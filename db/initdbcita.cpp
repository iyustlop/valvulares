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

    if (!query.prepare("insert into cita (personId,dateVisit,rhythm,functionalGrade,FRCV,HB,creatinina,FG,proBNP,potasio,indicacionQuirurgica,euroScore)"
                       "values (:personId,:dateVisit,:rhythm,:functionalGrade,:FRCV,:HB,:creatinina,:FG,:proBNP,:potasio,:indicacionQuirurgica,:euroScore)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateVisit",cita.getFechaConsulta());
    query.bindValue(":rhythm",cita.getRitmo());
    query.bindValue(":functionalGrade",cita.getGradoFuncional());
    query.bindValue(":FRCV",cita.getFrcv());
    query.bindValue(":HB",parametrosAnaliticos.getHB());
    query.bindValue(":creatinina",parametrosAnaliticos.getCreatinina());
    query.bindValue(":FG",parametrosAnaliticos.getFG());
    query.bindValue(":proBNP",parametrosAnaliticos.getProBNP());
    query.bindValue(":potasio",parametrosAnaliticos.getPotasio());
    query.bindValue(":indicacionQuirurgica",parametrosAnaliticos.getIndicacionQr());
    query.bindValue(":euroScore",parametrosAnaliticos.getEuroScore());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<visit> initDBCita::readVisit(QString nHistoria){
    QSqlQuery query;
    QList<visit> listVisit;
    visit visita;
    Cita cita;

    query.prepare("SELECT * FROM cita "
                  "where cita.personId = :id");
    query.bindValue(":id",nHistoria);

    if(query.exec()){
        while(query.next()) {
            cita.setFechaConsulta(query.value(2).toString());
            cita.setRitmo(query.value(3).toString());
            cita.setGradoFuncional(query.value(4).toString());
            cita.setFrcv(query.value(5).toString());
            visita.setCita(cita);
            listVisit.append(visita);
        }
    }

    return listVisit;
}

QList<visit> initDBCita::readVisitaDB(QString queryId){
    QSqlQuery query;

    visit readVisita;
    QList<visit> readVisitas;
    Cita readCita;
    ParametrosAnaliticos readParametrosAnaliticos;

    query.prepare("SELECT c.dateVisit, c.rhythm, c.functionalGrade, c.FRCV, c.HB, c.creatinina, c.FG, c.proBNP, c.potasio, c.indicacionQuirurgica, c.euroScore "
                  "FROM cita c "
                  "WHERE c.personId = :id");
    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            readCita.setFechaConsulta(query.value(0).toString());
            readCita.setRitmo(query.value(1).toString());
            readCita.setGradoFuncional(query.value(2).toString());
            readCita.setFrcv(query.value(3).toString());
            readParametrosAnaliticos.setHB(query.value(4).toString());
            readParametrosAnaliticos.setCreatinina(query.value(5).toString());
            readParametrosAnaliticos.setFG(query.value(6).toString());
            readParametrosAnaliticos.setProBNP(query.value(7).toString());
            readParametrosAnaliticos.setPotasio(query.value(8).toString());
            readParametrosAnaliticos.setIndicacionQr(query.value(9).toString());
            readParametrosAnaliticos.setEuroScore(query.value(10).toString());

            readVisita.setCita(readCita);
            readVisita.setParametrosAnaliticos(readParametrosAnaliticos);

            readVisitas.append(readVisita);
        }
    }

    return readVisitas;
}
