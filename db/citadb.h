#ifndef INITDBCITA_H
#define INITDBCITA_H
#include "bean/cita/cita.h"
#include "bean/cita/parametrosanaliticos.h"
#include "bean/cita/visitbean.h"
#include <QtSql>

class CitaDb
{
public:
    CitaDb();
    QSqlError insertCita(QString numeroHistoria, VisitBean visita);
    QList<VisitBean> readCita(QString queryId);
};

#endif // INITDBCITA_H
