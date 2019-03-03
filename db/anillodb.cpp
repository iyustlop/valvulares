#include "anillodb.h"

AnilloDb::AnilloDb()
{

}

QSqlError AnilloDb::insertAnilloDb(QString numeroHistoria, AnilloBean anilloBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into anillo (personId,dateAnillo,tipo,gradienteMedio,leakPeriprotesico) "
                       "values (:personId,:dateAnillo,:tipo,:gradienteMedio,:leakPeriprotesico)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateAnillo",anilloBean.getDateAnillo());
    query.bindValue(":tipo",anilloBean.getTipoAnillo());
    query.bindValue(":gradienteMedio",anilloBean.getGradiente());
    query.bindValue(":leakPeriprotesico",anilloBean.getLeak());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<AnilloBean> AnilloDb::readAnilloDb(QString queryId)
{
    QSqlQuery query;

    AnilloBean anilloBean;
    QList<AnilloBean> anilloBeanList;

    query.prepare("SELECT a.dateAnillo,a.tipo,a.gradienteMedio,a.leakPeriprotesico "
                  "FROM anillo a "
                  "WHERE a.personId = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            anilloBean.setDateAnillo(query.value(0).toString());
            anilloBean.setTipoAnillo(query.value(1).toString());
            anilloBean.setGradiente(query.value(2).toString());
            anilloBean.setLeak(query.value(3).toString());

            anilloBeanList.append(anilloBean);
        }
    }
     return anilloBeanList;
}
