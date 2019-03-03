#ifndef DIALOGPROTESISMECANICA_H
#define DIALOGPROTESISMECANICA_H

#include <QDialog>
#include "db/protesismecanicadb.h"

namespace Ui {
class DialogProtesisMecanica;
}

class DialogProtesisMecanica : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProtesisMecanica(QString numeroHistoria,QWidget *parent = 0);
    ~DialogProtesisMecanica();
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonProtMec_clicked();

private:
    Ui::DialogProtesisMecanica *ui;
    ProtesisMecanicaDb insertProtesisMecanicaaDb;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGANILLO_H
