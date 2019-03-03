#include "protesismecanicadb.h"

ProtesisMecanicaDb::ProtesisMecanicaDb()
{

}

QSqlError ProtesisMecanicaDb::insertProtesisMecanicaDb(QString numeroHistoria, ProtesisMecanicaBean protesisMecanicaBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into protesisMecanica (personId,dateProtMec,tipo,gradienteMaximo,gradienteMedio,tAcao,leakPeriprotesico,areaMitral,relacionIntegrales) "
                       "values (:personId,:dateProtMec,:tipo,:gradienteMaximo,:gradienteMedio,:tAcao,:leakPeriprotesico,:areaMitral,:relacionIntegrales)"))
        return query.lastError();
    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateProtMec",protesisMecanicaBean.getDateProtesisMecanica());
    query.bindValue(":tipo",protesisMecanicaBean.getTipoProtesisMecanica());
    query.bindValue(":gradienteMaximo",protesisMecanicaBean.getGradienteMax());
    query.bindValue(":gradienteMedio",protesisMecanicaBean.getGradienteMed());
    query.bindValue(":tAcao",protesisMecanicaBean.getTAcenAo());
    query.bindValue(":leakPeriprotesico",protesisMecanicaBean.getLeak());
    query.bindValue(":areaMitral",protesisMecanicaBean.getAreaMitral());
    query.bindValue(":relacionIntegrales",protesisMecanicaBean.getRi());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<ProtesisMecanicaBean> ProtesisMecanicaDb::readProtesisMecanicaDb(QString queryId)
{
    QSqlQuery query;

    ProtesisMecanicaBean protesisMecanicaBean;
    QList<ProtesisMecanicaBean> protesisMecanicaBeanList;

    query.prepare("SELECT pr.dateProtMec,pr.tipo,pr.gradienteMaximo,pr.gradienteMedio,pr.tAcao,pr.leakPeriprotesico,pr.areaMitral,pr.relacionIntegrales "
                  "FROM protesisMecanica pr "
                  "WHERE pr.personId = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            protesisMecanicaBean.setDateProtesisMecanica(query.value(0).toString());
            protesisMecanicaBean.setTipoProtesisMecanica(query.value(1).toString());
            protesisMecanicaBean.setGradienteMax(query.value(2).toString());
            protesisMecanicaBean.setGradienteMed(query.value(3).toString());
            protesisMecanicaBean.setTAcenAo(query.value(4).toString());
            protesisMecanicaBean.setLeak(query.value(5).toString());
            protesisMecanicaBean.setAreaMitral(query.value(6).toString());
            protesisMecanicaBean.setRi(query.value(7).toString());

            protesisMecanicaBeanList.append(protesisMecanicaBean);
        }
    }
     return protesisMecanicaBeanList;
}
