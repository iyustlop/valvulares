#ifndef DIALOGAORTA_H
#define DIALOGAORTA_H

#include <QDialog>

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

private:
    Ui::DialogAorta *ui;
    QString numeroHistoria;
};

#endif // DIALOGAORTA_H
