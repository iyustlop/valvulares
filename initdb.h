#ifndef INITDB_H
#define INITDB_H

#include "patient.h"
#include "person.h"
#include "etiology.h"

#include <QtSql>

class initDB
{
public:
    initDB();
    QSqlError startDb();
    QSqlError insertDB(Patient paciente);
    Patient readDB(QString queryId);
    QSqlError updateDB(Patient paciente);
};

#endif // INITDB_H
