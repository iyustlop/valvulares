#include "dialogprotesismecanica.h"
#include "ui_dialogprotesismecanica.h"
#include "bean/protesis/protesismecanicacabean.h"

#include <QMessageBox>

DialogProtesisMecanica::DialogProtesisMecanica(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProtesisMecanica)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogProtesisMecanica::~DialogProtesisMecanica()
{
    delete ui;
}

QString DialogProtesisMecanica::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogProtesisMecanica::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogProtesisMecanica::on_pushButtonProtMec_clicked()
{
    ProtesisMecanicaBean myProtesisMecanicaBean;
    myProtesisMecanicaBean.setDateProtesisMecanica(ui->dateEditProtBio->text());
    myProtesisMecanicaBean.setTipoProtesisMecanica(ui->lineEditTipo->text());
    myProtesisMecanicaBean.setGradienteMax(ui->lineEditGradienteMaximo->text());
    myProtesisMecanicaBean.setGradienteMed(ui->lineEditGradienteMedio->text());
    myProtesisMecanicaBean.setTAcenAo(ui->lineEditTacEnAo->text());
    myProtesisMecanicaBean.setLeak(ui->lineEditLeak->text());

    QSqlError err = insertProtesisMecanicaaDb.insertProtesisMecanicaDb(getNumeroHistoria(),myProtesisMecanicaBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogProtesisMecanica::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}


