#ifndef INITDB_H
#define INITDB_H

#include "patient.h"

#include <QtSql>

class initDB
{
public:
    initDB();
    QSqlError startDb();
    QSqlError insertDB(Patient patient);
};

#endif // INITDB_H
