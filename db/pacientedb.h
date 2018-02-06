#ifndef PACIENTEDB_H
#define PACIENTEDB_H

#include "bean/patient.h"
#include <QtSql>


class PacienteDB
{
public:
    PacienteDB();
    QSqlError insertDB(Patient paciente);
    Patient readDB(QString queryId);
};

#endif // PACIENTEDB_H
