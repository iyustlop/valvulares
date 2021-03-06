#ifndef VISIT_H
#define VISIT_H

#include "cita.h"
#include "parametrosanaliticos.h"


class VisitBean
{
public:
    VisitBean();
    Cita getCita() const;
    void setCita(const Cita &value);

    ParametrosAnaliticos getParametrosAnaliticos() const;
    void setParametrosAnaliticos(const ParametrosAnaliticos &value);

private:
    Cita cita;
    ParametrosAnaliticos parametrosAnaliticos;
};

#endif // VISIT_H
