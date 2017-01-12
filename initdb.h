#ifndef INITDB_H
#define INITDB_H

#include "patient.h"
#include "etiology.h"

#include <QtSql>

class initDB
{
public:
    initDB();
    QSqlError startDb();
    QSqlError insertDB(Person patient, Etiology etiology);
    Patient readDB(QString queryId);
    QSqlError updateDB(Person patient, Etiology etiology);
};

#endif // INITDB_H
