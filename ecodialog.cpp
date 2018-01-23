#include "ecodialog.h"
#include "ui_ecodialog.h"
#include "eco/ecobean.h"

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
    myEcoBean.setRaizAo(ui->lineEditRaizAo->text());
    myEcoBean.setAoAscend(ui->lineEditAoAsc->text());
    myEcoBean.setDilataVi(ui->lineEditDilatVi->text());
    myEcoBean.setDilataVd(ui->lineEditDilataVd->text());
    myEcoBean.setTapse(ui->lineEditTapse->text());

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
