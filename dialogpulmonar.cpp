#include "dialogpulmonar.h"
#include "ui_dialogpulmonar.h"

DialogPulmonar::DialogPulmonar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPulmonar)
{
    ui->setupUi(this);
}

DialogPulmonar::~DialogPulmonar()
{
    delete ui;
}
