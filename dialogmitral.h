#ifndef DIALOGMITRAL_H
#define DIALOGMITRAL_H

#include <QDialog>
#include "db/mitraldb.h"

namespace Ui {
class DialogMitral;
}

class DialogMitral : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMitral(QString numeroHistoria, QWidget *parent = 0);
    ~DialogMitral();

    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonMitral_clicked();

private:
    Ui::DialogMitral *ui;
    MitralDb mitralDb;
    QString numeroHistoria;
    void showError(const QSqlError &err);

};

#endif // DIALOGMITRAL_H
