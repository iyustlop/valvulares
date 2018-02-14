#ifndef DIALOGAORTA_H
#define DIALOGAORTA_H

#include <QDialog>
#include "db/aortadb.h"

namespace Ui {
class DialogAorta;
}

class DialogAorta : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAorta(QString numeroHistoria,QWidget *parent = 0);
    ~DialogAorta();

    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonAorta_clicked();

private:
    AortaDb inserAortaDb;
    Ui::DialogAorta *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGAORTA_H
