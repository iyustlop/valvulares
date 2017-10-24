#include "protesicdisfunction.h"

ProtesicDisfunction::ProtesicDisfunction()
{

}

QString ProtesicDisfunction::getCausa()
{
    return causa;
}

void ProtesicDisfunction::setCausa(QString cause)
{
    causa = cause;
}

QString ProtesicDisfunction::getProtesis()
{
    return protesis;
}

void ProtesicDisfunction::setProtesis(QString nProtesis)
{
    protesis = nProtesis;
}

QString ProtesicDisfunction::getModelo()
{
    return modelo;
}

void ProtesicDisfunction::setModelo(QString model)
{
    modelo = model;
}

QString ProtesicDisfunction::getNumero()
{
    return numero;
}

void ProtesicDisfunction::setNumero(QString number)
{
    numero = number;
}

QString ProtesicDisfunction::getFechaCirugia()
{
    return fechaCirugia;
}

void ProtesicDisfunction::setFechaCirugia(QString surgeonDate)
{
    fechaCirugia = surgeonDate;
}
