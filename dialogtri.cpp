#include "dialogtri.h"
#include "ui_dialogtri.h"
#include "bean/tri/tribean.h"

#include <QMessageBox>

DialogTri::DialogTri(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTri)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogTri::~DialogTri()
{
    delete ui;
}

QString DialogTri::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogTri::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogTri::on_pushButtonTri_clicked()
{
    TriBean myTriBean;
    myTriBean.setDateTri(ui->dateEdit->text());
    myTriBean.setPsap(ui->lineEditPsap->text());
    myTriBean.setGrado(ui->comboBoxGrado->currentText());

    QSqlError err = insertTriDb.insertTri(getNumeroHistoria(),myTriBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogTri::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
