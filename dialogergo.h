#ifndef DIALOGERGO_H
#define DIALOGERGO_H

#include <QDialog>
#include <db/ergodb.h>

namespace Ui {
class DialogErgo;
}

class DialogErgo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogErgo(QString numeroHistoria, QWidget *parent = 0);
    ~DialogErgo();
    QString getNumeroHistoria() const;
    void setNumeroHistoria(const QString &value);
private slots:
    void on_pushButtonErgoGuardar_clicked();

private:
    ErgoDb insertErgoDB;
    Ui::DialogErgo *ui;
    QString numeroHistoria;
    void showError(const QSqlError &err);
};

#endif // DIALOGERGO_H
