/********************************************************************************
** Form generated from reading UI file 'colortest.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORTEST_H
#define UI_COLORTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorTest
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QFrame *ButtonFrame;
    QGridLayout *gridLayout;
    QPushButton *colorSwatch;

    void setupUi(QWidget *ColorTest)
    {
        if (ColorTest->objectName().isEmpty())
            ColorTest->setObjectName(QStringLiteral("ColorTest"));
        ColorTest->resize(400, 62);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorTest->sizePolicy().hasHeightForWidth());
        ColorTest->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ColorTest);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 3, -1, 3);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(ColorTest);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setAcceptDrops(false);
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        ButtonFrame = new QFrame(ColorTest);
        ButtonFrame->setObjectName(QStringLiteral("ButtonFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ButtonFrame->sizePolicy().hasHeightForWidth());
        ButtonFrame->setSizePolicy(sizePolicy2);
        ButtonFrame->setAutoFillBackground(false);
        ButtonFrame->setStyleSheet(QLatin1String("#ButtonFrame{\n"
"background-image: url(:/ui/buttons/transparency_swatch.gif) !important;\n"
"border: 1px solid black;\n"
"}"));
        ButtonFrame->setFrameShape(QFrame::StyledPanel);
        ButtonFrame->setFrameShadow(QFrame::Raised);
        ButtonFrame->setLineWidth(1);
        gridLayout = new QGridLayout(ButtonFrame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        colorSwatch = new QPushButton(ButtonFrame);
        colorSwatch->setObjectName(QStringLiteral("colorSwatch"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(colorSwatch->sizePolicy().hasHeightForWidth());
        colorSwatch->setSizePolicy(sizePolicy3);
        colorSwatch->setAutoFillBackground(false);
        colorSwatch->setStyleSheet(QLatin1String("background-color: transparent !important;\n"
"border: 0 !important;\n"
"border-radius: 0 !important;"));
        colorSwatch->setFlat(true);

        gridLayout->addWidget(colorSwatch, 0, 0, 1, 1);


        horizontalLayout->addWidget(ButtonFrame);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ColorTest);

        QMetaObject::connectSlotsByName(ColorTest);
    } // setupUi

    void retranslateUi(QWidget *ColorTest)
    {
        ColorTest->setWindowTitle(QApplication::translate("ColorTest", "Form", nullptr));
        colorSwatch->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ColorTest: public Ui_ColorTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORTEST_H
