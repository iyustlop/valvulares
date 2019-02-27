#include "protesisbiologicabean.h"

ProtesisBiologicaBean::ProtesisBiologicaBean()
{

}

QString ProtesisBiologicaBean::getDateProtesisBiologica() const
{
    return dateProtesisBiologica;
}

void ProtesisBiologicaBean::setDateProtesisBiologica(const QString &value)
{
    dateProtesisBiologica = value;
}

QString ProtesisBiologicaBean::getTipoProtesisBiologica() const
{
    return tipoProtesisBiologica;
}

void ProtesisBiologicaBean::setTipoProtesisBiologica(const QString &value)
{
    tipoProtesisBiologica = value;
}

QString ProtesisBiologicaBean::getGradienteMax() const
{
    return gradienteMax;
}

void ProtesisBiologicaBean::setGradienteMax(const QString &value)
{
    gradienteMax = value;
}

QString ProtesisBiologicaBean::getGradienteMed() const
{
    return gradienteMed;
}

void ProtesisBiologicaBean::setGradienteMed(const QString &value)
{
    gradienteMed = value;
}

QString ProtesisBiologicaBean::getRi() const
{
    return ri;
}

void ProtesisBiologicaBean::setRi(const QString &value)
{
    ri = value;
}

QString ProtesisBiologicaBean::getLeak() const
{
    return leak;
}

void ProtesisBiologicaBean::setLeak(const QString &value)
{
    leak = value;
}
