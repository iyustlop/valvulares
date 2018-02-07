#include "ecodialog.h"
#include "ui_ecodialog.h"
#include "bean/eco/ecobean.h"

#include <QMessageBox>

EcoDialog::EcoDialog(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EcoDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

EcoDialog::~EcoDialog()
{
    delete ui;
}

QString EcoDialog::getNumeroHistoria() const
{
    return numeroHistoria;
}

void EcoDialog::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void EcoDialog::on_pushButtonGuardar_clicked()
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

void EcoDialog::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
