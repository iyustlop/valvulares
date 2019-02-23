#ifndef DIALOGCICLO_H
#define DIALOGCICLO_H

#include <QDialog>
#include <db/ciclodb.h>

namespace Ui {
class DialogCiclo;
}

class DialogCiclo : public QDialog
{
    Q_OBJECT
public:
    explicit DialogCiclo(QString numeroHistoria, QWidget *parent = 0);
    ~DialogCiclo();
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonCicloGuardar_clicked();

    void on_radioButtonCiclo_clicked();

    void on_radioButtonTapiz_clicked();

    void on_radioButtonAplanada_clicked();

    void on_radioButtonNoAplanada_clicked();

    void on_radioButtonCicloSi_clicked();

    void on_radioButtonCicloNo_clicked();

private:
    CicloDb insertCiclo;
    Ui::DialogCiclo *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGCICLO_H
