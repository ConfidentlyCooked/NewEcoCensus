#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::CustomizeWindowHint);
}

ConfirmDialog::ConfirmDialog(QWidget *parent, QString text) :
    ConfirmDialog(parent)
{
    ui->label->setText(text);
}

ConfirmDialog::ConfirmDialog(QWidget *parent, QString text, QString title) :
    ConfirmDialog(parent, text)
{
    setWindowTitle(title);
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}
