/*
EcoCensus.cpp
EcoCensus
Copyright 2017: Rebekah Loving and Morgan West
*/

#include "EcoCensus.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QDir>
#include <QImageReader>
#include <algorithm>
#include <QtMath>
#include <QSettings>
#include <QDesktopServices>
#include <QThread>
#include <QPainter>
#include <QtCore>
#include <QProcess>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <pstream.h>
#include <time.h>

std::string training_output;

int DEBUG = 0;
// @cleanup quick fix for header mismatch
bool MODE = true;

EcoCensus::EcoCensus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EcoCensus)
{
    ui->setupUi(this);
    //connect(ui->imageArea, ui->imageArea->mouseDoubleClickEvent, this, asd);
}

EcoCensus::~EcoCensus()
{
    delete ui;
}

void EcoCensus::closeEvent(QCloseEvent *event)
{
    bool ASKCLOSE = true;
    // @global ask user to quit
    // if the user says yes to closing then we close
    if (ASKCLOSE) {
        ConfirmDialog cdial(this, "Are you sure you want to quit? (progress will be saved)", "Confirmation.");
        cdial.setModal(true);
        auto result = cdial.exec();
        if (result) {
            // do nothing
        } else {
            // if they dont say yes, stay in and skip the rest
            event->ignore();
            return;
        }
    }
    // anyways, if we get here, save and quit
    {
        // save
        auto list = ui->iterate_pics->selectedItems();
        if (list.length() > 0) {
            ui->iterate_image->applyImageInfo(
                        list[0]->data(Qt::UserRole).toString(),
                    list[0]->text());
        }
        event->accept();
    }
    return;
}

/* ========== General Functions ==========
 *
 * */

// ===== dirs =====
void EcoCensus::getADir(QString prompt, QLineEdit* urlbar) {
    // @global file dialog start folder
    qDebug() << "get a dir";
    QString startdir = "./";
    //QFileDialog* asdf = new QFileDialog(this, prompt, startdir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QString temp = QFileDialog::getExistingDirectory(this, prompt, startdir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    urlbar->setText(temp);
}

// ===== piclist =====
void EcoCensus::addPicListWidget(QListWidget* parent, QString label, QString filePath)
{
    static int thumbsize = 100;
    // load an image
    QImageReader cimg(filePath + QDir::separator() + label);
    if (!cimg.canRead()) {
        ConfirmDialog error(this, "No Image!!", "Error");
        error.setModal(true);
        error.exec();
    } else {
        // fix size
        int newwd = thumbsize;
        int newht = thumbsize;
        double scalar = 1.0;
        QSize cimgsize = cimg.size();
        if (cimgsize.width() >= cimgsize.height()) {
            // Width Bigger or equal
            if (cimgsize.width() > thumbsize) {
                scalar = double(thumbsize) / double(cimgsize.width());
                newht = int(round(scalar * cimgsize.height()));
            }
        } else {
            // Height Bigger
            if (cimgsize.height() > thumbsize) {
                scalar = double(thumbsize) / double(cimgsize.height());
                newwd = int(round(scalar * cimgsize.width()));
            }
        }
        cimg.setScaledSize(QSize(newwd, newht));
        // end fix size
        QImage cimgdata = cimg.read();
        QListWidgetItem* imgitem = new QListWidgetItem(label, parent);
        imgitem->setData(Qt::DecorationRole, cimgdata);
        imgitem->setData(Qt::UserRole, filePath);
    }
}

// ===== dirlist =====
QString EcoCensus::getALabel()
{
    static int num = 0;
    return QStringLiteral("Label%1").arg(num++);
}

QColor EcoCensus::getAColor()
{
    static int h = 0;
    static int s = 255;
    static int v = 255;
    static int a = 255;
    QColor result;
    result.setHsv(h, s, v, a);
    h += 53;
    h = h % 360;
    return result;
}

void EcoCensus::addColorListWidget(QListWidget* parent, QString label, QColor color)
{
    QListWidgetItem* lwi = new QListWidgetItem(parent);
    ColorTest* ct = new ColorTest(NULL, label, color);
    lwi->setSizeHint(ct->sizeHint());
    parent->setItemWidget(lwi, ct);
    ct->updateColor();
}

