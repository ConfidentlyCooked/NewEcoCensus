#include "imageview.h"
#include "ui_imageview.h"
#include <QDebug>

qreal ImageView::getUi_scrollrate() const
{
    return ui_scrollrate;
}

void ImageView::setWorking_dir(const QString &value)
{
    working_dir = value;
}

ImageView::ImageView(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::ImageView)
{
    ui->setupUi(this);
    setScene(&m_scene);
    m_item.setTransformationMode(Qt::SmoothTransformation);
    m_scene.addItem(&m_item);
    setDragMode(QGraphicsView::ScrollHandDrag);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
}

ImageView::~ImageView()
{
    delete ui;
}


void ImageView::slot_zin()
{
    factoredZoom(+getUi_scrollrate());
}

void ImageView::slot_zout()
{
    factoredZoom(-getUi_scrollrate());
}

void ImageView::slot_1x()
{
    resetMatrix();
    centerImage();
}

void ImageView::slot_fit()
{
    fitImage();
}

void ImageView::slot_cen()
{
    centerImage();
}

void ImageView::slot_ChangeItem(QListWidgetItem* newitem, QListWidgetItem *olditem)
{
    qDebug() << "changing item";
    QString newdir = newitem->data(Qt::UserRole).toString();
    if (DEBUG >= 2) qDebug() << "items:" << newitem << olditem;
    QString olddir = "";
    QString oldfile = "";
    if (olditem != NULL) {
        //qDebug() << "filename" << olditem->text();
        olddir = olditem->data(Qt::UserRole).toString();
        oldfile = olditem->text();
    }
    QString newfile = newitem->text();
    QString image = newdir + QDir::separator() + newfile;
    setPixmapAndSave(QPixmap::fromImage(QImage(image)), olddir, oldfile);
}

qreal ImageView::getImgRelScl() {
    // get dimensions
    qreal img_w = qreal(m_item.pixmap().width());
    qreal img_h = qreal(m_item.pixmap().height());
    qreal con_w = qreal(width());
    qreal con_h = qreal(height());
    // get aspect ratios
    qreal img_a = img_w / img_h;
    qreal con_a = con_w / con_h;
    qreal scl = 1.0;

    if (img_a > con_a) {
        // image aspect wider than container
        // scale by width
        scl = img_w / con_w;
    } else {
        // image aspect taller than container (or same)
        // scale by height
        scl = img_h / con_h;
    }
    return scl;
}

void ImageView::wrangleRect()
{
    auto pixmap = m_item.pixmap();
    auto rect = QRectF(pixmap.rect());
    // offset is -0.5{w, h}
    auto offset = -rect.center();
    m_item.setOffset(offset);

    qreal scl = panmax;

    setSceneRect(
                // xy
                offset.x() - (scl * rect.width()),
                offset.y() - (scl * rect.height()),
                // wh
                2 * (-offset.x() + (scl * rect.width())),
                2 * (-offset.y() + (scl * rect.height()))
                );
}

void ImageView::setPixmap(const QPixmap &pixmap)
{
    // space outside of the image to pan through
    // relative to image size
    // default of 0.5 means half the image worth of space on the outside
    m_item.setPixmap(pixmap);
    wrangleRect();
    translate(1, 1);
    resetMatrix();
    //scale(qreal(width()) / qreal(pixmap.width()));
    fitImage();
}

