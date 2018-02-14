#include "tridb.h"

TriDb::TriDb()
{

}

QSqlError TriDb::insertTri(QString numeroHistoria, TriBean triBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into tricuspide (personId,dateTri,psap,grado) "
                       "values (:personId,:dateTri,:psap,:grado)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateTri",triBean.getDateTri());
    query.bindValue(":psap",triBean.getPsap());
    query.bindValue(":grado",triBean.getGrado());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<TriBean> TriDb::readTri(QString queryId)
{
    QSqlQuery query;

    TriBean triBean;
    QList<TriBean> triList;

    query.prepare("SELECT t.dateTri,t.psap,t.grado "
                  "FROM tricuspide t "
                  "WHERE t.personId = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            triBean.setDateTri(query.value(0).toString());
            triBean.setPsap(query.value(1).toString());
            triBean.setGrado(query.value(2).toString());

            triList.append(triBean);
        }
    }
     return triList;
}
