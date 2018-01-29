#include "ecodb.h"

ecoDb::ecoDb()
{

}

QSqlError ecoDb::insertEco(QString numeroHistoria, ecoBean ecoBean){

    QSqlQuery query;

    if (!query.prepare("insert into pruebasDiagnosticasEco (personId,dateEco,volumenAuriculaIzquierda,fevi,dilatacionVi,vtdVi,dilatacionVd,tapse,raizAortica,aortaAscecndente)"
                       "values (:personId,:dateEco,:volumenAuriculaIzquierda,:fevi,:dilatacionVi,:vtdVi,:dilatacionVd,:tapse,:raizAortica,:aortaAscecndente)"))
        return query.lastError();

    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateEco",ecoBean.getFechaEco());
    query.bindValue(":volumenAuriculaIzquierda",ecoBean.getVolAi());
    query.bindValue(":fevi",ecoBean.getFevi());
    query.bindValue(":dilatacionVi",ecoBean.getDilataVi());
    query.bindValue(":vtdVi","pendiente");
    query.bindValue(":dilatacionVd",ecoBean.getDilataVd());
    query.bindValue(":tapse",ecoBean.getTapse());
    query.bindValue(":aortaAscecndente",ecoBean.getAoAscend());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<ecoBean> ecoDb::readEcoBeanDB(QString queryId)
{
    QSqlQuery query;

    ecoBean ecoB;
    QList<ecoBean> ecoList;

    query.prepare("SELECT peco.dateEco,peco.volumenAuriculaIzquierda,peco.fevi,peco.dilatacionVi,peco.vtdVi,peco.dilatacionVd,peco.tapse,peco.raizAortica,peco.aortaAscecndente "
                  "FROM pruebasDiagnosticasEco peco "
                  "WHERE peco.personId = :id");
    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            ecoB.setFechaEco(query.value(0).toString());
            ecoB.setVolAi(query.value(1).toString());
            ecoB.setFevi(query.value(2).toString());
            ecoB.setDilataVi(query.value(3).toString());
            ecoB.setVtdVi(query.value(4).toString());
            ecoB.setDilataVd(query.value(5).toString());
            ecoB.setTapse(query.value(6).toString());
            ecoB.setRaizAo(query.value(7).toString());
            ecoB.setAoAscend(query.value(8).toString());

            ecoList.append(ecoB);
        }
    }
     return ecoList;
}


