#ifndef INITDB_H
#define INITDB_H

#include "bean/patientbean.h"
#include "bean/person.h"
#include "bean/etiology.h"
#include "cita/visit.h"

#include <QtSql>

class initDB
{
public:
    initDB();
    QSqlError startDb();

    QSqlError updateDB(PatientBean paciente);
};

#endif // INITDB_H
