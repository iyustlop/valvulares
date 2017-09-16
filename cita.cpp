#include "cita.h"

Cita::Cita()
{

}

QString Cita::getFechaConsulta() const
{
    return fechaConsulta;
}

void Cita::setFechaConsulta(const QString &value)
{
    fechaConsulta = value;
}

QString Cita::getRitmo() const
{
    return ritmo;
}

void Cita::setRitmo(const QString &value)
{
    ritmo = value;
}

QString Cita::getGradoFuncional() const
{
    return gradoFuncional;
}

void Cita::setGradoFuncional(const QString &value)
{
    gradoFuncional = value;
}

QString Cita::getFrcv() const
{
    return frcv;
}

void Cita::setFrcv(const QString &value)
{
    frcv = value;
}