void EcoCensus::addColorListWidget(QListWidget* parent, QString label, QString userdata, QColor color)
{
    QListWidgetItem* lwi = new QListWidgetItem(parent);
    ColorTest* ct = new ColorTest(NULL, label, color);
    lwi->setData(Qt::UserRole, userdata);
    lwi->setSizeHint(ct->sizeHint());
    parent->setItemWidget(lwi, ct);
    ct->updateColor();
}

/* ========== Classify Functions ==========
 *
 * */

// ===== classify =====
void EcoCensus::populateList_Partitions(vector<BoxInfo> &list, QString fileName) {
    // get a copy of "this" for the lambda function to use
    auto* capthis = this;

    // loop the children of our QListWidget
    for (int i = 0; i < ui->dirList->count(); i++) {
        // get the current item in various forms in case we need them
        // Widget Item
        QListWidgetItem* item = ui->dirList->item(i);
        // Widget itself
        QWidget* widget = ui->dirList->itemWidget(item);
        // Custom Class with needed information
        ColorTest* ct = (ColorTest*)widget;

        // get the current directory
        QString dirPath = item->data(Qt::UserRole).toString();
        QDir curDir(dirPath);
        // get the list of files inside
        QStringList filters;
        filters << QString("*" + fileName);
        QStringList images = curDir.entryList(filters, QDir::Files);
        std::for_each(
                    images.begin(),
                    images.end(),
                    [capthis, &list, &ct, dirPath](QString file){
            // blank result
            BoxInfo info;
            // color
            info.pen = ct->getPenValue();
            // xy
            QStringList pieces = file.split('_');
            // if there's junk at the start of the filename in the future
            // we need to use this to fix it
            int offset = 0;

            info.x = pieces.at(0 + offset).toInt();
            info.y = pieces.at(1 + offset).toInt();
            // wh
            // GETTING THE WIDTH AND HEIGHT FROM IMAGE DATA
            // until we get the jpg headers fixed in the partitioning, the
            // automatic size getting won't work
            QString curFile = dirPath + "/" + file;
            if (DEBUG >= 4) qDebug() << curFile;
            QImageReader curImg(curFile);
            QSize sz = curImg.size();
            if (DEBUG >= 4) qDebug() << "size: " << sz;
            // remove divide by 10 when the headers work properly
            info.w = sz.width();
            info.h = sz.height();

            // WH FROM DATA END

            // push the result to the list
            list.push_back(info);
        });
    }
}

// ===== dirlist =====
void EcoCensus::fillDirList(QString dest)
{
    auto* capthis = this;
    // collect folder names in a list
    QString resultDir = dest;// + d2;
    QDir dir(resultDir);
    QStringList results = dir.entryList(QStringList(), QDir::Dirs | QDir::NoDotAndDotDot);
    if (DEBUG >= 3) qDebug() << results;

    // create all of the result folder widgets
    // clear previous
    ui->dirList->clear();
    std::for_each(
                results.begin(),
                results.end(),
                [&dir, this](QString item){
        // item is the folder name, stored in the Label
        // store the full folder path in the UserRole data
        if (item == "Partitions") {
            // do nothing
        } else if (item == "Negative") {
            addColorListWidget(ui->dirList, item, dir.path() + "/" + item, Qt::transparent);
        } else {
            addColorListWidget(ui->dirList, item, dir.path() + "/" + item, getAColor());
        }
    });
}

// ===== image =====
void EcoCensus::imageUpdate(QListWidgetItem *item) {
    // get full file path and information
    QString filepath = item->data(Qt::UserRole).toString();

    // create our copy of the image in memory
    QImage imgdata(filepath);
    // attack a painter to the image data
    QPainter painter(&imgdata);

    // need to populate a list of the areas to draw shapes around
    // need the colors to draw each type
    vector<BoxInfo> boxes;
    // GET ALL THE BOX INFO
    populateList_Partitions(boxes, item->text());

    // DRAW ALL THE BOXES start
    std::for_each(
                boxes.begin(),
                boxes.end(),
                [&painter](BoxInfo citem){
        auto item = citem;
        // if pen padding is turned on
        if (MODE) item = citem.penPad();
        // debug msgs
        if (DEBUG >= 4) qDebug() << item.pen;
        if (DEBUG >= 4) qDebug() <<
                                    item.x << ", " <<
                                    item.y << ", " <<
                                    item.w << ", " <<
                                    item.h << ", " <<
                                    "";
        // set the pen
        painter.setPen(item.pen);
        // draw the rect
        painter.drawRect(item.x, item.y, item.w, item.h);
    });
    // DRAW ALL THE BOXES end
    // update the label with our painted image
    ui->classify_image->setPixmapAndResize(QPixmap::fromImage(imgdata));
}
/* ========== Train Functions ==========
 *
 * */

