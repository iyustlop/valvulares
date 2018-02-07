#ifndef INITDBCITA_H
#define INITDBCITA_H
#include "cita/cita.h"
#include "cita/parametrosanaliticos.h"
#include "cita/visit.h"
#include <QtSql>

class CitaDB
{
public:
    CitaDB();
    QSqlError insertCita(QString numeroHistoria, visit visita);
    QList<visit> readCita(QString queryId);
};

#endif // INITDBCITA_H
