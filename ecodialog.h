#ifndef ECODIALOG_H
#define ECODIALOG_H

#include <QDialog>

namespace Ui {
class EcoDialog;
}

class EcoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EcoDialog(QString numeroHistoria, QWidget *parent = 0);
    ~EcoDialog();

private:
    Ui::EcoDialog *ui;
};

#endif // ECODIALOG_H
