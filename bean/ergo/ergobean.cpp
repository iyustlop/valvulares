#include "ergobean.h"

ErgoBean::ErgoBean()
{

}

QString ErgoBean::getFechaErgo() const
{
    return fechaErgo;
}

void ErgoBean::setFechaErgo(const QString &value)
{
    fechaErgo = value;
}

QString ErgoBean::getTEsfuerzo() const
{
    return tEsfuerzo;
}

void ErgoBean::setTEsfuerzo(const QString &value)
{
    tEsfuerzo = value;
}

QString ErgoBean::getMets() const
{
    return mets;
}

void ErgoBean::setMets(const QString &value)
{
    mets = value;
}
