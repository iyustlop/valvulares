#ifndef DIALOGPROTESISBIOLOGICA_H
#define DIALOGPROTESISBIOLOGICA_H

#include <QDialog>
#include "db/protesisbiologicadb.h"

namespace Ui {
class DialogProtesisBiologica;
}

class DialogProtesisBiologica : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProtesisBiologica(QString numeroHistoria,QWidget *parent = 0);
    ~DialogProtesisBiologica();
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonProtBiolog_clicked();

private:
    Ui::DialogProtesisBiologica *ui;
    ProtesisBiologicaDb insertProtesisBiologicaDb;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGPROTESISBIOLOGICA_H
