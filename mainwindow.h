#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "db/initdb.h"
#include "db/ecodb.h"
#include "db/ergodb.h"
#include "db/resonanciadb.h"
#include "db/ciclodb.h"
#include "db/pacientedb.h"
#include "db/citadb.h"
#include "db/mitraldb.h"
#include "db/aortadb.h"
#include "db/tridb.h"
#include "db/protesisbiologicadb.h"
#include "display/displayciclo.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getNumeroHistoria();
    void clearUi();

    void displayCitaInTw(ParametrosAnaliticos insertarParametros, Cita insertarCita, QList<VisitBean> insertarVisita);
    void displayCicloInTW(QList<CicloBean> insertarCicloBean);
    void displayResoInTw(QList<ResonanciaBean> insertarResoBean);
    void displayEcoInTw(QList<ecoBean> insertarEcoBean);
    void displayErgoInTw(QList<ErgoBean> insertarErgoBean);

    void displayMitralInTw(QList<MitralBean> insertarMitral);
    void displayAortaInTw(QList<AortaBean> insertarAorta);
    void displayTriInTw(QList<TriBean> insertarTri);
    void displayProtesisBioInTw(QList<ProtesisBiologicaBean> insertarProtesisBio);


private slots:
    void on_pushButtonCreate_clicked();
    void on_pushButtonRead_clicked();
    void on_pushButtonClear_clicked();
    void on_pushButtonUpdate_clicked();

    void on_pushButtonCita_clicked();
    void on_pushButtonEco_clicked();
    void on_pushButtonResonancia_clicked();
    void on_pushButtonCiclo_clicked();

    void on_comboBox_activated(const QString &arg1);
    void on_comboBoxPatologiaValvular_activated(const QString &arg1);
    void on_combinadaComboBox_activated(const QString &arg1);

    void on_pushButtonMitral_clicked();
    void on_pushButtonAorta_clicked();
    void on_pushButtonTri_clicked();


    void on_pushButtonErgo_clicked();


    void on_pushButtonProtesisBio_clicked();

private:
    InitDb valvularesDb;
    PacienteDb myPacienteDb;
    CitaDb myVisitaDb;
    EcoDb myEcoDb;
    ResonanciaDb myResonanciaDb;
    CicloDb myCicloDb;
    ErgoDb myErgoDb;
    MitralDb myMitralDb;
    AortaDb myAortaDb;
    TriDb myTriDb;
    ProtesisBiologicaDb myProtesisBiologicaDb;
    Ui::MainWindow *ui;
    void showError(const QSqlError &err);
    QString comprobarLineEdit(QString lineEdit);

};

#endif // MAINWINDOW_H
