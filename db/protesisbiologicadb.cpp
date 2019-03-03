#include "protesisbiologicadb.h"

ProtesisBiologicaDb::ProtesisBiologicaDb()
{

}

QSqlError ProtesisBiologicaDb::insertProtesisBiologicaDb(QString numeroHistoria, ProtesisBiologicaBean protesisBiologicaBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into protesisBiologica (personId,dateProtBio,tipo,gradienteMaximo,gradienteMedio,relacionIntegrales,leakPeriprotesico) "
                       "values (:personId,:dateProtBio,:tipo,:gradienteMaximo,:gradienteMedio,:relacionIntegrales,:leakPeriprotesico)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateProtBio",protesisBiologicaBean.getDateProtesisBiologica());
    query.bindValue(":tipo",protesisBiologicaBean.getTipoProtesisBiologica());
    query.bindValue(":gradienteMaximo",protesisBiologicaBean.getGradienteMax());
    query.bindValue(":gradienteMedio",protesisBiologicaBean.getGradienteMed());
    query.bindValue(":relacionIntegrales",protesisBiologicaBean.getRi());
    query.bindValue(":leakPeriprotesico",protesisBiologicaBean.getLeak());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<ProtesisBiologicaBean> ProtesisBiologicaDb::readProtesisBiologicaDb(QString queryId)
{
    QSqlQuery query;

    ProtesisBiologicaBean protesisBiologicaBean;
    QList<ProtesisBiologicaBean> protesisBiologicaBeanList;

    query.prepare("SELECT pb.dateProtBio,pb.tipo,pb.gradienteMaximo,pb.gradienteMedio,pb.relacionIntegrales,pb.leakPeriprotesico "
                  "FROM protesisBiologica pb "
                  "WHERE pb.personId = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            protesisBiologicaBean.setDateProtesisBiologica(query.value(0).toString());
            protesisBiologicaBean.setTipoProtesisBiologica(query.value(1).toString());
            protesisBiologicaBean.setGradienteMax(query.value(2).toString());
            protesisBiologicaBean.setGradienteMed(query.value(3).toString());
            protesisBiologicaBean.setRi(query.value(4).toString());
            protesisBiologicaBean.setLeak(query.value(5).toString());

            protesisBiologicaBeanList.append(protesisBiologicaBean);
        }
    }
     return protesisBiologicaBeanList;
}
