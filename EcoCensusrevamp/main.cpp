/*
 main.cpp
 EcoCensus
 Copyright 2017: Rebekah Loving and Morgan West
 */

#include "EcoCensus.h"
#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile File(":/ui/styles/stylesheet_default.css");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    a.setStyleSheet(StyleSheet);
    File.close();

    EcoCensus w;
    w.show();

    return a.exec();
}
