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


