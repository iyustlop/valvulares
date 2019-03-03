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
    QList<PatientBean> readDB();
};

#endif // PACIENTEDB_H