void ImageView::applyImageInfo(QString dir, QString filename) {

    QFileInfo dstfile;
    // @global 300 box size
    // index * 300

    /*
     * Folder Structure
     *
     *  /dir
     *      /Negative
     *      /feature1
     *      /feature2
     *      ...
     *
     * maybe want instead?:
     *
     *  /dir
     *      /Source
     *      /Features ?
     *          /Negative
     *          /Feature1
     *          /Feature2
     *          ...
     *
     * */

    // save image status file
    //
    // open file
    QDir newfile(dir);
    //newfile.cd();
    QFile outfile(newfile.absolutePath() + QDir::separator() + filename + ".txt");
    if (outfile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&outfile);
        // for all x columns
        for (int x = 0; x < boxlist.length(); x++) {
            // for all y rows
            for (int y = 0; y < boxlist.length(); y++) {
                // get the current filename
                QString cx = QString::number(x * 300);
                QString cy = QString::number(y * 300);
                QString curfile =
                        cx.rightJustified(4, '0') + "_" +
                        cy.rightJustified(4, '0') + "_" +
                        filename;
                // each file at a time
                // try to find which folder it's in
                if (DEBUG >= 5) qDebug() << "Looking for" << curfile;
                QDir search(dir);
                // @global what's the features folder called
                //search.cd("Features");
                if (DEBUG >= 5) qDebug() << search;
                // list of folders
                QStringList folders = search.entryList(
                            QStringList(),
                            QDir::Dirs | QDir::NoDotAndDotDot);
                // for every folder
                for (int i = 0; i < folders.length(); i++) {
//                    qDebug() << folders[i] << "looking for" << curfile;
                    // try to find the image
                    QDir cfold(search);
                    // go to the current folder
                    cfold.cd(folders[i]);
                    // get the file if it exists
                    QFileInfoList images = cfold.entryInfoList(
                                QStringList() << ("*" + curfile),
                                QDir::Files);
                    if (images.length() <= 0 || boxlist[x][y] == NULL) {
                        if (DEBUG >= 5) qDebug() << "not found or null";
                        // if it couldn't find the image
                        // or there's no new information to write
                        // go to next loop
                        continue;
                    } else {
                        auto file = images[0];
                        // get the source and destination
                        QString src = file.absoluteFilePath();
                        QDir dfold(search);
                        dfold.cd(boxlist[x][y]->name);
                        QString dst = dfold.absolutePath() + "/" + curfile;
                        dstfile = QFileInfo(dst);
                        dst = dstfile.absoluteFilePath();
                        if (DEBUG >= 6) qDebug() << cfold << dfold;
                        if (DEBUG >= 6) qDebug() << src << dst;
                        if (src != dst) {
                            // write to file
                            stream <<
                                      '"' << src << '"' << " " <<
                                      '"' << dst << '"' << " " <<
//                                      x << " " <<
//                                      y << " " <<
//                                      boxlist[x][y]->name <<
                                      endl;
                        }

                        //                    // move the file to its new location
                        //                    // get file
                        //                    QString img(search.absolutePath() + "/" + folders.at(i) + "/" + images.at(0));
                        //                    QString tgt(search.absolutePath() + "/" + boxlist[x][y]->name + "/" + images.at(0));
                        //                    // move file
                        //                    QFile::rename(img, tgt);
                        // end the folders loop
                        break;
                    }
                    // end find image
                }
                // end folders loop
            }
            // end y loop
        }
        // end x loop
    }
    // close file
    iterate_move_partitions(dstfile);
    outfile.close();

}

void ImageView::deleteRect(rectitem* item) {
    if (item == NULL) {
        // already null
    } else {
        m_scene.removeItem(item->rect);
        delete item->rect;
        item = NULL;
    }
}

void ImageView::delBox(QPoint index) {
    auto x = index.x();
    auto y = index.y();
    auto current = boxlist[x][y];
    // remove the old
    if (current == NULL) {
        //
    } else {
        deleteRect(boxlist[x][y]);
        boxlist[x][y] = NULL;
    }
}

void ImageView::setBox(QString name, QPoint index, QPen pen) {
    // delete the old box
    delBox(index);
    auto x = index.x();
    auto y = index.y();
    // make the new box
    boxlist[x][y] = new rectitem;
    auto current = boxlist[x][y];
    // give it information
    current->name = name;
    QPointF pos = indexToPos(index);
    // @global 300 box size
    BoxInfo bi;
    bi.x = pos.x();
    bi.y = pos.y();
    bi.w = 300;
    bi.h = 300;
    bi.pen = pen;
    // @global padding mode
    if (true) {
        bi = bi.penPad();
    }
    current->rect = m_scene.addRect(
                bi.x,
                bi.y,
                bi.w,
                bi.h,
                bi.pen);
    //m_scene.update();
}

void ImageView::removeBoxes() {
    for (int x = 0; x < boxlist.length(); x++) {
        for (int y = 0; y < boxlist[x].length(); y++) {
            deleteRect(boxlist[x][y]);
            boxlist[x][y] = NULL;
        }
        //        std::for_each(boxlist[x].begin(),
        //                      boxlist[x].end(),
        //                      [this](rectitem* item){
        //            deleteRect(item);
        //        });
    }
    //m_scene.update();
}

void ImageView::clearAndResize(const QPixmap &pixmap) {
    removeBoxes();
    // @global 300 box size
    boxlist.resize(ceil(qreal(pixmap.width()) / 300));
    for (int i = 0; i < boxlist.length(); i++) {
        boxlist[i].resize(ceil(qreal(pixmap.height()) / 300));
    }
}

void ImageView::setPixmapAndSave(const QPixmap &pixmap, QString dir, QString filename)
{
    qDebug() << "saving item";
    qDebug() << "file:" << filename;
    // apply changes
    if (!(filename.isEmpty()) && !(dir.isEmpty()) && (filename != "") && (dir != "")) {
        qDebug() << "saving" << filename;
        applyImageInfo(dir, filename);
    }
    // change image
    setPixmap(pixmap);
    // fix box count
    clearAndResize(pixmap);
    qDebug() << "GOT to clearAndResize()" << endl;
    // load the boxes
}

void ImageView::setPixmapAndResize(const QPixmap &pixmap) {
    setPixmap(pixmap);
    clearAndResize(pixmap);
}

void ImageView::scale(qreal s) {
    QGraphicsView::scale(s, s);
}

qreal ImageView::normalizescroll(int val) {
    qreal temp = val / scrollnorm;
    //qDebug() << temp;
    if (temp >= 0) {
        if (temp > scrollmax) temp = scrollmax;
    } else {
        if (-temp > scrollmax) temp = -scrollmax;
    }
    //qDebug() << temp;
    return temp;
}

