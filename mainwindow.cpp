#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initdb.h"
#include "patient.h"

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
        ui->protesisComboBox->addItem("Biológica Aórtica");
        ui->protesisComboBox->addItem("Biológica Mitral");
        ui->protesisComboBox->addItem("Anillo Mitral");
        ui->protesisComboBox->addItem("Anillo Tricuspide");
    }
    else{
        ui->causaComboBox->clear();
        ui->protesisComboBox->clear();
    }
}

void MainWindow::on_combinadaComboBox_activated(const QString &arg1)
{
    if (arg1 == "Si") {
        ui->listWidgetPatologiaValvularCombinada->clear();
        ui->listWidgetPatologiaValvularCombinada->addItem("EM");
        ui->listWidgetPatologiaValvularCombinada->addItem("IM");
        ui->listWidgetPatologiaValvularCombinada->addItem("EAO");
        ui->listWidgetPatologiaValvularCombinada->addItem("IAO");
        ui->listWidgetPatologiaValvularCombinada->addItem("ET");
        ui->listWidgetPatologiaValvularCombinada->addItem("IT");
        ui->listWidgetPatologiaValvularCombinada->addItem("EP");
        ui->listWidgetPatologiaValvularCombinada->addItem("IP");
    }
    else{
        ui->listWidgetPatologiaValvularCombinada->clear();
    }
}

void MainWindow::on_pushButtonCreate_clicked()
{
    Person crearPersona;
    Etiology crearEtiologia;
    ProtesicDisfunction disfuncionProtesica;
    Patient crearPaciente;
    QList<QListWidgetItem*> itemSelected;

    crearPersona.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));
    crearEtiologia.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));

    crearPersona.setNombre(comprobarLineEdit(ui->lineEditNombre->text()));

    crearPersona.setApellidos(comprobarLineEdit(ui->lineEditApellidos->text()));

    crearPersona.setFechaNacimiento(ui->dateEditBirthDate->text());

    if (ui->radioButtonHombre->isChecked()){
        crearPersona.setGenero("Hombre");
    }
    else{
        crearPersona.setGenero("Mujer");
    }
    if (ui->comboBox->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Etiologia ");
        return;
    }
    else{
        crearEtiologia.setEtiologia(ui->comboBox->currentText());
    }

    if (ui->comboBoxCausa->currentIndex() == -1){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Causa ");
        return;
    }
    else{
        crearEtiologia.setCausa(ui->comboBoxCausa->currentText());
    }

    if (ui->comboBoxPatologiaValvular->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Patologia Valvular ");
        return;
    }
    else{
        crearEtiologia.setPatologiaValvular(ui->comboBoxPatologiaValvular->currentText());
    }
    if (ui->combinadaComboBox->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Combinada ");
        return;
    }
    else{
        crearEtiologia.setMixedVpatology(ui->combinadaComboBox->currentText());
    }

    if (ui->listWidgetPatologiaValvularCombinada->selectedItems().isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Combinada ");
        return;
    }
    else{

        itemSelected = ui->listWidgetPatologiaValvularCombinada->selectedItems();

        QString texts;
        foreach (QListWidgetItem *item, itemSelected) {
            texts.append(item->text());
            texts.append(";");
        }

        crearEtiologia.setValvularPatologySecondary(texts);
    }

    if (ui->comboBoxPatologiaValvular->currentText() == "Disfunción Protésica"){

        disfuncionProtesica = crearEtiologia.getDisfuncionProtesica();

        disfuncionProtesica.setCausa(ui->causaComboBox->currentText());
        disfuncionProtesica.setProtesis(ui->protesisComboBox->currentText());
        disfuncionProtesica.setModelo(ui->modeloLineEdit->text());
        disfuncionProtesica.setNumero(ui->nMeroLineEdit->text());
        disfuncionProtesica.setFechaCirugia(ui->dateEditSugeryDate->text());

        crearEtiologia.setDisfuncionProtesica(disfuncionProtesica);
    }

    crearPaciente.setPersona(crearPersona);
    crearPaciente.setEtiologia(crearEtiologia);

    QSqlError err = valvularesDB.insertDB(crearPaciente);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    clearUi();
}

