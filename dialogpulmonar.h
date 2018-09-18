#ifndef DIALOGPULMONAR_H
#define DIALOGPULMONAR_H

#include <QDialog>

namespace Ui {
class DialogPulmonar;
}

class DialogPulmonar : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPulmonar(QWidget *parent = 0);
    ~DialogPulmonar();

private:
    Ui::DialogPulmonar *ui;
};

#endif // DIALOGPULMONAR_H
