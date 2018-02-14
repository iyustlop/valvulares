#ifndef DIALOGTRI_H
#define DIALOGTRI_H

#include <QDialog>
#include "db/tridb.h"

namespace Ui {
class DialogTri;
}

class DialogTri : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTri(QString numeroHistoria,QWidget *parent = 0);
    ~DialogTri();

    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonTri_clicked();

private:
    Ui::DialogTri *ui;
    TriDb insertTriDb;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGTRI_H
