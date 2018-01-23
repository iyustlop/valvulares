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
    ecoDb insertEcoDb;

    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonGuardar_clicked();

private:
    Ui::EcoDialog *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // ECODIALOG_H
