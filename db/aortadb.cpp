#include "aortadb.h"

AortaDb::AortaDb()
{

}

QSqlError AortaDb::insertAorta(QString numeroHistoria, AortaBean aortaBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into mitral (personId,dateAorta,gradientePicoAo,gradienteMedioAo,relacionDeIntegrales,areaAortica,ore,vrIao,vcIao,relacionAlturaJetIaoItsvi,inversionIao)"
                       "values (:personId,:dateAorta,:gradientePicoAo,:gradienteMedioAo,:relacionDeIntegrales,:areaAortica,:ore,:vrIao,:vcIao,:relacionAlturaJetIaoItsvi,:inversionIao)"))
        return query.lastError();

    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateAorta",aortaBean.getDate());
    query.bindValue(":gradientePicoAo",aortaBean.getGradAo());
    query.bindValue(":gradienteMedioAo",aortaBean.getGradMedioAo());
    query.bindValue(":relacionDeIntegrales",aortaBean.getRelacionDeInl());
    query.bindValue(":areaAortica",aortaBean.getAreaAo());
    query.bindValue(":ore",aortaBean.getOReIaO());
    query.bindValue(":vrIao",aortaBean.getVRiAo());
    query.bindValue(":vcIao",aortaBean.getVCiAo());
    query.bindValue(":relacionAlturaJetIaoItsvi",aortaBean.getRelAltJetIao());
    query.bindValue(":inversionIao",aortaBean.getInversionIao());

    if (!query.exec())
        return query.lastError();

    return QSqlError();

}

QList<AortaBean> AortaDb::readAorta(QString queryId)
{
    QSqlQuery query;

    AortaBean aortaBean;
    QList<AortaBean> aortaList;

    query.prepare("SELECT a.dateAorta,a.gradientePicoAo,a.gradienteMedioAo,a.relacionDeIntegrales,a.areaAortica,a.ore,a.vrIao,a.vcIao,a.relacionAlturaJetIaoItsvi,a.inversionIao "
                  "FROM aorta a "
                  "WHERE a.personId = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            aortaBean.setDate(query.value(0).toString());
            aortaBean.setGradAo(query.value(1).toString());
            aortaBean.setGradMedioAo(query.value(2).toString());
            aortaBean.setRelacionDeInl(query.value(3).toString());
            aortaBean.setAreaAo(query.value(4).toString());
            aortaBean.setOReIaO(query.value(5).toString());
            aortaBean.setVRiAo(query.value(6).toString());
            aortaBean.setVCiAo(query.value(7).toString());
            aortaBean.setRelAltJetIao(query.value(8).toString());
            aortaBean.setInversionIao(query.value(9).toString());

            aortaList.append(aortaBean);
        }
    }
     return aortaList;
}