/* ========== Coord Functions ==========
 *
 * */

// ===== files =====
void EcoCensus::fillCoordList(QString dest)
{
    auto* capthis = this;
    // collect folder names in a list
    QString resultDir = dest;// + d2;
    QDir dir(resultDir);
    QStringList filters;
    filters << "*coords.txt";
    QStringList results = dir.entryList(filters, QDir::Files);
    if (DEBUG >= 3) qDebug() << results;

    // create all of the result folder widgets
    // clear previous
    ui->coord_files->clear();
    std::for_each(
                results.begin(),
                results.end(),
                [&dir, capthis](QString item){
        QFile f(item);
        // item is the folder name, stored in the Label
        // store the full folder path in the UserRole data
        QListWidgetItem* lwi = new QListWidgetItem(f.fileName(), capthis->ui->coord_files);
        lwi->setData(Qt::UserRole, dir.path() + "/" + item);
        //        lwi->setText(f.fileName());
    });
}

// ===== text =====
void EcoCensus::updateCoordText() {
    auto list = ui->coord_files->selectedItems();
    if (list.length() == 0) {
        // error no file selected
    } else {
        QListWidgetItem* item = list[0];
        //QFile f(item->data(Qt::UserRole));
        //        if (!f.open(QFile::ReadOnly | QFile::Text)) {
        //            // error file problem
        //        }
        //        QTextStream in(&f);
        QUrl url(item->data(Qt::UserRole).toString());
        url.setScheme("file");
        ui->coord_text->setSource(url);
    }
}

/* ========== Functions End ==========
 *
 * */





/* ========== Classify Slots ==========
 *
 * */

// ===== dirs =====
void EcoCensus::on_classify_root_btn_clicked()
{
    qDebug() << "open";
    getADir(tr("Choose root directory with Images."), ui->classify_root_url);
}

// ===== classify =====
void EcoCensus::on_button_predict_clicked()
{
    // get a copy of "this" for the lambda functions to use
    auto* capthis = (this);
    // ROOT/Partitions
    // DEST/Predictions/RESULT
    // QByteArray array = str.toLocal8Bit();

    QString d1 = "/Partitions";
    QString d2 = "/Predictions";

    // Root URL
    QString root = ui->classify_root_url->text();
    // Destination URL
    QString dest = ui->classify_root_url->text();
    // is empty
    if (dest.isEmpty()) {
        dest = root;
    }
    // STILL empty even thought it was set to root dir
    if (dest.isEmpty()) {
        // @fix error here that dir was never chosen
    }

    QDir rDir(root);
    QDir dDir(dest);
    // Predict on the directories
      QString EcoCensusDir = "cd " +QCoreApplication::applicationDirPath() + "/dist";
      QString swd = EcoCensusDir;
      //QString PythonLocation = "/Users/bound_to_love/tensorflow/bin/python ";
      QString params1 = EcoCensusDir;
      QString params2 = EcoCensusDir;
      QString params3 = EcoCensusDir;
      QString params4 = "rmdir ";
      QString heightval = EcoCensusDir;
      heightval = ui->faltitude_input->text();
      double FOV = 94.0;
      double HEIGHT = 60.0;
      params1 += "/image_partition; ./image_partition ";
      params1 += root + " " + QString::number(FOV) + " " + ui->faltitude_input->text();
      params1 = "cd; " + params1;
      params2 += "/predictions; export PBR_VERSION='3.0.0'; ./predictions ";
      params2 += dest + " " + ui->predict_threshold->text();
      params2 = "cd; " + params2;
      params3 += "/imageReader; ./imageReader ";
      params3 += dest + " " + QString::number(FOV) + " " + ui->faltitude_input->text();
      params3 = "cd; " + params3;
      qDebug() << "This is params3 ===   " << params3 << endl;
      params4 += dest;
      params4 += "/Partitions";
      system(qPrintable(swd));
      system(qPrintable(params1));
      system(qPrintable(params2));
      system(qPrintable(params3));
      system(qPrintable(params4));


    fillDirList(dest);
    fillCoordList(dest);

    // populate the picture list
    QDir mydir(root);
    if (mydir.exists()) {
        QStringList filters;
        filters << "*.jpg";
        QStringList files = mydir.entryList(filters, QDir::Files, QDir::Name | QDir::IgnoreCase);
        ui->classify_pics->clear();
        std::for_each(
                    files.begin(),
                    files.end(),
                    [&root, capthis, d1, d2, this](QString i) {
            // i is the file name, stored in the label
            // store the full filepath in the UserRole data
            addPicListWidget(ui->classify_pics, i, root);
        });

    } else {
        ConfirmDialog error(this, "No File", "Error");
        error.setModal(true);
        error.exec();
    }
}

