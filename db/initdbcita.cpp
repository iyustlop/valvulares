#include "db/initdbcita.h"
#include "mainwindow.h"

initDBCita::initDBCita()
{

}

QSqlError initDBCita::insertCita(QString nHistoria, visit visita){
    QString numeroHistoria;
    Cita cita;
    ParametrosAnaliticos parametrosAnaliticos;

    numeroHistoria = nHistoria;
    cita = visita.getCita();
    parametrosAnaliticos = visita.getParametrosAnaliticos();

    QSqlQuery query;

    if (!query.prepare("insert into cita (personId,dateVisit,rhythm,functionalGrade,FRCV) values (:personId,:dateVisit,:rhythm,:functionalGrade,:FRCV)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateVisit",cita.getFechaConsulta());
    query.bindValue(":rhythm",cita.getRitmo());
    query.bindValue(":functionalGrade",cita.getGradoFuncional());
    query.bindValue(":FRCV",cita.getFrcv());
    if (!query.exec())
        return query.lastError();

    if (!query.prepare("insert into parametrosAnaliticos values(:analiticalParameter,:HB,:creatinina,:FG,:proBNP,:potasio)"))
        return query.lastError();
    query.bindValue(":analiticalParameter",numeroHistoria.toInt());
    query.bindValue(":HB",parametrosAnaliticos.getHB());
    query.bindValue(":creatinina",parametrosAnaliticos.getCreatinina());
    query.bindValue(":FG",parametrosAnaliticos.getFG());
    query.bindValue(":proBNP",parametrosAnaliticos.getProBNP());
    query.bindValue(":potasio",parametrosAnaliticos.getPotasio());
    if (!query.exec())
        return query.lastError();

    return QSqlError();
}
