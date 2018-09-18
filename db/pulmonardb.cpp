#include "pulmonardb.h"

PulmonarDb::PulmonarDb()
{

}

QSqlError PulmonarDb::insertPulmonar(QString numeroHistoria, PulmonarBean pulmonarBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into pulmonar (personId,datePulmonar,gradienteMaximo,gradienteMedio,ip) "
                       "values (:personId,:datePulmonar,:gradienteMaximo,:gradienteMedio,:ip)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":datePulmonar",pulmonarBean.getDatePulmonar());
    query.bindValue(":gradienteMaximo",pulmonarBean.getGradoMax());
    query.bindValue(":gradienteMedio",pulmonarBean.getGradoMedio());
    query.bindValue(":ip",pulmonarBean.getIp());

    if (!query.exec())
        return query.lastError();

    return QSqlError();

}

QList<PulmonarBean> PulmonarDb::readPulmonar(QString queryId)
{
    QSqlQuery query;

    PulmonarBean pulmonarBean;
    QList<PulmonarBean> pulmonarList;

    query.prepare("SELECT p.datePulmonar,p.gradienteMaximo,p.gradienteMedio,p.ip "
                  "FROM pulmonar p "
                  "WHERE p.personId = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            pulmonarBean.setDatePulmonar(query.value(0).toString());
            pulmonarBean.setGradoMax(query.value(1).toString());
            pulmonarBean.setGradoMedio(query.value(2).toString());
            pulmonarBean.setIp(query.value(3).toString());

            pulmonarList.append(pulmonarBean);
        }
    }
     return pulmonarList;
}
