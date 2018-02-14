#include "dialogaorta.h"
#include "ui_dialogaorta.h"
#include "bean/aorta/aortabean.h"

#include <QMessageBox>

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

void DialogAorta::on_pushButtonAorta_clicked()
{
    AortaBean myAortaBean;

    myAortaBean.setDate(ui->dateEditAorta->text());
    myAortaBean.setGradAo(ui->lineEditGradientePicoAo->text());
    myAortaBean.setGradMedioAo(ui->lineEditGradienteMedioAo->text());
    myAortaBean.setRelacionDeInl(ui->lineEditRelacionDeIntegrales->text());
    myAortaBean.setAreaAo(ui->lineEditAreaAortica->text());
    myAortaBean.setOReIaO(ui->lineEditOreIao->text());
    myAortaBean.setVRiAo(ui->lineEditVrIao->text());
    myAortaBean.setVCiAo(ui->lineEditVcIao->text());
    myAortaBean.setRelAltJetIao(ui->lineEditRelacionAlturaJetIaoItsvi->text());

    if (ui->radioButtonInversionIaoSi->isChecked()){
        myAortaBean.setInversionIao("Si");
    }
    else if (ui->radioButtonInversionIaoNo->isChecked()){
        myAortaBean.setInversionIao("No");
    }
    else{
        myAortaBean.setInversionIao("Na");
    }

    QSqlError err = inserAortaDb.insertAorta(getNumeroHistoria(),myAortaBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogAorta::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
