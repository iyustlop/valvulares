#include "dialogresonancia.h"
#include "ui_dialogresonancia.h"
#include "bean/eco/ecobean.h"

#include <QMessageBox>

DialogResonancia::DialogResonancia(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResonancia)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogResonancia::~DialogResonancia()
{
    delete ui;
}

QString DialogResonancia::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogResonancia::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogResonancia::on_pushButtonGuardar_clicked()
{

}
