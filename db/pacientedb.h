#ifndef PACIENTEDB_H
#define PACIENTEDB_H

#include "bean/patientbean.h"
#include <QtSql>


class PacienteDb
{
public:
    PacienteDb();
    QSqlError insertDB(PatientBean paciente);
    PatientBean readDB(QString queryId);
};

#endif // PACIENTEDB_H
