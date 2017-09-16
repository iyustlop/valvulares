#include "parametrosanaliticos.h"

ParametrosAnaliticos::ParametrosAnaliticos()
{

}

QString ParametrosAnaliticos::getHB() const
{
    return HB;
}

void ParametrosAnaliticos::setHB(const QString &value)
{
    HB = value;
}

QString ParametrosAnaliticos::getCreatinina() const
{
    return creatinina;
}

void ParametrosAnaliticos::setCreatinina(const QString &value)
{
    creatinina = value;
}

QString ParametrosAnaliticos::getFG() const
{
    return FG;
}

void ParametrosAnaliticos::setFG(const QString &value)
{
    FG = value;
}

QString ParametrosAnaliticos::getProBNP() const
{
    return proBNP;
}

void ParametrosAnaliticos::setProBNP(const QString &value)
{
    proBNP = value;
}

QString ParametrosAnaliticos::getPotasio() const
{
    return potasio;
}

void ParametrosAnaliticos::setPotasio(const QString &value)
{
    potasio = value;
}

QString ParametrosAnaliticos::getTratamiento() const
{
    return tratamiento;
}

void ParametrosAnaliticos::setTratamiento(const QString &value)
{
    tratamiento = value;
}
