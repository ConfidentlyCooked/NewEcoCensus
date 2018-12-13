/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imageview.h"

QT_BEGIN_NAMESPACE

class Ui_EcoCensus
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QTabWidget *tabWidget;
    QWidget *Train;
    QGridLayout *gridLayout_9;
    QSplitter *splitter_Full_2;
    QFrame *frame_Dirs_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *train_imgs_btn;
    QLineEdit *train_imgs_url;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *train_start;
    QSpacerItem *horizontalSpacer_12;
    QSplitter *splitter_Bottom_2;
    QFrame *frame_Lists_2;
    QGridLayout *gridLayout_11;
    QSplitter *splitter_3;
    QListWidget *train_pics;
    QFrame *frame_train_dirs;
    QGridLayout *gridLayout_10;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *train_dir_add_3;
    QPushButton *train_dir_add_4;
    QPushButton *train_dir_add;
    QListWidget *train_dirs;
    QFrame *frame_Image_2;
    QGridLayout *gridLayout_8;
    QTextBrowser *train_output;
    QWidget *tab;
    QGridLayout *gridLayout_15;
    QSplitter *iterate_splitter_full;
    QFrame *frame_Dirs_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *iterate_pics_btn;
    QLineEdit *iterate_pics_url;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *iterate_add;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *iterate_merge;
    QSpacerItem *horizontalSpacer_20;
    QSplitter *splitter_Bottom_3;
    QFrame *frame_iterate_lists;
    QGridLayout *gridLayout_13;
    QSplitter *splitter_5;
    QListWidget *iterate_pics;
    QFrame *frame_iterate_dirs;
    QGridLayout *gridLayout_12;
    QListWidget *iterate_dirs;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_9;
    QPushButton *iterate_dirs_add;
    QPushButton *iterate_dirs_rem;
    QPushButton *iterate_dirs_edit;
    QFrame *frame_5;
    QGridLayout *gridLayout_16;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *iterate_save;
    QFrame *frame_iterate_image;
    QGridLayout *gridLayout_14;
    ImageView *iterate_image;
    QFrame *iterate_image_toolbar;
    QVBoxLayout *verticalLayout_10;
    QPushButton *iterate_zin;
    QPushButton *iterate_fit;
    QPushButton *iterate_cen;
    QPushButton *iterate_1x;
    QPushButton *iterate_zout;
    QWidget *Classify;
    QGridLayout *gridLayout_6;
    QSplitter *splitter_Full;
    QFrame *frame_Dirs;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *classify_root_btn;
    QLineEdit *classify_root_url;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QLineEdit *predict_threshold;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *faltitude_input;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *button_predict;
    QSpacerItem *horizontalSpacer_3;
    QSplitter *splitter_Bottom;
    QFrame *frame_Lists;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QListWidget *classify_pics;
    QListWidget *dirList;
    QFrame *frame_ListButtons;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *classify_refresh;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_Image;
    QGridLayout *gridLayout_2;
    ImageView *classify_image;
    QFrame *frame_Buttons;
    QVBoxLayout *verticalLayout_5;
    QPushButton *button_zin;
    QPushButton *button_fit;
    QPushButton *button_cen;
    QPushButton *button_1x;
    QPushButton *button_zout;
    QWidget *Coordinates;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QListWidget *coord_files;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *coord_openfile;
    QPushButton *coord_delete;
    QSpacerItem *horizontalSpacer_4;
    QTextBrowser *coord_text;
    QWidget *Maps;
    QWidget *Drones;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_2;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QTextEdit *textEdit;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QTextEdit *textEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EcoCensus)
    {
        if (EcoCensus->objectName().isEmpty())
            EcoCensus->setObjectName(QStringLiteral("EcoCensus"));
        EcoCensus->resize(957, 717);
        centralWidget = new QWidget(EcoCensus);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, -1, -1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabShape(QTabWidget::Rounded);
        Train = new QWidget();
        Train->setObjectName(QStringLiteral("Train"));
        gridLayout_9 = new QGridLayout(Train);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        splitter_Full_2 = new QSplitter(Train);
        splitter_Full_2->setObjectName(QStringLiteral("splitter_Full_2"));
        splitter_Full_2->setOrientation(Qt::Vertical);
        frame_Dirs_2 = new QFrame(splitter_Full_2);
        frame_Dirs_2->setObjectName(QStringLiteral("frame_Dirs_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_Dirs_2->sizePolicy().hasHeightForWidth());
        frame_Dirs_2->setSizePolicy(sizePolicy);
        frame_Dirs_2->setFrameShape(QFrame::StyledPanel);
        frame_Dirs_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_Dirs_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        train_imgs_btn = new QPushButton(frame_Dirs_2);
        train_imgs_btn->setObjectName(QStringLiteral("train_imgs_btn"));
        train_imgs_btn->setFlat(true);

        horizontalLayout_10->addWidget(train_imgs_btn);

        train_imgs_url = new QLineEdit(frame_Dirs_2);
        train_imgs_url->setObjectName(QStringLiteral("train_imgs_url"));

        horizontalLayout_10->addWidget(train_imgs_url);

        horizontalSpacer_10 = new QSpacerItem(42, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_11 = new QSpacerItem(7, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        train_start = new QPushButton(frame_Dirs_2);
        train_start->setObjectName(QStringLiteral("train_start"));
        train_start->setFlat(true);

        horizontalLayout_8->addWidget(train_start);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_8);

        splitter_Full_2->addWidget(frame_Dirs_2);
        splitter_Bottom_2 = new QSplitter(splitter_Full_2);
        splitter_Bottom_2->setObjectName(QStringLiteral("splitter_Bottom_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter_Bottom_2->sizePolicy().hasHeightForWidth());
        splitter_Bottom_2->setSizePolicy(sizePolicy1);
        splitter_Bottom_2->setOrientation(Qt::Horizontal);
        frame_Lists_2 = new QFrame(splitter_Bottom_2);
        frame_Lists_2->setObjectName(QStringLiteral("frame_Lists_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_Lists_2->sizePolicy().hasHeightForWidth());
        frame_Lists_2->setSizePolicy(sizePolicy2);
        frame_Lists_2->setMinimumSize(QSize(0, 0));
        frame_Lists_2->setFrameShape(QFrame::StyledPanel);
        frame_Lists_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_Lists_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(frame_Lists_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        train_pics = new QListWidget(splitter_3);
        train_pics->setObjectName(QStringLiteral("train_pics"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(train_pics->sizePolicy().hasHeightForWidth());
        train_pics->setSizePolicy(sizePolicy3);
        splitter_3->addWidget(train_pics);
        frame_train_dirs = new QFrame(splitter_3);
        frame_train_dirs->setObjectName(QStringLiteral("frame_train_dirs"));
        frame_train_dirs->setFrameShape(QFrame::StyledPanel);
        frame_train_dirs->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_train_dirs);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setVerticalSpacing(0);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frame_train_dirs);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 7, 0);
        train_dir_add_3 = new QPushButton(frame_3);
        train_dir_add_3->setObjectName(QStringLiteral("train_dir_add_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(train_dir_add_3->sizePolicy().hasHeightForWidth());
        train_dir_add_3->setSizePolicy(sizePolicy4);
        train_dir_add_3->setMinimumSize(QSize(28, 28));
        train_dir_add_3->setMaximumSize(QSize(28, 28));
        train_dir_add_3->setBaseSize(QSize(28, 28));

        verticalLayout_6->addWidget(train_dir_add_3);

        train_dir_add_4 = new QPushButton(frame_3);
        train_dir_add_4->setObjectName(QStringLiteral("train_dir_add_4"));
        sizePolicy4.setHeightForWidth(train_dir_add_4->sizePolicy().hasHeightForWidth());
        train_dir_add_4->setSizePolicy(sizePolicy4);
        train_dir_add_4->setMinimumSize(QSize(28, 28));
        train_dir_add_4->setMaximumSize(QSize(28, 28));
        train_dir_add_4->setBaseSize(QSize(28, 28));

        verticalLayout_6->addWidget(train_dir_add_4);

        train_dir_add = new QPushButton(frame_3);
        train_dir_add->setObjectName(QStringLiteral("train_dir_add"));
        sizePolicy4.setHeightForWidth(train_dir_add->sizePolicy().hasHeightForWidth());
        train_dir_add->setSizePolicy(sizePolicy4);
        train_dir_add->setMinimumSize(QSize(28, 28));
        train_dir_add->setMaximumSize(QSize(28, 28));
        train_dir_add->setBaseSize(QSize(28, 28));

        verticalLayout_6->addWidget(train_dir_add);


        gridLayout_10->addWidget(frame_3, 0, 1, 1, 1);

        train_dirs = new QListWidget(frame_train_dirs);
        train_dirs->setObjectName(QStringLiteral("train_dirs"));
        sizePolicy3.setHeightForWidth(train_dirs->sizePolicy().hasHeightForWidth());
        train_dirs->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(train_dirs, 0, 0, 1, 1);

        splitter_3->addWidget(frame_train_dirs);

        gridLayout_11->addWidget(splitter_3, 0, 0, 1, 1);

        splitter_Bottom_2->addWidget(frame_Lists_2);
        frame_Image_2 = new QFrame(splitter_Bottom_2);
        frame_Image_2->setObjectName(QStringLiteral("frame_Image_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(3);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frame_Image_2->sizePolicy().hasHeightForWidth());
        frame_Image_2->setSizePolicy(sizePolicy5);
        frame_Image_2->setMinimumSize(QSize(0, 0));
        frame_Image_2->setFrameShape(QFrame::StyledPanel);
        frame_Image_2->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_Image_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        train_output = new QTextBrowser(frame_Image_2);
        train_output->setObjectName(QStringLiteral("train_output"));

        gridLayout_8->addWidget(train_output, 0, 0, 1, 1);

        splitter_Bottom_2->addWidget(frame_Image_2);
        splitter_Full_2->addWidget(splitter_Bottom_2);

        gridLayout_9->addWidget(splitter_Full_2, 0, 0, 1, 1);

        tabWidget->addTab(Train, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_15 = new QGridLayout(tab);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        iterate_splitter_full = new QSplitter(tab);
        iterate_splitter_full->setObjectName(QStringLiteral("iterate_splitter_full"));
        iterate_splitter_full->setOrientation(Qt::Vertical);
        frame_Dirs_3 = new QFrame(iterate_splitter_full);
        frame_Dirs_3->setObjectName(QStringLiteral("frame_Dirs_3"));
        sizePolicy.setHeightForWidth(frame_Dirs_3->sizePolicy().hasHeightForWidth());
        frame_Dirs_3->setSizePolicy(sizePolicy);
        frame_Dirs_3->setFrameShape(QFrame::StyledPanel);
        frame_Dirs_3->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_Dirs_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        iterate_pics_btn = new QPushButton(frame_Dirs_3);
        iterate_pics_btn->setObjectName(QStringLiteral("iterate_pics_btn"));
        iterate_pics_btn->setFlat(true);

        horizontalLayout_13->addWidget(iterate_pics_btn);

        iterate_pics_url = new QLineEdit(frame_Dirs_3);
        iterate_pics_url->setObjectName(QStringLiteral("iterate_pics_url"));

        horizontalLayout_13->addWidget(iterate_pics_url);

        horizontalSpacer_17 = new QSpacerItem(42, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_17);


        verticalLayout_8->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_18 = new QSpacerItem(7, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_18);

        iterate_add = new QPushButton(frame_Dirs_3);
        iterate_add->setObjectName(QStringLiteral("iterate_add"));
        iterate_add->setEnabled(true);
        iterate_add->setFlat(true);

        horizontalLayout_14->addWidget(iterate_add);

        horizontalSpacer_19 = new QSpacerItem(170, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_19);

        iterate_merge = new QPushButton(frame_Dirs_3);
        iterate_merge->setObjectName(QStringLiteral("iterate_merge"));
        iterate_merge->setEnabled(true);
        iterate_merge->setFlat(true);

        horizontalLayout_14->addWidget(iterate_merge);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_20);


        verticalLayout_8->addLayout(horizontalLayout_14);

        iterate_splitter_full->addWidget(frame_Dirs_3);
        splitter_Bottom_3 = new QSplitter(iterate_splitter_full);
        splitter_Bottom_3->setObjectName(QStringLiteral("splitter_Bottom_3"));
        sizePolicy1.setHeightForWidth(splitter_Bottom_3->sizePolicy().hasHeightForWidth());
        splitter_Bottom_3->setSizePolicy(sizePolicy1);
        splitter_Bottom_3->setOrientation(Qt::Horizontal);
        frame_iterate_lists = new QFrame(splitter_Bottom_3);
        frame_iterate_lists->setObjectName(QStringLiteral("frame_iterate_lists"));
        sizePolicy2.setHeightForWidth(frame_iterate_lists->sizePolicy().hasHeightForWidth());
        frame_iterate_lists->setSizePolicy(sizePolicy2);
        frame_iterate_lists->setMinimumSize(QSize(0, 0));
        frame_iterate_lists->setFrameShape(QFrame::StyledPanel);
        frame_iterate_lists->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_iterate_lists);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        splitter_5 = new QSplitter(frame_iterate_lists);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Vertical);
        iterate_pics = new QListWidget(splitter_5);
        iterate_pics->setObjectName(QStringLiteral("iterate_pics"));
        sizePolicy3.setHeightForWidth(iterate_pics->sizePolicy().hasHeightForWidth());
        iterate_pics->setSizePolicy(sizePolicy3);
        splitter_5->addWidget(iterate_pics);
        frame_iterate_dirs = new QFrame(splitter_5);
        frame_iterate_dirs->setObjectName(QStringLiteral("frame_iterate_dirs"));
        frame_iterate_dirs->setFrameShape(QFrame::StyledPanel);
        frame_iterate_dirs->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_iterate_dirs);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        iterate_dirs = new QListWidget(frame_iterate_dirs);
        iterate_dirs->setObjectName(QStringLiteral("iterate_dirs"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(iterate_dirs->sizePolicy().hasHeightForWidth());
        iterate_dirs->setSizePolicy(sizePolicy6);

        gridLayout_12->addWidget(iterate_dirs, 0, 0, 1, 1);

        frame_4 = new QFrame(frame_iterate_dirs);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy7);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 7, 0);
        iterate_dirs_add = new QPushButton(frame_4);
        iterate_dirs_add->setObjectName(QStringLiteral("iterate_dirs_add"));
        sizePolicy4.setHeightForWidth(iterate_dirs_add->sizePolicy().hasHeightForWidth());
        iterate_dirs_add->setSizePolicy(sizePolicy4);
        iterate_dirs_add->setMinimumSize(QSize(28, 28));
        iterate_dirs_add->setMaximumSize(QSize(28, 28));
        iterate_dirs_add->setBaseSize(QSize(28, 28));

        verticalLayout_9->addWidget(iterate_dirs_add);

        iterate_dirs_rem = new QPushButton(frame_4);
        iterate_dirs_rem->setObjectName(QStringLiteral("iterate_dirs_rem"));
        sizePolicy4.setHeightForWidth(iterate_dirs_rem->sizePolicy().hasHeightForWidth());
        iterate_dirs_rem->setSizePolicy(sizePolicy4);
        iterate_dirs_rem->setMinimumSize(QSize(28, 28));
        iterate_dirs_rem->setMaximumSize(QSize(28, 28));
        iterate_dirs_rem->setBaseSize(QSize(28, 28));

        verticalLayout_9->addWidget(iterate_dirs_rem);

        iterate_dirs_edit = new QPushButton(frame_4);
        iterate_dirs_edit->setObjectName(QStringLiteral("iterate_dirs_edit"));
        sizePolicy4.setHeightForWidth(iterate_dirs_edit->sizePolicy().hasHeightForWidth());
        iterate_dirs_edit->setSizePolicy(sizePolicy4);
        iterate_dirs_edit->setMinimumSize(QSize(28, 28));
        iterate_dirs_edit->setMaximumSize(QSize(28, 28));
        iterate_dirs_edit->setBaseSize(QSize(28, 28));

        verticalLayout_9->addWidget(iterate_dirs_edit);


        gridLayout_12->addWidget(frame_4, 0, 1, 1, 1);

        frame_5 = new QFrame(frame_iterate_dirs);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        sizePolicy4.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy4);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frame_5);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_16, 0, 0, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_21, 0, 2, 1, 1);

        iterate_save = new QPushButton(frame_5);
        iterate_save->setObjectName(QStringLiteral("iterate_save"));

        gridLayout_16->addWidget(iterate_save, 0, 1, 1, 1);


        gridLayout_12->addWidget(frame_5, 1, 0, 1, 2);

        splitter_5->addWidget(frame_iterate_dirs);

        gridLayout_13->addWidget(splitter_5, 0, 0, 1, 1);

        splitter_Bottom_3->addWidget(frame_iterate_lists);
        frame_iterate_image = new QFrame(splitter_Bottom_3);
        frame_iterate_image->setObjectName(QStringLiteral("frame_iterate_image"));
        sizePolicy5.setHeightForWidth(frame_iterate_image->sizePolicy().hasHeightForWidth());
        frame_iterate_image->setSizePolicy(sizePolicy5);
        frame_iterate_image->setMinimumSize(QSize(0, 0));
        frame_iterate_image->setFrameShape(QFrame::StyledPanel);
        frame_iterate_image->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_iterate_image);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        iterate_image = new ImageView(frame_iterate_image);
        iterate_image->setObjectName(QStringLiteral("iterate_image"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(5);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(iterate_image->sizePolicy().hasHeightForWidth());
        iterate_image->setSizePolicy(sizePolicy8);
        iterate_image->setMouseTracking(true);
        iterate_image->setAutoFillBackground(true);
        iterate_image->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        iterate_image->setDragMode(QGraphicsView::ScrollHandDrag);

        gridLayout_14->addWidget(iterate_image, 0, 0, 1, 1);

        iterate_image_toolbar = new QFrame(frame_iterate_image);
        iterate_image_toolbar->setObjectName(QStringLiteral("iterate_image_toolbar"));
        iterate_image_toolbar->setEnabled(true);
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(iterate_image_toolbar->sizePolicy().hasHeightForWidth());
        iterate_image_toolbar->setSizePolicy(sizePolicy9);
        iterate_image_toolbar->setFrameShape(QFrame::StyledPanel);
        iterate_image_toolbar->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(iterate_image_toolbar);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 7, 0);
        iterate_zin = new QPushButton(iterate_image_toolbar);
        iterate_zin->setObjectName(QStringLiteral("iterate_zin"));
        iterate_zin->setMinimumSize(QSize(27, 27));
        iterate_zin->setMaximumSize(QSize(27, 27));
        iterate_zin->setBaseSize(QSize(27, 27));

        verticalLayout_10->addWidget(iterate_zin);

        iterate_fit = new QPushButton(iterate_image_toolbar);
        iterate_fit->setObjectName(QStringLiteral("iterate_fit"));
        sizePolicy4.setHeightForWidth(iterate_fit->sizePolicy().hasHeightForWidth());
        iterate_fit->setSizePolicy(sizePolicy4);
        iterate_fit->setMinimumSize(QSize(36, 36));
        iterate_fit->setMaximumSize(QSize(36, 36));
        iterate_fit->setBaseSize(QSize(36, 36));

        verticalLayout_10->addWidget(iterate_fit);

        iterate_cen = new QPushButton(iterate_image_toolbar);
        iterate_cen->setObjectName(QStringLiteral("iterate_cen"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(iterate_cen->sizePolicy().hasHeightForWidth());
        iterate_cen->setSizePolicy(sizePolicy10);
        iterate_cen->setMinimumSize(QSize(36, 36));
        iterate_cen->setMaximumSize(QSize(36, 36));
        iterate_cen->setBaseSize(QSize(36, 36));

        verticalLayout_10->addWidget(iterate_cen);

        iterate_1x = new QPushButton(iterate_image_toolbar);
        iterate_1x->setObjectName(QStringLiteral("iterate_1x"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(36);
        sizePolicy11.setVerticalStretch(36);
        sizePolicy11.setHeightForWidth(iterate_1x->sizePolicy().hasHeightForWidth());
        iterate_1x->setSizePolicy(sizePolicy11);
        iterate_1x->setMinimumSize(QSize(36, 36));
        iterate_1x->setMaximumSize(QSize(28, 16777215));
        iterate_1x->setBaseSize(QSize(36, 36));

        verticalLayout_10->addWidget(iterate_1x);

        iterate_zout = new QPushButton(iterate_image_toolbar);
        iterate_zout->setObjectName(QStringLiteral("iterate_zout"));
        iterate_zout->setMinimumSize(QSize(27, 27));
        iterate_zout->setMaximumSize(QSize(27, 27));
        iterate_zout->setBaseSize(QSize(27, 27));
        iterate_zout->setStyleSheet(QStringLiteral(""));

        verticalLayout_10->addWidget(iterate_zout);


        gridLayout_14->addWidget(iterate_image_toolbar, 0, 1, 1, 1);

        splitter_Bottom_3->addWidget(frame_iterate_image);
        iterate_splitter_full->addWidget(splitter_Bottom_3);

        gridLayout_15->addWidget(iterate_splitter_full, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        Classify = new QWidget();
        Classify->setObjectName(QStringLiteral("Classify"));
        gridLayout_6 = new QGridLayout(Classify);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        splitter_Full = new QSplitter(Classify);
        splitter_Full->setObjectName(QStringLiteral("splitter_Full"));
        splitter_Full->setOrientation(Qt::Vertical);
        frame_Dirs = new QFrame(splitter_Full);
        frame_Dirs->setObjectName(QStringLiteral("frame_Dirs"));
        sizePolicy.setHeightForWidth(frame_Dirs->sizePolicy().hasHeightForWidth());
        frame_Dirs->setSizePolicy(sizePolicy);
        frame_Dirs->setFrameShape(QFrame::StyledPanel);
        frame_Dirs->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_Dirs);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        classify_root_btn = new QPushButton(frame_Dirs);
        classify_root_btn->setObjectName(QStringLiteral("classify_root_btn"));
        QSizePolicy sizePolicy12(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(classify_root_btn->sizePolicy().hasHeightForWidth());
        classify_root_btn->setSizePolicy(sizePolicy12);
        classify_root_btn->setFlat(true);

        horizontalLayout_4->addWidget(classify_root_btn);

        classify_root_url = new QLineEdit(frame_Dirs);
        classify_root_url->setObjectName(QStringLiteral("classify_root_url"));

        horizontalLayout_4->addWidget(classify_root_url);

        horizontalSpacer_6 = new QSpacerItem(42, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label = new QLabel(frame_Dirs);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_9->addWidget(label);

        predict_threshold = new QLineEdit(frame_Dirs);
        predict_threshold->setObjectName(QStringLiteral("predict_threshold"));
        predict_threshold->setMaxLength(200);

        horizontalLayout_9->addWidget(predict_threshold);

        horizontalSpacer_7 = new QSpacerItem(600, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
     
        label_2 = new QLabel(frame_Dirs);
        label_2->setObjectName(QStringLiteral("label_2"));
        
        horizontalLayout_2->addWidget(label_2);
        
        faltitude_input = new QLineEdit(frame_Dirs);
        faltitude_input->setObjectName(QStringLiteral("faltitude_input"));
        faltitude_input->setMaxLength(50);
        
        horizontalLayout_2->addWidget(faltitude_input);
        
        horizontalSpacer_8 = new QSpacerItem(333, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        button_predict = new QPushButton(frame_Dirs);
        button_predict->setObjectName(QStringLiteral("button_predict"));
        button_predict->setFlat(true);

        horizontalLayout_2->addWidget(button_predict);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        splitter_Full->addWidget(frame_Dirs);
        splitter_Bottom = new QSplitter(splitter_Full);
        splitter_Bottom->setObjectName(QStringLiteral("splitter_Bottom"));
        sizePolicy1.setHeightForWidth(splitter_Bottom->sizePolicy().hasHeightForWidth());
        splitter_Bottom->setSizePolicy(sizePolicy1);
        splitter_Bottom->setOrientation(Qt::Horizontal);
        frame_Lists = new QFrame(splitter_Bottom);
        frame_Lists->setObjectName(QStringLiteral("frame_Lists"));
        sizePolicy2.setHeightForWidth(frame_Lists->sizePolicy().hasHeightForWidth());
        frame_Lists->setSizePolicy(sizePolicy2);
        frame_Lists->setMinimumSize(QSize(0, 0));
        frame_Lists->setFrameShape(QFrame::StyledPanel);
        frame_Lists->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_Lists);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(frame_Lists);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy13(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy13);
        splitter->setBaseSize(QSize(300, 0));
        splitter->setOrientation(Qt::Vertical);
        classify_pics = new QListWidget(splitter);
        classify_pics->setObjectName(QStringLiteral("classify_pics"));
        sizePolicy3.setHeightForWidth(classify_pics->sizePolicy().hasHeightForWidth());
        classify_pics->setSizePolicy(sizePolicy3);
        splitter->addWidget(classify_pics);
        dirList = new QListWidget(splitter);
        dirList->setObjectName(QStringLiteral("dirList"));
        sizePolicy3.setHeightForWidth(dirList->sizePolicy().hasHeightForWidth());
        dirList->setSizePolicy(sizePolicy3);
        splitter->addWidget(dirList);

        verticalLayout->addWidget(splitter);

        frame_ListButtons = new QFrame(frame_Lists);
        frame_ListButtons->setObjectName(QStringLiteral("frame_ListButtons"));
        frame_ListButtons->setMinimumSize(QSize(0, 0));
        frame_ListButtons->setFrameShape(QFrame::StyledPanel);
        frame_ListButtons->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_ListButtons);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        classify_refresh = new QPushButton(frame_ListButtons);
        classify_refresh->setObjectName(QStringLiteral("classify_refresh"));
        sizePolicy4.setHeightForWidth(classify_refresh->sizePolicy().hasHeightForWidth());
        classify_refresh->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(classify_refresh);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_ListButtons);

        splitter_Bottom->addWidget(frame_Lists);
        frame_Image = new QFrame(splitter_Bottom);
        frame_Image->setObjectName(QStringLiteral("frame_Image"));
        sizePolicy5.setHeightForWidth(frame_Image->sizePolicy().hasHeightForWidth());
        frame_Image->setSizePolicy(sizePolicy5);
        frame_Image->setMinimumSize(QSize(0, 0));
        frame_Image->setFrameShape(QFrame::StyledPanel);
        frame_Image->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_Image);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        classify_image = new ImageView(frame_Image);
        classify_image->setObjectName(QStringLiteral("classify_image"));
        sizePolicy8.setHeightForWidth(classify_image->sizePolicy().hasHeightForWidth());
        classify_image->setSizePolicy(sizePolicy8);
        classify_image->setMouseTracking(true);
        classify_image->setAutoFillBackground(true);
        classify_image->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        classify_image->setDragMode(QGraphicsView::ScrollHandDrag);

        gridLayout_2->addWidget(classify_image, 0, 0, 1, 1);

        frame_Buttons = new QFrame(frame_Image);
        frame_Buttons->setObjectName(QStringLiteral("frame_Buttons"));
        frame_Buttons->setEnabled(true);
        sizePolicy9.setHeightForWidth(frame_Buttons->sizePolicy().hasHeightForWidth());
        frame_Buttons->setSizePolicy(sizePolicy9);
        frame_Buttons->setFrameShape(QFrame::StyledPanel);
        frame_Buttons->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_Buttons);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 7, 0);
        button_zin = new QPushButton(frame_Buttons);
        button_zin->setObjectName(QStringLiteral("button_zin"));
        button_zin->setMinimumSize(QSize(27, 27));
        button_zin->setMaximumSize(QSize(27, 27));
        button_zin->setBaseSize(QSize(27, 27));

        verticalLayout_5->addWidget(button_zin);

        button_fit = new QPushButton(frame_Buttons);
        button_fit->setObjectName(QStringLiteral("button_fit"));
        sizePolicy4.setHeightForWidth(button_fit->sizePolicy().hasHeightForWidth());
        button_fit->setSizePolicy(sizePolicy4);
        button_fit->setMinimumSize(QSize(36, 36));
        button_fit->setMaximumSize(QSize(36, 36));
        button_fit->setBaseSize(QSize(36, 36));

        verticalLayout_5->addWidget(button_fit);

        button_cen = new QPushButton(frame_Buttons);
        button_cen->setObjectName(QStringLiteral("button_cen"));
        sizePolicy10.setHeightForWidth(button_cen->sizePolicy().hasHeightForWidth());
        button_cen->setSizePolicy(sizePolicy10);
        button_cen->setMinimumSize(QSize(36, 36));
        button_cen->setMaximumSize(QSize(36, 36));
        button_cen->setBaseSize(QSize(36, 36));

        verticalLayout_5->addWidget(button_cen);

        button_1x = new QPushButton(frame_Buttons);
        button_1x->setObjectName(QStringLiteral("button_1x"));
        sizePolicy11.setHeightForWidth(button_1x->sizePolicy().hasHeightForWidth());
        button_1x->setSizePolicy(sizePolicy11);
        button_1x->setMinimumSize(QSize(36, 36));
        button_1x->setMaximumSize(QSize(36, 36));
        button_1x->setBaseSize(QSize(36, 36));

        verticalLayout_5->addWidget(button_1x);

        button_zout = new QPushButton(frame_Buttons);
        button_zout->setObjectName(QStringLiteral("button_zout"));
        button_zout->setMinimumSize(QSize(27, 27));
        button_zout->setMaximumSize(QSize(27, 27));
        button_zout->setBaseSize(QSize(27, 27));
        button_zout->setStyleSheet(QStringLiteral(""));

        verticalLayout_5->addWidget(button_zout);


        gridLayout_2->addWidget(frame_Buttons, 0, 1, 1, 1);

        splitter_Bottom->addWidget(frame_Image);
        splitter_Full->addWidget(splitter_Bottom);

        gridLayout_6->addWidget(splitter_Full, 0, 0, 1, 1);

        tabWidget->addTab(Classify, QString());
        Coordinates = new QWidget();
        Coordinates->setObjectName(QStringLiteral("Coordinates"));
        gridLayout_4 = new QGridLayout(Coordinates);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        splitter_4 = new QSplitter(Coordinates);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        coord_files = new QListWidget(layoutWidget);
        coord_files->setObjectName(QStringLiteral("coord_files"));
        coord_files->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout_4->addWidget(coord_files);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        coord_openfile = new QPushButton(layoutWidget);
        coord_openfile->setObjectName(QStringLiteral("coord_openfile"));

        horizontalLayout_5->addWidget(coord_openfile);

        coord_delete = new QPushButton(layoutWidget);
        coord_delete->setObjectName(QStringLiteral("coord_delete"));

        horizontalLayout_5->addWidget(coord_delete);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_5);

        splitter_4->addWidget(layoutWidget);
        coord_text = new QTextBrowser(splitter_4);
        coord_text->setObjectName(QStringLiteral("coord_text"));
        splitter_4->addWidget(coord_text);

        gridLayout_4->addWidget(splitter_4, 0, 0, 1, 1);

        tabWidget->addTab(Coordinates, QString());
        Maps = new QWidget();
        Maps->setObjectName(QStringLiteral("Maps"));
        tabWidget->addTab(Maps, QString());
        Drones = new QWidget();
        Drones->setObjectName(QStringLiteral("Drones"));
        gridLayout_3 = new QGridLayout(Drones);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter_2 = new QSplitter(Drones);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy14(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(3);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy14);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_5->addWidget(textEdit, 0, 0, 1, 1);

        splitter_2->addWidget(frame);
        frame_2 = new QFrame(splitter_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy15(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy15.setHorizontalStretch(1);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy15);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        textEdit_2 = new QTextEdit(frame_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout_7->addWidget(textEdit_2, 0, 0, 1, 1);

        splitter_2->addWidget(frame_2);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);

        tabWidget->addTab(Drones, QString());

        horizontalLayout_6->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        EcoCensus->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EcoCensus);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 957, 22));
        EcoCensus->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EcoCensus);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        EcoCensus->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EcoCensus);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EcoCensus->setStatusBar(statusBar);

        retranslateUi(EcoCensus);
        QObject::connect(button_zin, SIGNAL(clicked()), classify_image, SLOT(slot_zin()));
        QObject::connect(button_fit, SIGNAL(clicked()), classify_image, SLOT(slot_fit()));
        QObject::connect(button_cen, SIGNAL(clicked()), classify_image, SLOT(slot_cen()));
        QObject::connect(button_1x, SIGNAL(clicked()), classify_image, SLOT(slot_1x()));
        QObject::connect(button_zout, SIGNAL(clicked()), classify_image, SLOT(slot_zout()));
        QObject::connect(iterate_zin, SIGNAL(clicked()), iterate_image, SLOT(slot_zin()));
        QObject::connect(iterate_zout, SIGNAL(clicked()), iterate_image, SLOT(slot_zout()));
        QObject::connect(iterate_1x, SIGNAL(clicked()), iterate_image, SLOT(slot_1x()));
        QObject::connect(iterate_cen, SIGNAL(clicked()), iterate_image, SLOT(slot_cen()));
        QObject::connect(iterate_fit, SIGNAL(clicked()), iterate_image, SLOT(slot_fit()));
        QObject::connect(iterate_pics, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), iterate_image, SLOT(slot_changeitem(QListWidgetItem*,QListWidgetItem*)));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(EcoCensus);
    } // setupUi

    void retranslateUi(QMainWindow *EcoCensus)
    {
        EcoCensus->setWindowTitle(QApplication::translate("EcoCensus", "EcoCensus", nullptr));
        train_imgs_btn->setText(QApplication::translate("EcoCensus", "Training Database", nullptr));
        train_start->setText(QApplication::translate("EcoCensus", "Begin Training", nullptr));
#ifndef QT_NO_TOOLTIP
        train_dir_add_3->setToolTip(QApplication::translate("EcoCensus", "Add Directory", nullptr));
#endif // QT_NO_TOOLTIP
        train_dir_add_3->setText(QApplication::translate("EcoCensus", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        train_dir_add_4->setToolTip(QApplication::translate("EcoCensus", "Remove Directory", nullptr));
#endif // QT_NO_TOOLTIP
        train_dir_add_4->setText(QApplication::translate("EcoCensus", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        train_dir_add->setToolTip(QApplication::translate("EcoCensus", "Rename", nullptr));
#endif // QT_NO_TOOLTIP
        train_dir_add->setText(QApplication::translate("EcoCensus", "I", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Train), QApplication::translate("EcoCensus", "Train", nullptr));
        iterate_pics_btn->setText(QApplication::translate("EcoCensus", "Input Images", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_add->setToolTip(QApplication::translate("EcoCensus", "Partition and add new images into the dataset", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_add->setText(QApplication::translate("EcoCensus", "Reclassify Images", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_merge->setToolTip(QApplication::translate("EcoCensus", "Partition and add new images into the dataset", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_merge->setText(QApplication::translate("EcoCensus", "Merge with Training Data", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_dirs_add->setToolTip(QApplication::translate("EcoCensus", "Add Directory", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_dirs_add->setText(QApplication::translate("EcoCensus", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_dirs_rem->setToolTip(QApplication::translate("EcoCensus", "Remove Directory", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_dirs_rem->setText(QApplication::translate("EcoCensus", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_dirs_edit->setToolTip(QApplication::translate("EcoCensus", "Rename", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_dirs_edit->setText(QApplication::translate("EcoCensus", "I", nullptr));
        iterate_save->setText(QApplication::translate("EcoCensus", "Save Single Image", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_zin->setToolTip(QApplication::translate("EcoCensus", "Zoom In", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_zin->setText(QApplication::translate("EcoCensus", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_fit->setToolTip(QApplication::translate("EcoCensus", "Fit to View", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_fit->setText(QApplication::translate("EcoCensus", "Fit", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_cen->setToolTip(QApplication::translate("EcoCensus", "Center in View", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_cen->setText(QApplication::translate("EcoCensus", "Cen", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_1x->setToolTip(QApplication::translate("EcoCensus", "100% Zoom", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_1x->setText(QApplication::translate("EcoCensus", "1x", nullptr));
#ifndef QT_NO_TOOLTIP
        iterate_zout->setToolTip(QApplication::translate("EcoCensus", "Zoom Out", nullptr));
#endif // QT_NO_TOOLTIP
        iterate_zout->setText(QApplication::translate("EcoCensus", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EcoCensus", "Iterate", nullptr));
        classify_root_btn->setText(QApplication::translate("EcoCensus", "Images Directory", nullptr));
#ifndef QT_NO_TOOLTIP
        classify_root_url->setToolTip(QApplication::translate("EcoCensus", "<html><head/><body><p>Root directory to find images to classify</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        classify_root_url->setText(QString());
        label->setText(QApplication::translate("EcoCensus", "   Predictions Threshold", nullptr));
        label_2->setText(QApplication::translate("EcoCensus", " Flight Altitude ", nullptr));
        button_predict->setText(QApplication::translate("EcoCensus", "Partition and Predict", nullptr));
        classify_refresh->setText(QApplication::translate("EcoCensus", "Refresh Features", nullptr));
#ifndef QT_NO_TOOLTIP
        button_zin->setToolTip(QApplication::translate("EcoCensus", "Zoom In", nullptr));
#endif // QT_NO_TOOLTIP
        button_zin->setText(QApplication::translate("EcoCensus", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        button_fit->setToolTip(QApplication::translate("EcoCensus", "Fit to View", nullptr));
#endif // QT_NO_TOOLTIP
        button_fit->setText(QApplication::translate("EcoCensus", "Fit", nullptr));
#ifndef QT_NO_TOOLTIP
        button_cen->setToolTip(QApplication::translate("EcoCensus", "Center in View", nullptr));
#endif // QT_NO_TOOLTIP
        button_cen->setText(QApplication::translate("EcoCensus", "Cen", nullptr));
#ifndef QT_NO_TOOLTIP
        button_1x->setToolTip(QApplication::translate("EcoCensus", "100% Zoom", nullptr));
#endif // QT_NO_TOOLTIP
        button_1x->setText(QApplication::translate("EcoCensus", "1x", nullptr));
#ifndef QT_NO_TOOLTIP
        button_zout->setToolTip(QApplication::translate("EcoCensus", "Zoom Out", nullptr));
#endif // QT_NO_TOOLTIP
        button_zout->setText(QApplication::translate("EcoCensus", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Classify), QApplication::translate("EcoCensus", "Classify", nullptr));
        coord_openfile->setText(QApplication::translate("EcoCensus", "Show Coords", nullptr));
        coord_delete->setText(QApplication::translate("EcoCensus", "Delete File", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Coordinates), QApplication::translate("EcoCensus", "Coordinates", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Maps), QApplication::translate("EcoCensus", "Maps", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Drones), QApplication::translate("EcoCensus", "Drones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EcoCensus: public Ui_EcoCensus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
