#include "dialogmitral.h"
#include "ui_dialogmitral.h"

DialogMitral::DialogMitral(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMitral)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogMitral::~DialogMitral()
{
    delete ui;
}

QString DialogMitral::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogMitral::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}