void MainWindow::on_createDatePushButton_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    Patient insertarPaciente;
    Etiology insertarEtiologia;
    ProtesicDisfunction insertarDisfucionProtesica;
    Person insertarPersona;

    QString queryId;

    queryId = ui->lineEditNumeroHistoria->text();

    insertarPaciente = valvularesDB.readDB(queryId);

    insertarPersona = insertarPaciente.getPersona();
    insertarEtiologia = insertarPaciente.getEtiologia();
    insertarDisfucionProtesica = insertarEtiologia.getDisfuncionProtesica();

    QDate fechaNacimiento = QDate::fromString(insertarPersona.getFechaNacimiento(),"dd/MM/yyyy");
    QDate fechaCirugia    = QDate::fromString(insertarDisfucionProtesica.getFechaCirugia(),"dd/MM/yyyy");

    ui->lineEditNombre->setText(insertarPersona.getNombre());
    ui->lineEditApellidos->setText(insertarPersona.getApellidos());
    ui->dateEditBirthDate->setDate(fechaNacimiento);
    if (insertarPersona.getGenero() == "Hombre"){
        ui->radioButtonHombre->setChecked(true);
    }
    else{
        ui->radioButtonMujer->setChecked(true);
    }
    ui->comboBox->setCurrentText(insertarEtiologia.getEtiologia());
    on_comboBox_activated(insertarEtiologia.getEtiologia());
    ui->comboBoxCausa->setCurrentText(insertarEtiologia.getCausa());
    ui->comboBoxPatologiaValvular->setCurrentText(insertarEtiologia.getPatlogiaValvular());
    ui->combinadaComboBox->setCurrentText(insertarEtiologia.getMixedVpatology());
    on_comboBoxPatologiaValvular_activated(insertarEtiologia.getPatlogiaValvular());
    on_combinadaComboBox_activated(insertarEtiologia.getMixedVpatology());
    //ui->comboBoxPatologiaValvularCombinada->setCurrentText(insertarEtiologia.getValvularPatologySecondary());
    ui->causaComboBox->setCurrentText(insertarDisfucionProtesica.getCausa());
    ui->protesisComboBox->setCurrentText(insertarDisfucionProtesica.getProtesis());
    ui->modeloLineEdit->setText(insertarDisfucionProtesica.getModelo());
    ui->nMeroLineEdit->setText(insertarDisfucionProtesica.getNumero());
    ui->dateEditSugeryDate->setDate(fechaCirugia);

}

void MainWindow::on_pushButtonUpdate_clicked()
{
    Patient updatePaciente;
    Person updatePersona;
    Etiology updateEtiologia;
    ProtesicDisfunction updateDisfuncionProtesica;

    updatePersona.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));
    updateEtiologia.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));

    updatePersona.setNombre(comprobarLineEdit(ui->lineEditNombre->text()));

    updatePersona.setApellidos(comprobarLineEdit(ui->lineEditApellidos->text()));

    updatePersona.setFechaNacimiento(ui->dateEditBirthDate->text());

    if (ui->radioButtonHombre->isChecked()){
        updatePersona.setGenero("Hombre");
    }
    else{
        updatePersona.setGenero("Mujer");
    }
    if (ui->comboBox->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Etiologia ");
        return;
    }
    else{
        updateEtiologia.setEtiologia(ui->comboBox->currentText());
    }

    if (ui->comboBoxCausa->currentIndex() == -1){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Causa ");
        return;
    }
    else{
        updateEtiologia.setCausa(ui->comboBoxCausa->currentText());
    }

    if (ui->comboBoxPatologiaValvular->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Patologia Valvular ");
        return;
    }
    else{
        updateEtiologia.setPatologiaValvular(ui->comboBoxPatologiaValvular->currentText());
    }
    if (ui->combinadaComboBox->currentIndex() == 0){
        QMessageBox::critical(this, "Unable to insert in Database",
                "Error insert in Combinada ");
        return;
    }
    else{
        updateEtiologia.setMixedVpatology(ui->combinadaComboBox->currentText());
    }

  //  updateEtiologia.setValvularPatologySecondary(ui->comboBoxPatologiaValvularCombinada->currentText());

    if (ui->comboBoxPatologiaValvular->currentText() == "Disfunción Protésica"){

        updateDisfuncionProtesica = updateEtiologia.getDisfuncionProtesica();

        updateDisfuncionProtesica.setCausa(ui->causaComboBox->currentText());
        updateDisfuncionProtesica.setProtesis(ui->protesisComboBox->currentText());
        updateDisfuncionProtesica.setModelo(ui->modeloLineEdit->text());
        updateDisfuncionProtesica.setNumero(ui->nMeroLineEdit->text());
        updateDisfuncionProtesica.setFechaCirugia(ui->dateEditSugeryDate->text());

        updateEtiologia.setDisfuncionProtesica(updateDisfuncionProtesica);
    }

    updatePaciente.setPersona(updatePersona);
    updateEtiologia.setDisfuncionProtesica(updateDisfuncionProtesica);
    updatePaciente.setEtiologia(updateEtiologia);

    QSqlError err = valvularesDB.updateDB(updatePaciente);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    clearUi();
}

void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

void MainWindow::clearUi()
{
    ui->lineEditNombre->clear();
    ui->lineEditApellidos->clear();
    ui->lineEditNumeroHistoria->clear();
    ui->dateEditBirthDate->setDate(QDate::currentDate());
    ui->comboBox->setCurrentIndex(0);
    ui->comboBoxCausa->clear();
    ui->comboBoxPatologiaValvular->setCurrentIndex(0);
    ui->combinadaComboBox->setCurrentIndex(0);
    ui->listWidgetPatologiaValvularCombinada->clear();
    ui->radioButtonHombre->setAutoExclusive(false);
    ui->radioButtonHombre->setChecked(false);
    ui->radioButtonMujer->setAutoExclusive(false);
    ui->radioButtonMujer->setChecked(false);
    ui->protesisComboBox->clear();
    ui->causaComboBox->clear();
    ui->modeloLineEdit->clear();
    ui->nMeroLineEdit->clear();
    ui->dateEditSugeryDate->setDate(QDate::currentDate());
}

QString MainWindow::comprobarLineEdit(QString lineEdit)
{
    if (lineEdit.isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database","Error insert in Nombre ");
            return "Vacio";
        }
        else{
            return lineEdit;
        }
}
