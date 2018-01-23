#include "ecodialog.h"
#include "ui_ecodialog.h"

EcoDialog::EcoDialog(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EcoDialog)
{
    ui->setupUi(this);
}

EcoDialog::~EcoDialog()
{
    delete ui;
}
