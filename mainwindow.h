#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "db/initdb.h"
#include "db/ecodb.h"
#include "db/pacientedb.h"
#include "db/initdbcita.h"
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
    initDB valvularesDB;
    PacienteDB myPacienteDB;
    initDBCita myVisitaDB;
    ecoDb myEcoDB;
    QString getNumeroHistoria();
    void clearUi();

private slots:
    void on_pushButtonCreate_clicked();
    void on_comboBox_activated(const QString &arg1);
    void on_pushButton_clicked();
    void on_pushButtonUpdate_clicked();
    void on_comboBoxPatologiaValvular_activated(const QString &arg1);
    void on_combinadaComboBox_activated(const QString &arg1);
    void on_createDatePushButton_clicked();
    void on_pushButtonClear_clicked();

    void on_createEcoPushButton_clicked();

private:
    Ui::MainWindow *ui;
    void showError(const QSqlError &err);
    QString comprobarLineEdit(QString lineEdit);
};

#endif // MAINWINDOW_H
