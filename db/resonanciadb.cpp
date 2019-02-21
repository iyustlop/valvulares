#include "resonanciadb.h"

ResonanciaDb::ResonanciaDb()
{

}

QSqlError ResonanciaDb::insertResonancia(QString numeroHistoria, ResonanciaBean resonanciaBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into pruebasDiagnosticasReso (personId,dateReso,fevi,vtvdi,dilatacionVi,dilatacionVd,fracRegMit,fracRegAo,raizAortica,aortaAscecndente,realceTardio,varios)"
                       "values (:personId,:dateReso,:fevi,:vtvdi,:dilatacionVi,:dilatacionVd,:fracRegMit,:fracRegAo,:raizAortica,:aortaAscecndente,:realceTardio,:varios)"))
        return query.lastError();

    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateReso",resonanciaBean.getFechaReso());
    query.bindValue(":fevi",resonanciaBean.getFevi());
    query.bindValue(":vtvdi",resonanciaBean.getVtdVi());
    query.bindValue(":dilatacionVi",resonanciaBean.getDilataVi());
    query.bindValue(":dilatacionVd",resonanciaBean.getDilataVd());
    query.bindValue(":fracRegMit",resonanciaBean.getFracRegValMit());
    query.bindValue(":fracRegAo",resonanciaBean.getFracRegValAo());
    query.bindValue(":raizAortica",resonanciaBean.getRaizAo());
    query.bindValue(":aortaAscecndente",resonanciaBean.getAoAscend());
    query.bindValue(":realceTardio",resonanciaBean.getRealceTardio());
    query.bindValue(":varios",resonanciaBean.getVarios());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<ResonanciaBean> ResonanciaDb::readResonancia(QString queryId)
{
    QSqlQuery query;

    ResonanciaBean resonanciaBean;
    QList<ResonanciaBean> resoList;

    query.prepare("SELECT preso.dateReso,preso.fevi,preso.vtvdi,preso.dilatacionVd,preso.dilatacionVi,preso.fracRegMit,preso.fracRegAo,preso.raizAortica,preso.aortaAscecndente,preso.realceTardio,preso.varios "
                  "FROM pruebasDiagnosticasReso preso "
                  "WHERE preso.personId = :id");
    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            resonanciaBean.setFechaReso(query.value(0).toString());
            resonanciaBean.setFevi(query.value(1).toString());
            resonanciaBean.setVtdVi(query.value(2).toString());
            resonanciaBean.setDilataVi(query.value(3).toString());
            resonanciaBean.setDilataVd(query.value(4).toString());
            resonanciaBean.setFracRegValMit(query.value(5).toString());
            resonanciaBean.setFracRegValAo(query.value(6).toString());
            resonanciaBean.setRaizAo(query.value(7).toString());
            resonanciaBean.setAoAscend(query.value(8).toString());
            resonanciaBean.setRealceTardio(query.value(9).toString());
            resonanciaBean.setVarios(query.value(10).toString());

            resoList.append(resonanciaBean);
        }
    }
     return resoList;
}


