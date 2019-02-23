#ifndef DIALOGRESONANCIA_H
#define DIALOGRESONANCIA_H

#include <QDialog>
#include <db/resonanciadb.h>

namespace Ui {
class DialogResonancia;
}

class DialogResonancia : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResonancia(QString numeroHistoria, QWidget *parent = 0);
    ~DialogResonancia();
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonGuardar_clicked();


    void on_pushButtonResoGuardar_clicked();
    void on_radioButtonResoDiViSi_clicked();
    void on_radioButtonResoDiViNo_clicked();
    void on_radioButtonResoDiVdSi_clicked();
    void on_radioButtonResoDiVdNo_clicked();

private:
    ResonanciaDb insertResonancia;
    Ui::DialogResonancia *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGRESONANCIA_H