// ===== piclist =====
void EcoCensus::on_classify_pics_itemClicked(QListWidgetItem *current, QListWidgetItem *previous)
{
    qDebug() << "Is this even called :on_iterate_pics_itemClicked" << endl;
}

void EcoCensus::on_classify_pics_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    qDebug() << "Is this even called :on_iterate_pics_currentItemChanged" << endl;
    ui->classify_image->slot_ChangeItem(current, previous);
    qDebug() << ui->dirList->item(0) << endl;
    ui->classify_image->loadCurrentBoxes(ui->dirList, current->data(Qt::UserRole).toString(), current->text());
}

// ===== dirlist =====
void EcoCensus::on_classify_opendir_clicked()
{
    QListWidgetItem* citem = ui->dirList->currentItem();
    if (citem != NULL) {
        if (DEBUG >= 2) qDebug() << citem->data(Qt::UserRole).toString();
        QDesktopServices::openUrl(QUrl(citem->data(Qt::UserRole).toString(), QUrl::TolerantMode));
    }
}

void EcoCensus::on_classify_refresh_clicked()
{
    // Root URL to char*
    QString root = ui->classify_root_url->text();
    // Destination URL to char*
    QString dest = ui->classify_root_url->text();
    // is empty
    if (dest.isEmpty()) {
        dest = root;
    }
    // STILL empty even though set to root
    if (dest.isEmpty()) {
        // error here saying that dir was not chosen
    } else {
        fillDirList(dest);
    }
    //addColorListWidget(getALabel(), "C:/", getAColor());
}

// ===== image =====
void EcoCensus::on_classify_image_dubclick(QMouseEvent *event)
{

}

/* ========== Train Slots ==========
 *
 * */

// ===== dirs =====
void EcoCensus::on_train_imgs_btn_clicked()
{
    getADir(tr("Choose a directory of training data"), ui->train_imgs_url);
}

// ===== train with output in window =====
void EcoCensus::on_train_start_clicked()
{
    QString traindir = ui->train_imgs_url->text();
    if (traindir.isEmpty()) {
        ConfirmDialog cdial(this, "A training directory must be chosen.", "Error.");
        cdial.setModal(true);
        auto result = cdial.exec();
        return;
    }else{
          QString EcoCensusDir = "cd " +QCoreApplication::applicationDirPath() + "/dist";
          QString params1 = EcoCensusDir;
          params1 += "/train; ./train ";
          params1 += traindir + " " + QCoreApplication::applicationDirPath() + "/dist/train ";
          //system(qPrintable(params1));
          qDebug() << "Setup to start train." << endl;
          QFile file(QCoreApplication::applicationDirPath() + "/training.txt");
          if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

          QTextStream out(&file);
          // run a process and create a streambuf that reads its stdout and stderr
           const redi::pstreams::pmode mode = redi::pstreams::pstdout|redi::pstreams::pstderr;
           redi::ipstream child(params1.toStdString(), mode);
           char buf[1024];
           std::streamsize n;
           bool finished[2] = { false, false };
           while (!finished[0] || !finished[1])
           {
               if (!finished[0])
               {
                   while ((n = child.err().readsome(buf, sizeof(buf))) > 0){
                       qDebug() << "std error " << QString::fromStdString(buf) << endl;
                   }
                   if (child.eof())
                   {
                       finished[0] = true;
                       if (!finished[1])
                           child.clear();
                   }
               }

               if (!finished[1])
               {
                   while ((n = child.out().readsome(buf, sizeof(buf))) > 0){
                       qDebug() << "std output " << QString::fromStdString(buf) << endl;
                       out << QString(buf);
                       QUrl url(QCoreApplication::applicationDirPath() + "/training.txt");
                       url.setScheme("file");
                       ui->train_output->setSource(url);
                   }
                   if (child.eof())
                   {
                       finished[1] = true;
                       if (!finished[0])
                           child.clear();
                   }
               }
           }
    }
}


