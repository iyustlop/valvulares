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
    QSqlError insertDB(Patient patient, Etiology etiology);
    Patient readDB(QString queryId);
    QSqlError updateDB(Patient patient, Etiology etiology);
};

#endif // INITDB_H
