#include "ergodb.h"

ErgoDb::ErgoDb()
{

}

QSqlError ErgoDb::insertErgo(QString numeroHistoria, ErgoBean ergoBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into pruebasDiagnosticasErgo (personId,dateErgo,tEsfuerzo,mets )"
                       "values (:personId,:dateErgo,:tEsfuerzo,:mets)"))
        return query.lastError();

    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateErgo",ergoBean.getFechaErgo());
    query.bindValue(":tEsfuerzo",ergoBean.getTEsfuerzo());
    query.bindValue(":mets",ergoBean.getMets());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<ErgoBean> ErgoDb::readErgo(QString queryId)
{
    QSqlQuery query;

    ErgoBean ergoBean;
    QList<ErgoBean> ergoList;

    query.prepare("SELECT pergo.dateErgo,pergo.tEsfuerzo,pergo.mets "
                  "FROM pruebasDiagnosticasErgo pergo "
                  "WHERE pergo.personId = :id");
    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            ergoBean.setFechaErgo(query.value(0).toString());
            ergoBean.setTEsfuerzo(query.value(1).toString());
            ergoBean.setMets(query.value(2).toString());

            ergoList.append(ergoBean);
        }
    }
     return ergoList;
}
