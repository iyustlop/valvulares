#ifndef INITDBCITA_H
#define INITDBCITA_H
#include "cita/cita.h"
#include "cita/parametrosanaliticos.h"
#include <QtSql>

class initDBCita
{
public:
    initDBCita();
    QSqlError insertCita(Cita cita, ParametrosAnaliticos parametrosAnaliticos);
};

#endif // INITDBCITA_H
