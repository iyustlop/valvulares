#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "db/initdb.h"
#include "bean/patientbean.h"
#include "addvisit.h"
#include "dialogeco.h"
#include "dialogmitral.h"
#include "dialogaorta.h"
#include "dialogtri.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();

    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        QMessageBox::critical(this, "Unable to load database", "This demo needs the SQLITE driver");

    // initialize the database
    QSqlError err = valvularesDb.startDb();
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
        ui->comboBoxCausa->addItem("Prolapso Idio");
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
    QList<QListWidgetItem*> itemSelected;
    PatientBean crearPaciente;

    crearPersona.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));
    crearEtiologia.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));

    crearPersona.setNombre(comprobarLineEdit(ui->lineEditNombre->text()));

    crearPersona.setApellidos(comprobarLineEdit(ui->lineEditApellidos->text()));

    crearPersona.setEdad(ui->lineEditAge->text());

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

    if (crearEtiologia.getMixedVpatology().compare("Si") == 0){
        if (ui->listWidgetPatologiaValvularCombinada->selectedItems().isEmpty()){
            QMessageBox::critical(this, "Unable to insert in Database",
                                  "Error insert in Patologia Valvular Combinada ");
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

    QSqlError err = myPacienteDb.insertDB(crearPaciente);
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    clearUi();
}


void MainWindow::on_pushButtonRead_clicked()
{
    PatientBean insertarPaciente;
    Etiology insertarEtiologia;    
    ProtesicDisfunction insertarDisfucionProtesica;
    Person insertarPersona;
    // lista de la vista.
    QList<VisitBean> insertarVisita;
    Cita insertarCita;
    ParametrosAnaliticos insertarParametros;
    // Lista del Eco.
    QList<ecoBean> insertarEcoBean;
    // Lista de Mitral
    QList<MitralBean> insertarMitral;
    // Lista de Aorta
    QList<AortaBean> insertarAorta;
    //Lista de tricuspide
    QList<TriBean> insertarTri;

    QString queryId;

    queryId = ui->lineEditNumeroHistoria->text();

    insertarPaciente = myPacienteDb.readDB(queryId);
    insertarVisita = myVisitaDb.readCita(queryId);
    insertarEcoBean = myEcoDb.readEco(queryId);
    insertarMitral = myMitralDb.readMitral(queryId);
    insertarAorta = myAortaDb.readAorta(queryId);
    insertarTri = myTriDb.readTri(queryId);

    insertarPersona = insertarPaciente.getPersona();
    insertarEtiologia = insertarPaciente.getEtiologia();
    insertarDisfucionProtesica = insertarEtiologia.getDisfuncionProtesica();

    QDate fechaCirugia    = QDate::fromString(insertarDisfucionProtesica.getFechaCirugia(),"dd/MM/yyyy");

    ui->lineEditNombre->setText(insertarPersona.getNombre());
    ui->lineEditApellidos->setText(insertarPersona.getApellidos());
    ui->lineEditAge->setText(insertarPersona.getEdad());
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

    ui->citasTableWidget->setRowCount(insertarVisita.length());

    for (int i = 0; i < insertarVisita.length();i++){

        VisitBean visitaIter = insertarVisita[i];
        insertarCita = visitaIter.getCita();
        insertarParametros = visitaIter.getParametrosAnaliticos();

        ui->citasTableWidget->setItem(i,0,new QTableWidgetItem(insertarCita.getFechaConsulta()));
        ui->citasTableWidget->setItem(i,1,new QTableWidgetItem(insertarCita.getRitmo()));
        ui->citasTableWidget->setItem(i,2,new QTableWidgetItem(insertarCita.getGradoFuncional()));
        ui->citasTableWidget->setItem(i,3,new QTableWidgetItem(insertarCita.getFrcv()));
        ui->citasTableWidget->setItem(i,4,new QTableWidgetItem(insertarParametros.getHB()));
        ui->citasTableWidget->setItem(i,5,new QTableWidgetItem(insertarParametros.getCreatinina()));
        ui->citasTableWidget->setItem(i,6,new QTableWidgetItem(insertarParametros.getFG()));
        ui->citasTableWidget->setItem(i,7,new QTableWidgetItem(insertarParametros.getProBNP()));
        ui->citasTableWidget->setItem(i,8,new QTableWidgetItem(insertarParametros.getPotasio()));
        ui->citasTableWidget->setItem(i,9,new QTableWidgetItem(insertarParametros.getIndicacionQr()));
        ui->citasTableWidget->setItem(i,10,new QTableWidgetItem(insertarParametros.getEuroScore()));
        ui->citasTableWidget->setItem(i,11,new QTableWidgetItem(insertarParametros.getTratamiento()));
    }

    ui->ecoTableWidget->setRowCount(insertarEcoBean.length());

    for (int i = 0; i < insertarEcoBean.length(); i++){
        ecoBean myEcoBean = insertarEcoBean[i];

        ui->ecoTableWidget->setItem(i,0,new QTableWidgetItem(myEcoBean.getFechaEco()));
        ui->ecoTableWidget->setItem(i,1,new QTableWidgetItem(myEcoBean.getVolAi()));
        ui->ecoTableWidget->setItem(i,2,new QTableWidgetItem(myEcoBean.getFevi()));
        ui->ecoTableWidget->setItem(i,3,new QTableWidgetItem(myEcoBean.getDilataVi()));
        ui->ecoTableWidget->setItem(i,4,new QTableWidgetItem(myEcoBean.getVtdVi()));
        ui->ecoTableWidget->setItem(i,5,new QTableWidgetItem(myEcoBean.getDilataVd()));
        ui->ecoTableWidget->setItem(i,6,new QTableWidgetItem(myEcoBean.getTapse()));
        ui->ecoTableWidget->setItem(i,7,new QTableWidgetItem(myEcoBean.getAoAscend()));
    }

    ui->tableWidgetMitral->setRowCount(insertarMitral.length());
    for (int i = 0; i < insertarMitral.length(); i++){
        MitralBean myMitralBean = insertarMitral[i];
        ui->tableWidgetMitral->setItem(i,0,new QTableWidgetItem(myMitralBean.getFecha()));
        ui->tableWidgetMitral->setItem(i,1,new QTableWidgetItem(myMitralBean.getGrdMedio()));
        ui->tableWidgetMitral->setItem(i,2,new QTableWidgetItem(myMitralBean.getAvmXtmp()));
        ui->tableWidgetMitral->setItem(i,3,new QTableWidgetItem(myMitralBean.getVOndaE()));
        ui->tableWidgetMitral->setItem(i,4,new QTableWidgetItem(myMitralBean.getORe()));
        ui->tableWidgetMitral->setItem(i,5,new QTableWidgetItem(myMitralBean.getVR()));
        ui->tableWidgetMitral->setItem(i,6,new QTableWidgetItem(myMitralBean.getVC()));
        ui->tableWidgetMitral->setItem(i,7,new QTableWidgetItem(myMitralBean.getInvSistolicaVvpp()));
    }

    ui->tableWidgetAorta->setRowCount(insertarAorta.length());
    for (int i = 0; i < insertarAorta.length(); i++){
        AortaBean myAortaBean = insertarAorta[i];
        ui->tableWidgetAorta->setItem(i,0,new QTableWidgetItem(myAortaBean.getDate()));
        ui->tableWidgetAorta->setItem(i,1,new QTableWidgetItem(myAortaBean.getGradAo()));
        ui->tableWidgetAorta->setItem(i,2,new QTableWidgetItem(myAortaBean.getGradMedioAo()));
        ui->tableWidgetAorta->setItem(i,3,new QTableWidgetItem(myAortaBean.getRelacionDeInl()));
        ui->tableWidgetAorta->setItem(i,4,new QTableWidgetItem(myAortaBean.getAreaAo()));
        ui->tableWidgetAorta->setItem(i,5,new QTableWidgetItem(myAortaBean.getOReIaO()));
        ui->tableWidgetAorta->setItem(i,6,new QTableWidgetItem(myAortaBean.getVRiAo()));
        ui->tableWidgetAorta->setItem(i,7,new QTableWidgetItem(myAortaBean.getVCiAo()));
        ui->tableWidgetAorta->setItem(i,8,new QTableWidgetItem(myAortaBean.getRelAltJetIao()));
        ui->tableWidgetAorta->setItem(i,9,new QTableWidgetItem(myAortaBean.getInversionIao()));
    }

    ui->tableWidgetTri->setRowCount(insertarTri.length());
    for (int i = 0; i < insertarTri.length(); i++){
        TriBean myTriBean = insertarTri[i];
        ui->tableWidgetTri->setItem(i,0,new QTableWidgetItem(myTriBean.getDateTri()));
        ui->tableWidgetTri->setItem(i,1,new QTableWidgetItem(myTriBean.getPsap()));
        ui->tableWidgetTri->setItem(i,2,new QTableWidgetItem(myTriBean.getGrado()));
    }
}

void MainWindow::on_pushButtonUpdate_clicked()
{
    PatientBean updatePaciente;
    Person updatePersona;
    Etiology updateEtiologia;
    ProtesicDisfunction updateDisfuncionProtesica;

    updatePersona.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));
    updateEtiologia.setNumeroHistoria(comprobarLineEdit(ui->lineEditNumeroHistoria->text()));

    updatePersona.setNombre(comprobarLineEdit(ui->lineEditNombre->text()));

    updatePersona.setApellidos(comprobarLineEdit(ui->lineEditApellidos->text()));

    updatePersona.setEdad(ui->lineEditAge->text());

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

    QSqlError err = valvularesDb.updateDB(updatePaciente);
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
    ui->lineEditAge->clear();
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

    ui->citasTableWidget->setRowCount(0);

    ui->ecoTableWidget->setRowCount(0);

    ui->tableWidgetMitral->setRowCount(0);

    ui->tableWidgetAorta->setRowCount(0);

    ui->tableWidgetTri->setRowCount(0);
}

