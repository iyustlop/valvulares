#include "dialogmitral.h"
#include "ui_dialogmitral.h"

#include <QMessageBox>

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

void DialogMitral::on_pushButtonMitral_clicked()
{
    MitralBean mitralBean;

    mitralBean.setFecha(ui->dateEditMitral->text());
    mitralBean.setGrdMedio(ui->lineEditGradMedio->text());
    mitralBean.setAvmXtmp(ui->lineEditAvmXtmp->text());
    mitralBean.setVOndaE(ui->lineEditVelOndaE->text());
    mitralBean.setORe(ui->lineEditOre->text());
    mitralBean.setVR(ui->lineEditVR->text());
    mitralBean.setVC(ui->lineEditVc->text());

    if (ui->radioButtonVvppSi->isChecked()) {
        mitralBean.setInvSistolicaVvpp("Si");
    } else if (ui->radioButtonVvppNo->isChecked()) {
        mitralBean.setInvSistolicaVvpp("No");
    } else {
        mitralBean.setInvSistolicaVvpp("Na");
    }

    QSqlError err = mitralDb.insertMitral(getNumeroHistoria(),mitralBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();

}

void DialogMitral::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
