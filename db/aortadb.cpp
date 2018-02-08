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

}