QString MainWindow::comprobarLineEdit(QString lineEdit)
{
    if (lineEdit.isEmpty()){
        QMessageBox::critical(this, "Unable to insert in Database","Fill all the fields ");
        return "Vacio";
    }
    else{
        return lineEdit;
    }
}

void MainWindow::on_pushButtonCita_clicked()
{
    QList<VisitBean> listVist;
    QString numeroHistoria = comprobarLineEdit(ui->lineEditNumeroHistoria->text());
    AddVisit myAddVisit(numeroHistoria);

    int x = QString::compare(numeroHistoria,"Vacio");
    if (x == 0){

    } else{
        //myAddVisit.setModal(true);
        myAddVisit.exec();
        clearUi();
    }

    listVist = myAddVisit.returnVisits(numeroHistoria);
}

void MainWindow::on_pushButtonEco_clicked()
{
    QString numeroHistoria = comprobarLineEdit(ui->lineEditNumeroHistoria->text());
    DialogEco ecoDialog(numeroHistoria);
    int x = QString::compare(numeroHistoria,"Vacio");
    if (x == 0){

    } else{
        //myAddVisit.setModal(true);
        ecoDialog.exec();
        clearUi();
    }

}

void MainWindow::on_pushButtonClear_clicked()
{
    clearUi();

    ui->citasTableWidget->setRowCount(0);
}

