#ifndef INITDB_H
#define INITDB_H

#include "bean/patient.h"
#include "bean/person.h"
#include "bean/etiology.h"
#include "cita/visit.h"

#include <QtSql>

class initDB
{
public:
    initDB();
    QSqlError startDb();
    QSqlError insertDB(Patient paciente);
    Patient readDB(QString queryId);
    visit readVisitaDB(QString queryId);
    QSqlError updateDB(Patient paciente);
};

#endif // INITDB_H
