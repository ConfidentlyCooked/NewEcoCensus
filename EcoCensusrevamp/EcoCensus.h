#ifndef ECOCENSUS_H
#define ECOCENSUS_H

#include <QMainWindow>
#include <QDir>
#include <QProcess>
#include <QImageReader>
#include <QListWidgetItem>
#include "confirmdialog.h"
#include "colortest.h"
#include "boxinfo.h"
#include <vector>
using std::vector;

namespace Ui {
class EcoCensus;
}

class EcoCensus : public QMainWindow
{
    Q_OBJECT

public:
    explicit EcoCensus(QWidget *parent = 0);
    ~EcoCensus();
    // ===== General Functions =====
    // dirs
    void getADir(QString prompt, QLineEdit *urlbar);
    // piclist
    void addPicListWidget(QListWidget *parent, QString label, QString filePath);
    // dirlist
    QString getALabel();
    QColor getAColor();
    void addColorListWidget(QListWidget *parent, QString label, QColor color);
    void addColorListWidget(QListWidget *parent, QString label, QString userData, QColor color);
    void closeEvent(QCloseEvent* event);

    // ===== Classify Functions =====
    // classify
    void populateList_Partitions(vector<BoxInfo> &list, QString fileName);
    // dirlist
    void fillDirList(QString);
    // image
    void imageUpdate(QListWidgetItem *item);

    // ===== Train Functions =====
    // train
    void train_LoadSession(QString dir);
    void train_SaveSessionFile(QString dir);

    // ===== Coord Functions =====
    // files
    void fillCoordList(QString);
    // text
    void updateCoordText();

private slots:
    // ===== Classify Slots =====
    // dirs
    void on_classify_root_btn_clicked();
    // classify
    void on_button_predict_clicked();
    // piclist
    void on_classify_pics_itemClicked(QListWidgetItem *current, QListWidgetItem *previous);

    void on_classify_pics_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    // dirlist
    void on_classify_opendir_clicked();
    void on_classify_refresh_clicked();
    // image
    void on_classify_image_dubclick(QMouseEvent *event);

    // ===== Train Slots =====
    // dirs
    void on_train_imgs_btn_clicked();
    // train
    void on_train_start_clicked();
    // image

    // ===== Coord Slots =====
    // files
    void on_coord_openfile_clicked();
    void on_coord_files_itemDoubleClicked(QListWidgetItem *item);
    void on_coord_delete_clicked();
    // garbage debug
    void on_coord_test_clicked();

    // ==map
    // ==drone

    // ===== Iterate Slots =====
    // dirs
    void on_iterate_pics_btn_clicked();
    // iterate
    void on_iterate_add_clicked();
    void on_iterate_merge_clicked();
    // piclist
    void on_iterate_pics_itemClicked(QListWidgetItem *item);
    void on_iterate_pics_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    // image
    void on_iterate_image_dubclick(QMouseEvent *);
    void on_EcoCensus_destroyed();
    void on_iterate_save_clicked();


private:
    Ui::EcoCensus *ui;
};

#endif // ECOCENSUS_H
