#ifndef ECODIALOG_H
#define ECODIALOG_H

#include <QDialog>
#include <db/ecodb.h>

namespace Ui {
class EcoDialog;
}

class EcoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EcoDialog(QString numeroHistoria, QWidget *parent = 0);
    ~EcoDialog();    
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonGuardar_clicked();

    void on_radioButtonDiVdNo_clicked();
    void on_radioButtonDiVdSi_clicked();
    void on_radioButtonDiViNo_clicked();
    void on_radioButtonDiViSi_clicked();

private:
    EcoDb insertEcoDb;
    Ui::EcoDialog *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // ECODIALOG_H
