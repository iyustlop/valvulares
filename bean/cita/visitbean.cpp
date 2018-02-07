#include "visitbean.h"

VisitBean::VisitBean()
{

}

Cita VisitBean::getCita() const
{
    return cita;
}

void VisitBean::setCita(const Cita &value)
{
    cita = value;
}

ParametrosAnaliticos VisitBean::getParametrosAnaliticos() const
{
    return parametrosAnaliticos;
}

void VisitBean::setParametrosAnaliticos(const ParametrosAnaliticos &value)
{
    parametrosAnaliticos = value;
}
