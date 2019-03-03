#ifndef DIALOGANILLO_H
#define DIALOGANILLO_H

#include <QDialog>
#include "db/anillodb.h"

namespace Ui {
class DialogAnillo;
}

class DialogAnillo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAnillo(QString numeroHistoria,QWidget *parent = 0);
    ~DialogAnillo();
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);

private slots:
    void on_pushButtonProtMec_clicked();

private:
    Ui::DialogAnillo *ui;
    AnilloDb insertAnilloDb;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGANILLO_H
