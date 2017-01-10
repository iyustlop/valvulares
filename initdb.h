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
    Patient readDB(QString queryId);
};

#endif // INITDB_H
