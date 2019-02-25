#include "dialogresonancia.h"
#include "ui_dialogresonancia.h"
#include "bean/reso/resonanciabean.h"

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

void DialogResonancia::on_pushButtonResoGuardar_clicked()
{
    ResonanciaBean myResoBean;

    myResoBean.setFechaReso(ui->dateEditResoFecha->text());
    myResoBean.setFevi(ui->lineEditResoFevi->text());
    myResoBean.setVtdVi(ui->lineEditResoVtvdi->text());
    myResoBean.setFracRegValMit(ui->lineEditResoFracRegMit->text());
    myResoBean.setFracRegValAo(ui->lineEditResoFragRegAo->text());
    myResoBean.setRaizAo(ui->lineEditRaizAo->text());
    myResoBean.setAoAscend(ui->lineEditResoAoAsc->text());
    myResoBean.setRealceTardio(ui->lineEditResoRealceT->text());
    myResoBean.setVarios(ui->lineEditResoVarios->text());

    if (ui->radioButtonResoDiViSi->isChecked()){
        myResoBean.setDilataVi("Si");
    }
    else{
        myResoBean.setDilataVi("No");
    }
    if (ui->radioButtonResoDiVdSi->isChecked()){
        myResoBean.setDilataVd("Si");
    }
    else{
        myResoBean.setDilataVd("No");
    }

    QSqlError err = insertResonancia.insertResonancia(getNumeroHistoria(),myResoBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogResonancia::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

void DialogResonancia::on_radioButtonResoDiViSi_clicked()
{
    if(ui->radioButtonResoDiViNo->isChecked()){
        ui->radioButtonResoDiViNo->setChecked(false);
    }
}

void DialogResonancia::on_radioButtonResoDiViNo_clicked()
{
    if(ui->radioButtonResoDiViSi->isChecked()){
        ui->radioButtonResoDiViSi->setChecked(false);
    }
}

void DialogResonancia::on_radioButtonResoDiVdSi_clicked()
{
    if(ui->radioButtonResoDiVdNo->isChecked()){
        ui->radioButtonResoDiVdNo->setChecked(false);
    }
}

void DialogResonancia::on_radioButtonResoDiVdNo_clicked()
{
    if(ui->radioButtonResoDiVdSi->isChecked()){
        ui->radioButtonResoDiVdSi->setChecked(false);
    }
}