// ===== image =====
// move function here

/* ========== Coord Slots ==========
 *
 * */

// ===== files =====
void EcoCensus::on_coord_openfile_clicked()
{
    updateCoordText();
}

void EcoCensus::on_coord_files_itemDoubleClicked(QListWidgetItem *item)
{
    QUrl url(item->data(Qt::UserRole).toString());
    url.setScheme("file");
    ui->coord_text->setSource(url);
}

void EcoCensus::on_coord_delete_clicked()
{
    auto* capthis = this;
    auto list = ui->coord_files->selectedItems();
    if (list.length() == 0) {
        return;
    }
    ConfirmDialog cdial(this, "Are you sure you want to delete this file?", "Confirmation");
    cdial.setModal(true);
    auto result = cdial.exec();
    if (result) {
        std::for_each(list.begin(), list.end(), [&capthis](QListWidgetItem* i){
            QFile file(i->data(Qt::UserRole).toString());
            // maybe check if have permissions?
            bool success = file.remove();
            if (success) {
                delete capthis->ui->coord_files->takeItem(capthis->ui->coord_files->row(i));
            }
        });
    } else {
        // do nothing
    }
}

// ===== debug =====
void EcoCensus::on_coord_test_clicked()
{
    auto list = ui->coord_files->selectedItems();
    if (list.length() == 0) {
        qDebug() << "no list";
        return;
    }

    QDir file(list[0]->data(Qt::UserRole).toString());
    qDebug() << file;
    QString name(list[0]->text());
    QDir tgt(file.absolutePath());
    tgt.cd("Coord");
    if (!tgt.exists()) {
        if (tgt.mkpath(".")){
            // made succ
        } else {
            // not made
            qDebug() << "not made";
        }
    }
    QString r(file.absolutePath() + "/" + name);
    QString d(tgt.absolutePath() + "/" + name);

    QFile::rename(r, d);
}

/* ========== Iterate Slots ==========
 *
 * */

// ===== dirs =====
void EcoCensus::on_iterate_pics_btn_clicked()
{
    getADir(tr("Choose your source image directory"), ui->iterate_pics_url);
}

// ===== iterate =====
void EcoCensus::on_iterate_add_clicked()
{
    // make sure a root directory is chosen
    QString root = ui->iterate_pics_url->text();
    if (root.isEmpty()) {
        ConfirmDialog cdial(this, "A root directory must be chosen.", "Error.");
        cdial.setModal(true);
        auto result = cdial.exec();
        return;
    }
    ui->iterate_image->setWorking_dir(root);
    ui->iterate_dirs->clear();
    QDir fdir(root);
    // @cleanup change this from hard coded to the opposite of that
    // @global what's the features dir
    //fdir.cd("Features");
    fdir.cd("Negative");
    addColorListWidget(ui->iterate_dirs, "Negative", fdir.absolutePath(), Qt::transparent);
    fdir.cd("..");
    fdir.cd("Miconia");
    addColorListWidget(ui->iterate_dirs, "Miconia", fdir.absolutePath(), getAColor());

    // partition input images

    // send them to the magic predict script

    //then do the thing

    // get all of the full images
    ui->iterate_pics->clear();
    QDir folder(root);
    QFileInfoList files(folder.entryInfoList(QStringList() << "*.jpg", QDir::Files, QDir::Name));
    for (int i = 0; i < files.length(); i++) {
        // one image at a time
        qDebug() << files[i].absoluteFilePath();
        addPicListWidget(ui->iterate_pics, files.at(i).fileName(), files.at(i).absolutePath());
    }

}

void EcoCensus::on_iterate_merge_clicked()
{
    ConfirmDialog cdial(this, "Are you sure you want to merge changes? (Cannot be easily undone!)", "Confirmation.");
    cdial.setModal(true);
    auto result = cdial.exec();

    qDebug() << result;
}


// ===== piclist =====
void EcoCensus::on_iterate_pics_itemClicked(QListWidgetItem *item)
{
    qDebug() << "Is this even called " << endl;
    //    QString dir = item->data(Qt::UserRole).toString();
    //    QString file = item->text();
    //    QString image = dir + QDir::separator() + file;
    //    ui->iterate_image->setPixmapAndSave(QPixmap::fromImage(QImage(image)), dir, file);
}

