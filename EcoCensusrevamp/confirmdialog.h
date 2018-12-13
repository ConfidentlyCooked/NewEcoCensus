/*
 confirmdialog.h
 EcoCensus
 Copyright 2018: Morgan Friend, Rebekah Loving, and Morgan West
 */

#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = 0);
    explicit ConfirmDialog(QWidget *parent, QString text);
    explicit ConfirmDialog(QWidget *parent, QString text, QString title);
    ~ConfirmDialog();

private:
    Ui::ConfirmDialog *ui;
};

#endif // CONFIRMDIALOG_H
