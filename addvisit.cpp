#include "addvisit.h"
#include "ui_addvisit.h"
#include "cita/cita.h"
#include "cita/parametrosanaliticos.h"

#include <QMessageBox>

AddVisit::AddVisit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVisit)
{
    ui->setupUi(this);
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
    Cita crearCita;
    ParametrosAnaliticos parametrosAnaliticos;
    QList<QListWidgetItem*> itemSelected;

    crearCita.setFechaConsulta(ui->fechaConsultaDateEdit->text());
    crearCita.setRitmo(ui->ritmoComboBox->currentText());
    crearCita.setGradoFuncional(ui->gradoFuncionalComboBox->currentText());

    if (ui->listWidgetFRCV->selectedItems().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                              "Error insert in Combinada ");
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

    parametrosAnaliticos.setHB(ui->hBLineEdit->text());
    parametrosAnaliticos.setCreatinina(ui->creatininaLineEdit->text());
    parametrosAnaliticos.setFG(ui->fGLineEdit->text());
    parametrosAnaliticos.setProBNP(ui->potasioLineEdit->text());
    parametrosAnaliticos.setPotasio(ui->potasioLineEdit->text());

    if (ui->listWidgetTratamiento->selectedItems().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                              "Error insert in Combinada ");
        return;
    }
    else{

        itemSelected = ui->listWidgetTratamiento->selectedItems();

        QString texts;
        foreach (QListWidgetItem *item, itemSelected) {
            texts.append(item->text());
            texts.append(";");
        }

        parametrosAnaliticos.setTratamiento(texts);
    }

    parametrosAnaliticos.setIndicacionQr(ui->indicacionQrComboBox->currentText());
    parametrosAnaliticos.setEuroScore(ui->euroScoreLineEdit->text());

    close();
}
