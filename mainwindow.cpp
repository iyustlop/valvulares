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

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if (arg1 == "Primaria") {
        ui->comboBoxCausa->clear();
        ui->comboBoxCausa->addItem("Reumática");
        ui->comboBoxCausa->addItem("Degenerativa");
        ui->comboBoxCausa->addItem("Mixomatosa");
        ui->comboBoxCausa->addItem("Endocarditis");
        ui->comboBoxCausa->addItem("Bicúspide");
        ui->comboBoxCausa->addItem("Traumática");
        ui->comboBoxCausa->addItem("Farmacos");
        ui->comboBoxCausa->addItem("Radioterapia");
    }
    if (arg1 == "Secundaria"){
        ui->comboBoxCausa->clear();
        ui->comboBoxCausa->addItem("Dilatacion R. Ao");
        ui->comboBoxCausa->addItem("Isquémico");
        ui->comboBoxCausa->addItem("Dilatacion Anillo");
        ui->comboBoxCausa->addItem("Dilatacion Ao");
    }
}

void MainWindow::on_comboBoxPatologiaValvular_activated(const QString &arg1)
{
    if (arg1 == "Disfunción Protésica") {
        ui->causaComboBox->clear();
        ui->protesisComboBox->clear();
        ui->causaComboBox->addItem("Trombosis");
        ui->causaComboBox->addItem("Leak");
        ui->causaComboBox->addItem("Endocarditis");
        ui->causaComboBox->addItem("Pannus");
        ui->causaComboBox->addItem("Mismatch");
        ui->protesisComboBox->addItem("Mecánica Aórtica");
        ui->protesisComboBox->addItem("Mecánica Mitral");
        ui->protesisComboBox->addItem("Mecánica Aórtica");
        ui->protesisComboBox->addItem("Mecánica Mitral");
        ui->protesisComboBox->addItem("Mecánica Mitral");
        ui->protesisComboBox->addItem("Mecánica Tricuspide");
    }
    else{
        ui->causaComboBox->clear();
        ui->protesisComboBox->clear();
    }
}

void MainWindow::on_combinadaComboBox_activated(const QString &arg1)
{
    if (arg1 == "Si") {
        ui->comboBoxPatologiaValvularCombinada->clear();
        ui->comboBoxPatologiaValvularCombinada->addItem("EM");
        ui->comboBoxPatologiaValvularCombinada->addItem("IM");
        ui->comboBoxPatologiaValvularCombinada->addItem("EAO");
        ui->comboBoxPatologiaValvularCombinada->addItem("IAO");
        ui->comboBoxPatologiaValvularCombinada->addItem("ET");
        ui->comboBoxPatologiaValvularCombinada->addItem("IT");
        ui->comboBoxPatologiaValvularCombinada->addItem("EP");
        ui->comboBoxPatologiaValvularCombinada->addItem("IP");
    }
    else{
        ui->comboBoxPatologiaValvularCombinada->clear();
    }
}

void MainWindow::on_pushButtonCreate_clicked()
{
    Patient crearPaciente;

    if (ui->lineEditNumeroHistoria->text().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Numero Historia ");
        return;
    }
    else{
        crearPaciente.setNumeroHistoria(ui->lineEditNumeroHistoria->text());
    }

    if (ui->lineEditNombre->text().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Nombre ");
        return;
    }
    else{
        crearPaciente.setNombre(ui->lineEditNombre->text());
    }

    if (ui->lineEditApellidos->text().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Apellidos ");
        return;
    }
    else{
        crearPaciente.setApellidos(ui->lineEditApellidos->text());
    }

    if (ui->radioButtonHombre->isChecked()){
        crearPaciente.setGenero("Hombre");
    }
    else{
        crearPaciente.setGenero("Mujer");
    }
    if (ui->comboBox->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Etiologia ");
        return;
    }
    else{
        crearPaciente.setEtiologia(ui->comboBox->currentText());
    }

    if (ui->comboBoxCausa->currentIndex() == -1){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Causa ");
        return;
    }
    else{
        crearPaciente.setCausa(ui->comboBoxCausa->currentText());
    }

    if (ui->comboBoxPatologiaValvular->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Apellidos ");
        return;
    }
    else{
        crearPaciente.setPatologiaValvular(ui->comboBoxPatologiaValvular->currentText());
    }

    QSqlError err = valvularesDB.insertDB(crearPaciente);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    ui->lineEditNombre->clear();
    ui->lineEditApellidos->clear();
    ui->lineEditNumeroHistoria->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBoxCausa->clear();
    ui->comboBoxPatologiaValvular->setCurrentIndex(0);

}

void MainWindow::on_pushButton_clicked()
{
    Patient insertarPaciente;
    QString queryId;

    queryId = ui->lineEditNumeroHistoria->text();

    insertarPaciente = valvularesDB.readDB(queryId);

    ui->lineEditNombre->setText(insertarPaciente.getNombre());
    ui->lineEditApellidos->setText(insertarPaciente.getApellidos());
    if (insertarPaciente.getGenero() == "Hombre"){
        ui->radioButtonHombre->setChecked(true);
    }
    else{
        ui->radioButtonMujer->setChecked(true);
    }
    ui->comboBox->setCurrentText(insertarPaciente.getEtiologia());
    on_comboBox_activated(insertarPaciente.getEtiologia());
    ui->comboBoxCausa->setCurrentText(insertarPaciente.getCausa());
    ui->comboBoxPatologiaValvular->setCurrentText(insertarPaciente.getPatlogiaValvular());

}

void MainWindow::on_pushButtonUpdate_clicked()
{
    Patient updatePaciente;

    if (ui->lineEditNumeroHistoria->text().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Numero Historia ");
        return;
    }
    else{
        updatePaciente.setNumeroHistoria(ui->lineEditNumeroHistoria->text());
    }

    if (ui->lineEditNombre->text().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Nombre ");
        return;
    }
    else{
        updatePaciente.setNombre(ui->lineEditNombre->text());
    }

    if (ui->lineEditApellidos->text().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Apellidos ");
        return;
    }
    else{
        updatePaciente.setApellidos(ui->lineEditApellidos->text());
    }

    if (ui->radioButtonHombre->isChecked()){
        updatePaciente.setGenero("Hombre");
    }
    else{
        updatePaciente.setGenero("Mujer");
    }
    if (ui->comboBox->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Etiologia ");
        return;
    }
    else{
        updatePaciente.setEtiologia(ui->comboBox->currentText());
    }

    if (ui->comboBoxCausa->currentIndex() == -1){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Causa ");
        return;
    }
    else{
        updatePaciente.setCausa(ui->comboBoxCausa->currentText());
    }

    if (ui->comboBoxPatologiaValvular->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Apellidos ");
        return;
    }
    else{
        updatePaciente.setPatologiaValvular(ui->comboBoxPatologiaValvular->currentText());
    }

    QSqlError err = valvularesDB.updateDB(updatePaciente);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    ui->lineEditNombre->clear();
    ui->lineEditApellidos->clear();
    ui->lineEditNumeroHistoria->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBoxCausa->clear();
    ui->comboBoxPatologiaValvular->setCurrentIndex(0);
}

void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}
