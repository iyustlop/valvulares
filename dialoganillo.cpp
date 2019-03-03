#include "dialoganillo.h"
#include "ui_dialoganillo.h"
#include "bean/protesis/anillobean.h"

#include <QMessageBox>

DialogAnillo::DialogAnillo(QString numeroHistoria,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAnillo)
{
    ui->setupUi(this);
    this->setWindowTitle("Numero de historia:"+numeroHistoria);
    setNumeroHistoria(numeroHistoria);
}

DialogAnillo::~DialogAnillo()
{
    delete ui;
}

QString DialogAnillo::getNumeroHistoria() const
{
    return numeroHistoria;
}

void DialogAnillo::setNumeroHistoria(const QString &value)
{
    numeroHistoria = value;
}

void DialogAnillo::on_pushButtonProtMec_clicked()
{
    AnilloBean myAnilloBean;
    myAnilloBean.setDateAnillo(ui->dateEditAnillo->text());
    myAnilloBean.setTipoAnillo(ui->lineEditTipo->text());
    myAnilloBean.setGradiente(ui->lineEditGradiente->text());
    myAnilloBean.setLeak(ui->lineEditLeak->text());

    QSqlError err = insertAnilloDb.insertAnilloDb(getNumeroHistoria(),myAnilloBean);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    close();
}

void DialogAnillo::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}


