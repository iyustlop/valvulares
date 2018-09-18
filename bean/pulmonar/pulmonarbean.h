#ifndef PULMONAR_H
#define PULMONAR_H

#include<QString>

class PulmonarBean
{
public:
    PulmonarBean();
    QString getIp() const;
    void setIp(const QString &value);

    QString getGradoMedio() const;
    void setGradoMedio(const QString &value);

    QString getGradoMax() const;
    void setGradoMax(const QString &value);

    QString getDatePulmonar() const;
    void setDatePulmonar(const QString &value);

private:
    QString datePulmonar;
    QString gradoMax;
    QString gradoMedio;
    QString ip;
};

#endif // PULMONAR_H


