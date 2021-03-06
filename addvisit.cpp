#include "addvisit.h"
#include "ui_addvisit.h"
#include "bean/cita/cita.h"
#include "bean/cita/parametrosanaliticos.h"
#include "bean/cita/visitbean.h"
#include "mainwindow.h"

#include <QMessageBox>

AddVisit::AddVisit(QString numeroHistoria, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVisit)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

AddVisit::~AddVisit()
{
    delete ui;
}

void AddVisit::on_pushButtonCancelar_clicked()
{
    close();
}

void AddVisit::on_pushButtonGuardar_clicked()
{
    VisitBean visita;
    Cita crearCita;
    ParametrosAnaliticos crearParametrosAnaliticos;
    QList<QListWidgetItem*> itemSelected;

    crearCita.setFechaConsulta(ui->fechaConsultaDateEdit->text());
    crearCita.setRitmo(ui->ritmoComboBox->currentText());
    crearCita.setGradoFuncional(ui->gradoFuncionalComboBox->currentText());

    if (ui->listWidgetFRCV->selectedItems().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                              "Error insert in FRCV ");
        return;
    }
    else{

        itemSelected = ui->listWidgetFRCV->selectedItems();

        QString texts;
        foreach (QListWidgetItem *item, itemSelected) {
            texts.append(item->text());
            texts.append(";");
        }

        crearCita.setFrcv(texts);
    }

    crearParametrosAnaliticos.setHB(ui->hBLineEdit->text());
    crearParametrosAnaliticos.setCreatinina(ui->creatininaLineEdit->text());
    crearParametrosAnaliticos.setFG(ui->fGLineEdit->text());
    crearParametrosAnaliticos.setProBNP(ui->proBNPLineEdit->text());
    crearParametrosAnaliticos.setPotasio(ui->potasioLineEdit->text());

    if (ui->listWidgetTratamiento->selectedItems().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                              "Error insert in Parametros Analiticos");
        return;
    }
    else{

        itemSelected = ui->listWidgetTratamiento->selectedItems();

        QString texts;
        foreach (QListWidgetItem *item, itemSelected) {
            texts.append(item->text());
            texts.append(";");
        }

        crearParametrosAnaliticos.setTratamiento(texts);
    }

    crearParametrosAnaliticos.setIndicacionQr(ui->indicacionQrComboBox->currentText());
    crearParametrosAnaliticos.setEuroScore(ui->euroScoreLineEdit->text());

    visita.setCita(crearCita);
    visita.setParametrosAnaliticos(crearParametrosAnaliticos);

    QSqlError err = citaDB.insertCita(getNumeroHistoria(),visita);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();

}

QList<VisitBean>  AddVisit::returnVisits(QString nHistoria){
    QList<VisitBean> myVisits = citaDB.readCita(nHistoria);
    return myVisits;
}

void AddVisit::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

QString AddVisit::getNumeroHistoria() const
{
    return numeroHistoria;
}

void AddVisit::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}
