#include "dialogergo.h"
#include "ui_dialogergo.h"
#include "bean/ergo/ergobean.h"

#include <QMessageBox>

DialogErgo::DialogErgo(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogErgo)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}


DialogErgo::~DialogErgo()
{
    delete ui;
}

QString DialogErgo::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogErgo::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogErgo::on_pushButtonErgoGuardar_clicked()
{
    ErgoBean myErgoBean;

    myErgoBean.setFechaErgo(ui->dateEditErgo->text());
    myErgoBean.setTEsfuerzo(ui->lineEditTesfuerzo->text());
    myErgoBean.setMets(ui->lineEditMets->text());


    QSqlError err = insertErgoDB.insertErgo(getNumeroHistoria(),myErgoBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogErgo::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
