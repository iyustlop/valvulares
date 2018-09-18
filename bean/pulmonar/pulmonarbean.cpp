#include "pulmonarbean.h"

PulmonarBean::PulmonarBean()
{

}

QString PulmonarBean::getIp() const
{
    return ip;
}

void PulmonarBean::setIp(const QString &value)
{
    ip = value;
}

QString PulmonarBean::getGradoMedio() const
{
    return gradoMedio;
}

void PulmonarBean::setGradoMedio(const QString &value)
{
    gradoMedio = value;
}

QString PulmonarBean::getGradoMax() const
{
    return gradoMax;
}

void PulmonarBean::setGradoMax(const QString &value)
{
    gradoMax = value;
}

QString PulmonarBean::getDatePulmonar() const
{
    return datePulmonar;
}

void PulmonarBean::setDatePulmonar(const QString &value)
{
    datePulmonar = value;
}