void ImageView::factoredZoom(qreal fac) {
    if (fac > 0) {
        // zooming in
        scale(1.0 + (fac * zoomfactor));
    } else if (fac <= 0) {
        // zooming out

        // image scale relative to container
        qreal iscl = getImgRelScl();
        // current scale
        qreal cscl = matrix().m11();
        // scale attempt
        qreal temp = 1.0 / (1.0 - (fac * zoomfactor));
        // what the scalar will be after the transformation
        qreal next = (cscl * temp);
        if (iscl > 1) {
            // handle images larger than display
            // their minimum scale is display size * zoom min
            iscl = (1.0 / iscl) * zoommin;
        } else {
            // handle images smaller than display
            //     their minimum scale is their size * zoom min
            iscl = (zoommin);
        }
        // if the next value is under the minimum zoom distance
        // scale to the minimum
        if (next <= iscl) {
            scale(iscl / cscl);
            return;
        }
        // otherwise, scale normally
        scale(temp);
    }
}

void ImageView::wheelEvent(QWheelEvent *event) {
    // qDebug() << event;
    auto val = event->angleDelta().y();
    qreal scl = 1.0;
    if (magscalezoom) {
        scl = normalizescroll(val);
    }

    factoredZoom(scl);
}

void ImageView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    wrangleRect();
    factoredZoom(-0.0);
}

void ImageView::centerImage()
{
    centerOn(m_item.boundingRect().center());
}

//void centerBar(QScrollBar* bar) {
//    auto center = bar->maximum() - bar->minimum() + bar->pageStep();
//    bar->setValue(qreal(center) / 2.0);
//}

void ImageView::fitImage(bool allowUpscale)
{
    centerImage();
    resetMatrix();
    translate(1, 1);
    //centerOn(m_item.parentItem());

    qreal scl = (1.0 / getImgRelScl());

    if (!allowUpscale) {
        if (scl > 1.0) scl = 1.0;
    }

    scale(scl);
}

void ImageView::iterate_move_partitions(QString dir, QString filename)
{
    // get the text file name manually from the dir and filename
    QString the_text_file_path = dir + "/" + filename + ".txt";
    // CALL SHELL SCRIPT
}

void ImageView::iterate_move_partitions(QFileInfo txtfile)
{
    QString the_text_file_path = txtfile.absoluteFilePath();
    // CALL SHELL SCRIPT
}

void ImageView::loadCurrentBoxes(QListWidget* list, QString dir, QString filename)
{
    // for each folder in the list
    for (int i = 0; i < list->count(); i++) {
        // Widget Item
        QListWidgetItem* item = list->item(i);
        // Widget itself
        QWidget* widget = list->itemWidget(item);
        // Custom Class with needed information
        ColorTest* ct = (ColorTest*)widget;
        // get foldername and pen from widget
        QString foldername = ct->getLabelText();
        qDebug() << foldername << endl;
        QPen pen = ct->getPenValue();
        // find filename inside dir/foldername
        QDir search(dir);
        search.cd(foldername);
        QFileInfoList partitions = search.entryInfoList(QStringList() << "*" + filename, QDir::Files);
        // for each partition found inside the folder
        for (int j = 0; j < partitions.length(); j++) {
            QFileInfo cfile(partitions[j]);
            QString filename = cfile.fileName();
            QStringList parts = filename.split("_");
            if (DEBUG >= 2) qDebug() << parts;
            // @global partition size again
            int x = parts[0].toInt() / 300;
            int y = parts[1].toInt() / 300;
            // get the xy pos
            QPoint position;
            position.setX(x);
            position.setY(y);
            // set a box to it
            setBox(foldername, position, pen);
        }
        // each partition end
    }
    // each folder end
}

QPointF ImageView::uncenter(QPointF p) {
    qreal w = m_item.pixmap().width();
    qreal h = m_item.pixmap().height();
    return QPointF(
                p.x() + (w / 2),
                p.y() + (h / 2)
                );
}

QPointF ImageView::recenter(QPointF p) {
    qreal w = m_item.pixmap().width();
    qreal h = m_item.pixmap().height();
    return QPointF(
                p.x() - (w / 2),
                p.y() - (h / 2)
                );
}

QPoint ImageView::indexFromPos(QPointF p) {
    p = uncenter(p);
    return QPoint(
                floor(p.x()/ 300),
                floor(p.y() / 300)
                );
}

bool ImageView::posWithinImage(QPointF p)
{
    auto w = m_item.pixmap().width();
    auto h = m_item.pixmap().height();

    p = uncenter(p);

    if (    p.x() < 0 ||
            p.y() < 0 ||
            p.x() > w ||
            p.y() > h) {
        return false;
    } else {
        return true;
    }
}

QPointF ImageView::indexToPos(QPoint i) {
    QPointF result(
                i.x() * 300,
                i.y() * 300
                );
    return recenter(result);
}

void ImageView::mouseDoubleClickEvent(QMouseEvent *event)
{

    emit dubclick(event);
}




