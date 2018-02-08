#include "dialogaorta.h"
#include "ui_dialogaorta.h"

DialogAorta::DialogAorta(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAorta)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogAorta::~DialogAorta()
{
    delete ui;
}

QString DialogAorta::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogAorta::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}
