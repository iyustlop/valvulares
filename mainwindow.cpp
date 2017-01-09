#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initdb.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!QSqlDatabase::drivers().contains("QSQLITE"))
            QMessageBox::critical(this, "Unable to load database", "This demo needs the SQLITE driver");

        // initialize the database
        QSqlError err = valvularesDB.startDb();
        if (err.type() != QSqlError::NoError) {
            showError(err);
            return;
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

void MainWindow::on_pushButtonCreate_clicked()
{
Patient crearPaciente;

if (ui->lineEditNumeroHistoria->text().isEmpty()){
    QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Numero Historia ");
}
else{
    crearPaciente.setNumeroHistoria(ui->lineEditNumeroHistoria->text());
}

if (ui->lineEditNombre->text().isEmpty()){
    QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Nombre ");
}
else{
    crearPaciente.setNombre(ui->lineEditNombre->text());
}

if (ui->lineEditApellidos->text().isEmpty()){
    QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Apellidos ");
}
else{
    crearPaciente.setApellidos(ui->lineEditApellidos->text());
}

QSqlError err = valvularesDB.insertDB(crearPaciente);
if (err.type() != QSqlError::NoError) {
    showError(err);
    return;
}
}
