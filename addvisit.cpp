#include "addvisit.h"
#include "ui_addvisit.h"

AddVisit::AddVisit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVisit)
{
    ui->setupUi(this);
}

AddVisit::~AddVisit()
{
    delete ui;
}
