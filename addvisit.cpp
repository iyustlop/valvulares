#include "addvisit.h"
#include "ui_addvisit.h"
#include "cita.h"
#include "parametrosanaliticos.h"

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

    crearCita.setFechaConsulta(ui->fechaConsultaDate->text());
    crearCita.setRitmo(ui->ritmoComboBox->currentText());
    crearCita.setFechaConsulta(ui->gradoFuncionalComboBox->currentText());
    //crearCita.setFrcv(ui->);

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

    close();
}