QString MainWindow::getNumeroHistoria(){
    QString keyNumeroHistoria =  ui->lineEditNumeroHistoria->text();

    return keyNumeroHistoria;
}

void MainWindow::on_pushButtonMitral_clicked()
{
    QString numeroHistoria = comprobarLineEdit(ui->lineEditNumeroHistoria->text());
    DialogMitral dialogMitral(numeroHistoria);

    int x = QString::compare(numeroHistoria,"Vacio");
    if (x == 0){

    } else{
        //myAddVisit.setModal(true);
        dialogMitral.exec();
        clearUi();
    }
}

void MainWindow::on_pushButtonAorta_clicked()
{
    QString numeroHistoria = comprobarLineEdit(ui->lineEditNumeroHistoria->text());
    DialogAorta dialogAorta(numeroHistoria);
    int x = QString::compare(numeroHistoria,"Vacio");
    if (x == 0){

    } else{
        //myAddVisit.setModal(true);
        dialogAorta.exec();
        clearUi();
    }
}

void MainWindow::on_pushButtonTri_clicked()
{
    QString numeroHistoria = comprobarLineEdit(ui->lineEditNumeroHistoria->text());
    DialogTri dialogTri(numeroHistoria);
    int x = QString::compare(numeroHistoria,"Vacio");
    if (x == 0){

    } else{
        //myAddVisit.setModal(true);
        dialogTri.exec();
        clearUi();
    }
}
