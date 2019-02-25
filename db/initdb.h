#ifndef INITDB_H
#define INITDB_H

#include "bean/patientbean.h"
#include "bean/person.h"
#include "bean/etiology.h"
#include "bean/cita/visitbean.h"

#include <QtSql>

class InitDb
{
public:
    InitDb();
    QSqlError startDb();

    QSqlError updateDB(PatientBean paciente);
private:
    void createTableResonancia(QSqlQuery query);
    void createTablePruebasDiagnosticasErgo(QSqlQuery query);
    void createTablePruebasDiagnosticasCiclo(QSqlQuery query);
    void createTablePruebasDiagnosticasReso(QSqlQuery query);
    void createTablePruebasDiagnosticasEco(QSqlQuery query);
    void createTableCita(QSqlQuery query);
    void createTableProtesisBiologica(QSqlQuery query);
    void createTableProtesisMecanica(QSqlQuery query);
    void createTableAnillo(QSqlQuery query);
};

#endif // INITDB_H
