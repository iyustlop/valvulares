#include "dialogeco.h"
#include "ui_ecodialog.h"
#include "bean/eco/ecobean.h"

#include <QMessageBox>

DialogEco::DialogEco(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEco)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogEco::~DialogEco()
{
    delete ui;
}

QString DialogEco::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogEco::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogEco::on_pushButtonGuardar_clicked()
{
    ecoBean myEcoBean;

    myEcoBean.setFechaEco(ui->dateEditFechaEco->text());
    myEcoBean.setFevi(ui->lineEditFevi->text());
    myEcoBean.setVolAi(ui->lineEditVolAuIz->text());
    myEcoBean.setRaizAo(ui->lineEditRaizAo->text());
    myEcoBean.setAoAscend(ui->lineEditAoAsc->text());
    myEcoBean.setTapse(ui->lineEditTapse->text());

    if (ui->radioButtonDiViSi->isChecked()){
        myEcoBean.setDilataVi("Si");
    }
    else{
        myEcoBean.setDilataVi("No");
    }
    if (ui->radioButtonDiVdSi->isChecked()){
        myEcoBean.setDilataVd("Si");
    }
    else{
        myEcoBean.setDilataVd("No");
    }

    QSqlError err = insertEcoDb.insertEco(getNumeroHistoria(),myEcoBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogEco::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

void DialogEco::on_radioButtonDiVdNo_clicked()
{
    if(ui->radioButtonDiVdSi->isChecked()){
        ui->radioButtonDiVdSi->setChecked(false);
    }
}

void DialogEco::on_radioButtonDiVdSi_clicked()
{
    if(ui->radioButtonDiVdNo->isCheckable()){
        ui->radioButtonDiVdNo->setChecked(false);
    }
}

void DialogEco::on_radioButtonDiViNo_clicked()
{
    if(ui->radioButtonDiViSi->isChecked()){
        ui->radioButtonDiViSi->setChecked(false);
    }
}

void DialogEco::on_radioButtonDiViSi_clicked()
{
    if(ui->radioButtonDiViNo->isCheckable()){
        ui->radioButtonDiViNo->setChecked(false);
    }
}
