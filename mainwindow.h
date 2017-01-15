#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "initdb.h"

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

private slots:
    void on_pushButtonCreate_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButtonUpdate_clicked();

    void on_comboBoxPatologiaValvular_activated(const QString &arg1);

    void on_combinadaComboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void showError(const QSqlError &err);
    void clearUi();
};

#endif // MAINWINDOW_H
