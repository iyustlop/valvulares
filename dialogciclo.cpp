#include "dialogciclo.h"
#include "ui_dialogciclo.h"
#include "bean/ciclo/ciclobean.h"

#include <QMessageBox>

DialogCiclo::DialogCiclo(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCiclo)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogCiclo::~DialogCiclo()
{
    delete ui;
}

QString DialogCiclo::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogCiclo::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogCiclo::on_pushButtonCicloGuardar_clicked()
{
    CicloBean myCicloBean;

    myCicloBean.setFechaCiclo(ui->dateEditCicloFecha->text());
    myCicloBean.setVo2Indexado(ui->lineEditCicloVo2Indexado->text());
    myCicloBean.setVo2PicoPredicho(ui->lineEditCicloVo2Picopre->text());
    myCicloBean.setRer(ui->lineEditCicloRer->text());
    myCicloBean.setVo2enVa(ui->lineEditCicloVo2enVa->text());
    myCicloBean.setEqCo2enVa(ui->lineEditCicloEqCo2enVa->text());
    myCicloBean.setVslopeCo2(ui->lineEditCicloVslope->text());
    myCicloBean.setOues(ui->lineEditCicloOues->text());
    myCicloBean.setReservVentilatoria(ui->lineEditCicloReserVent->text());

    if (ui->radioButtonCiclo->isChecked()){
        myCicloBean.setModalidad("CicloErgometro");
    }
    else{
        myCicloBean.setModalidad("Tapiz Rodante");
    }

    if (ui->radioButtonAplanada->isChecked()){
        myCicloBean.setMorfCurva("Aplanada");
    }
    else{
        myCicloBean.setMorfCurva("No Aplanada");
    }

    if (ui->radioButtonCicloSi->isChecked()){
        myCicloBean.setVentOscilante("Si");
    }
    else{
        myCicloBean.setVentOscilante("No");
    }

    QSqlError err = insertCiclo.insertCiclo(getNumeroHistoria(),myCicloBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogCiclo::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}


void DialogCiclo::on_radioButtonCiclo_clicked()
{
    if(ui->radioButtonTapiz->isChecked()){
        ui->radioButtonTapiz->setChecked(false);
    }
}

void DialogCiclo::on_radioButtonTapiz_clicked()
{
    if(ui->radioButtonCiclo->isChecked()){
        ui->radioButtonCiclo->setChecked(false);
    }
}

void DialogCiclo::on_radioButtonAplanada_clicked()
{
    if(ui->radioButtonNoAplanada->isChecked()){
        ui->radioButtonNoAplanada->setChecked(false);
    }
}

void DialogCiclo::on_radioButtonNoAplanada_clicked()
{
    if(ui->radioButtonAplanada->isChecked()){
        ui->radioButtonAplanada->setChecked(false);
    }
}

void DialogCiclo::on_radioButtonCicloSi_clicked()
{
    if(ui->radioButtonCicloSi->isChecked()){
        ui->radioButtonCicloSi->setChecked(false);
    }
}

void DialogCiclo::on_radioButtonCicloNo_clicked()
{
    if(ui->radioButtonCicloNo->isChecked()){
        ui->radioButtonCicloNo->setChecked(false);
    }
}
