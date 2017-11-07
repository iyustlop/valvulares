#ifndef ADDVISIT_H
#define ADDVISIT_H

#include <QDialog>

#include <db/initdbcita.h>

namespace Ui {
class AddVisit;
}

class AddVisit : public QDialog
{
    Q_OBJECT

public:
    explicit AddVisit(QString numeroHistoria, QWidget *parent = 0);
    ~AddVisit();
    initDBCita citaDB;

    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonCancelar_clicked();

    void on_pushButtonGuardar_clicked();

private:
    Ui::AddVisit *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // ADDVISIT_H
