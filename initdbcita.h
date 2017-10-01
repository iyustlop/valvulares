#ifndef INITDBCITA_H
#define INITDBCITA_H
#include "cita.h"

#include <QtSql>

class initDBCita
{
public:
    initDBCita();
    QSqlError insertCita(Cita cita);
};

#endif // INITDBCITA_H
