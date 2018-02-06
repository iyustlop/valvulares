#ifndef INITDBCITA_H
#define INITDBCITA_H
#include "cita/cita.h"
#include "cita/parametrosanaliticos.h"
#include "cita/visit.h"
#include <QtSql>

class initDBCita
{
public:
    initDBCita();
    QSqlError insertCita(QString numeroHistoria, visit visita);
    QList<visit> readVisit(QString nHistoria);
    QList<visit> readVisitaDB(QString queryId);
};

#endif // INITDBCITA_H
