#ifndef ADDVISIT_H
#define ADDVISIT_H

#include <QDialog>

namespace Ui {
class AddVisit;
}

class AddVisit : public QDialog
{
    Q_OBJECT

public:
    explicit AddVisit(QWidget *parent = 0);
    ~AddVisit();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddVisit *ui;
};

#endif // ADDVISIT_H
