#include "anillobean.h"

AnilloBean::AnilloBean()
{

}


QString AnilloBean::getDateAnillo() const
{
    return dateAnillo;
}

void AnilloBean::setDateAnillo(const QString &value)
{
    dateAnillo = value;
}

QString AnilloBean::getTipoAnillo() const
{
    return tipoAnillo;
}

void AnilloBean::setTipoAnillo(const QString &value)
{
    tipoAnillo = value;
}

QString AnilloBean::getGradiente() const
{
    return gradiente;
}

void AnilloBean::setGradiente(const QString &value)
{
    gradiente = value;
}

QString AnilloBean::getLeak() const
{
    return leak;
}

void AnilloBean::setLeak(const QString &value)
{
    leak = value;
}
