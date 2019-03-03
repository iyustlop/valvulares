#include "dialogprotesisbiologica.h"
#include "ui_dialogprotesisbiologica.h"
#include "bean/protesis/protesisbiologicabean.h"

#include <QMessageBox>

DialogProtesisBiologica::DialogProtesisBiologica(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProtesisBiologica)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogProtesisBiologica::~DialogProtesisBiologica()
{
    delete ui;
}

QString DialogProtesisBiologica::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogProtesisBiologica::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogProtesisBiologica::on_pushButtonProtBiolog_clicked()
{
    ProtesisBiologicaBean myProtesisBiologicaBean;
    myProtesisBiologicaBean.setDateProtesisBiologica(ui->dateEditProtBio->text());
    myProtesisBiologicaBean.setTipoProtesisBiologica(ui->lineEditTipo->text());
    myProtesisBiologicaBean.setGradienteMax(ui->lineEditGradienteMaximo->text());
    myProtesisBiologicaBean.setGradienteMed(ui->lineEditGradienteMedio->text());
    myProtesisBiologicaBean.setRi(ui->lineEditRi->text());
    myProtesisBiologicaBean.setLeak(ui->lineEditLeak->text());

    QSqlError err = insertProtesisBiologicaDb.insertProtesisBiologicaDb(getNumeroHistoria(),myProtesisBiologicaBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogProtesisBiologica::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
