#include "mitraldb.h"

MitralDB::MitralDB()
{

}

 QSqlError MitralDB::insertMitral(QString numeroHistoria, MitralBean mitralBean){
     QSqlQuery query;

     if (!query.prepare("insert into mitral (personId,dateMitral,gradienteMedioMitral,avmPorThp,vOndaE,ore,vR,vC,inversionSistolicaVvpp)"
                        "values (:personId,:dateMitral,:gradienteMedioMitral,:avmPorThp,:vOndaE,:ore,:vR,:vC,:inversionSistolicaVvpp)"))
         return query.lastError();

     query.bindValue(":personId",numeroHistoria.toInt());
     query.bindValue(":dateMitral",mitralBean.getFecha());
     query.bindValue(":gradienteMedioMitral",mitralBean.getGrdMedio());
     query.bindValue(":avmPorThp",mitralBean.getAvmXtmp());
     query.bindValue(":vOndaE",mitralBean.getVOndaE());
     query.bindValue(":ore",mitralBean.getORe());
     query.bindValue(":vR",mitralBean.getVR());
     query.bindValue(":vC",mitralBean.getVC());
     query.bindValue(":inversionSistolicaVvpp",mitralBean.getInvSistolicaVvpp());

     if (!query.exec())
         return query.lastError();

     return QSqlError();
 }

 QList<MitralBean> MitralDB::readMitral(QString queryId){
     QSqlQuery query;

     MitralBean mitralBean;
     QList<MitralBean> mitralList;

     query.prepare("SELECT m.dateMitral,m.gradienteMedioMitral,m.avmPorThp,m.vOndaE,m.ore,m.vR,m.vC,m.inversionSistolicaVvpp "
                   "FROM mitral m "
                   "WHERE m.personId = :id");
     query.bindValue(":id",queryId);

     if(query.exec()){
         while (query.next()){
             mitralBean.setFecha(query.value(0).toString());
             mitralBean.setGrdMedio(query.value(1).toString());
             mitralBean.setAvmXtmp(query.value(2).toString());
             mitralBean.setVOndaE(query.value(3).toString());
             mitralBean.setORe(query.value(4).toString());
             mitralBean.setVR(query.value(5).toString());
             mitralBean.setVC(query.value(6).toString());
             mitralBean.setInvSistolicaVvpp(query.value(7).toString());

             mitralList.append(mitralBean);
         }
     }
      return mitralList;
 }

