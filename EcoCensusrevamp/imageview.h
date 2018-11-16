#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QListWidgetItem>
#include <QWheelEvent>
#include <QScrollBar>
#include <QDir>
#include "boxinfo.h"
#include "colortest.h"


struct rectitem {
    QString name;
    QGraphicsRectItem* rect;
};

namespace Ui {
class ImageView;
}

class ImageView : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene m_scene;
    QGraphicsPixmapItem m_item;
    QString working_dir;
    QVector<QVector<rectitem*>> boxlist;

    int DEBUG = 0;
    // 0: none
    // out of loops
    // 1: status messages
    // 2: constructed strings and variable values
    // inside loops
    // 3: status messages
    // 4: strings and var values
    // inner loops
    // 5: status
    // 6: values
    //qreal curScale = 1;
    // minimum zoom level
    const qreal zoommin = 0.9;
    // paximum pan-out-of-image ratio
    const qreal panmax = 0.0;
    // zooming rate
    const qreal zoomfactor = 0.1;
    // does zoom scale by wheel event magnitude?
    // this allows trackpads and tablets to have smooth scrolling
    const bool magscalezoom = true;
    // 120 seems to be the default wheelevent magnitude
    // when users use a mouse
    const qreal scrollnorm = 120;
    // trackpad and tablet scrolls can get magnitudes
    // past scrollnorm, this value decides at what point to
    // truncate the value
    const qreal scrollmax = scrollnorm * 2;
    // + and - button scalar for zoom
    const qreal ui_scrollrate = 5.0;

public:
    explicit ImageView(QWidget *parent = 0);
    ~ImageView();
    qreal getImgRelScl();
    void wrangleRect();
    void setPixmap(const QPixmap &pixmap);
    void scale(qreal s);
    qreal normalizescroll(int val);
    //QSize sizeHint();
    void factoredZoom(qreal fac);
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);
    void centerImage();
    void fitImage(bool allowUpscale = true);
    void iterate_move_partitions(QString dir, QString filename);
    void iterate_move_partitions(QFileInfo txtfile);
    void loadCurrentBoxes(QListWidget *list, QString dir, QString filename);

    qreal getUi_scrollrate() const;

    QPointF uncenter(QPointF p);
    QPointF recenter(QPointF p);
    QPointF indexToPos(QPoint i);
    QPoint indexFromPos(QPointF p);
    bool posWithinImage(QPointF p);
    void mouseDoubleClickEvent(QMouseEvent* event);

    void applyImageInfo(QString dir, QString filename);
    void setPixmapAndSave(const QPixmap &pixmap, QString dir, QString filename);
    void removeBoxes();
    void clearAndResize(const QPixmap &pixmap);
    void setBox(QString name, QPoint index, QPen pen);
    void setPixmapAndResize(const QPixmap &pixmap);
    void deleteRect(rectitem *item);
    void delBox(QPoint index);
    void setWorking_dir(const QString &value);

signals:
    void dubclick(QMouseEvent *event);
public slots:
    void slot_zin();
    void slot_zout();
    void slot_1x();
    void slot_fit();
    void slot_cen();
    void slot_ChangeItem(QListWidgetItem* newitem, QListWidgetItem* olditem);
private:
    Ui::ImageView *ui;
};

#endif // IMAGEVIEW_H
