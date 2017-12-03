#include "visit.h"

visit::visit()
{

}

Cita visit::getCita() const
{
    return cita;
}

void visit::setCita(const Cita &value)
{
    cita = value;
}

ParametrosAnaliticos visit::getParametrosAnaliticos() const
{
    return parametrosAnaliticos;
}

void visit::setParametrosAnaliticos(const ParametrosAnaliticos &value)
{
    parametrosAnaliticos = value;
}
