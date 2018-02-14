#include "tribean.h"

TriBean::TriBean()
{

}

QString TriBean::getPsap() const
{
    return psap;
}

void TriBean::setPsap(const QString &value)
{
    psap = value;
}

QString TriBean::getGrado() const
{
    return grado;
}

void TriBean::setGrado(const QString &value)
{
    grado = value;
}