void EcoCensus::on_iterate_pics_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    qDebug() << "Is this even called :on_iterate_pics_currentItemChanged" << endl;
    ui->iterate_image->slot_ChangeItem(current, previous);
    ui->iterate_image->loadCurrentBoxes(ui->iterate_dirs, current->data(Qt::UserRole).toString(), current->text());
}

// ===== image =====
void EcoCensus::on_iterate_image_dubclick(QMouseEvent *event)
{
    auto a = ui->iterate_image;
    if (DEBUG >= 5) qDebug() << event;
    QPointF p = a->mapToScene(event->pos());
    if (DEBUG >= 5) qDebug() << p;

    if (a->posWithinImage(p)) {
        QPoint index = ui->iterate_image->indexFromPos(p);
        qDebug() << "index:" << index;
        auto citems = ui->iterate_dirs->selectedItems();
        if (citems.length() == 0) {
            ui->iterate_image->delBox(index);
        } else {
            // Widget Item
            QListWidgetItem* item = citems[0];
            // Widget itself
            QWidget* widget = ui->iterate_dirs->itemWidget(item);
            qDebug() << ui->iterate_dirs->itemWidget(item)->accessibleName() << endl;
            // Custom Class with needed information
            ColorTest* ct = (ColorTest*)widget;
            ui->iterate_image->setBox(ct->getLabelText(), index, ct->getPenValue());
            qDebug() << ct->getLabelText();
            qDebug() << ui->iterate_pics->selectedItems()[0]->data(Qt::UserRole).toString() << endl;
            qDebug() << ui->iterate_pics->selectedItems()[0]->text() << endl;
            QFileInfo dstfile;
            // save image status file
            //
            // open file
            QDir newfile(ui->iterate_pics->selectedItems()[0]->data(Qt::UserRole).toString());
            QFile outfile(newfile.absolutePath() + QDir::separator() + ui->iterate_pics->selectedItems()[0]->text() + ".txt");
            if (outfile.open(QIODevice::ReadWrite)) {
                QTextStream stream(&outfile);
                    // get the current filename
                    QString cx = QString::number(index.x()*300);
                    QString cy = QString::number(index.y()*300);
                    QString curfile =
                            cx.rightJustified(4, '0') + "_" +
                            cy.rightJustified(4, '0') + "_" +
                              ui->iterate_pics->selectedItems()[0]->text();
                    // try to find which folder it's in
                    QDir search(ui->iterate_pics->selectedItems()[0]->data(Qt::UserRole).toString());
                    // @global what's the features folder called
                    //search.cd("Features");
                    if (DEBUG >= 5) qDebug() << search;
                        // list of folders
                        QStringList folders = search.entryList(
                                QStringList(),
                                QDir::Dirs | QDir::NoDotAndDotDot);
                        // for every folder
                    for (int i = 0; i < folders.length(); i++) {
                        qDebug() << folders[i] << "looking for" << curfile;
                        // try to find the image
                        QDir cfold(search);
                        // go to the current folder
                        cfold.cd(folders[i]);
                        // get the file if it exists
                        QFileInfoList images = cfold.entryInfoList(
                                    QStringList() << ("*" + curfile),
                                    QDir::Files);
                        if(images.length() > 0){
                            auto file = images[0];
                            qDebug() << file << endl;
                            // get the source and destination
                            QString src = file.absoluteFilePath();
                            QDir dfold(search);
                            QString dst = dfold.absolutePath() + "/" + ct->getLabelText() + "/" + curfile;
                            if (DEBUG >= 6) qDebug() << cfold << dfold;
                            qDebug() << src << dst;
                            if (src != dst) {
                                // write to file
                                stream << '"' << src << '"' << " " <<
                                          '"' << dst << '"' << " " << endl;

                            //Windows
                            //system("MOV "+ src + " " + dst);
                            //MacOS
                            system(qPrintable("mv " + src + " " + dst));
                            break;
                        }
                    }
                }
            }
            // close file
            outfile.close();
        }

    } else {
        qDebug() << "index:" << "Outside image bounds";
    }
}

void EcoCensus::on_EcoCensus_destroyed()
{

}

void EcoCensus::on_iterate_save_clicked()
{
    qDebug() << "on_iterate_save_clicked()" << endl;
    auto list = ui->iterate_pics->selectedItems();
    if (list.length() > 0) {
        ui->iterate_image->applyImageInfo(
                    list[0]->data(Qt::UserRole).toString(),
                list[0]->text());
    }
}




