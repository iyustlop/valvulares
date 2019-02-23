#include "ciclodb.h"

CicloDb::CicloDb()
{

}

QSqlError CicloDb::insertCiclo(QString numeroHistoria, CicloBean cicloBean)
{
    QSqlQuery query;

    if (!query.prepare("insert into pruebasDiagnosticasCiclo (personId,dateCiclo,modalidad,vo2indexado,vo2picoperdicho,rer,vo2enVa,morfCurva,EqCo2enVa,vslopeCo2,oues,reservaVent,ventOscilante)"
                       "values (:personId,:dateCiclo,:modalidad,:vo2indexado,:vo2picoperdicho,:rer,:vo2enVa,:morfCurva,:EqCo2enVa,:vslopeCo2,:oues,:reservaVent,:ventOscilante)"))
        return query.lastError();

    query.bindValue(":personId",numeroHistoria.toInt());
    query.bindValue(":dateCiclo",cicloBean.getFechaCiclo());
    query.bindValue(":modalidad",cicloBean.getModalidad());
    query.bindValue(":vo2indexado",cicloBean.getVo2Indexado());
    query.bindValue(":vo2picoperdicho",cicloBean.getVo2PicoPredicho());
    query.bindValue(":rer",cicloBean.getRer());
    query.bindValue(":vo2enVa",cicloBean.getVo2enVa());
    query.bindValue(":morfCurva",cicloBean.getMorfCurva());
    query.bindValue(":EqCo2enVa",cicloBean.getEqCo2enVa());
    query.bindValue(":vslopeCo2",cicloBean.getVslopeCo2());
    query.bindValue(":oues",cicloBean.getOues());
    query.bindValue(":reservaVent",cicloBean.getReservVentilatoria());
    query.bindValue(":ventOscilante",cicloBean.getVentOscilante());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

QList<CicloBean> CicloDb::readCiclo(QString queryId)
{
    QSqlQuery query;

    CicloBean cicloBean;
    QList<CicloBean> cicloList;

    query.prepare("SELECT pciclo.dateCiclo,pciclo.modalidad,pciclo.vo2indexado,pciclo.vo2picoperdicho,pciclo.rer,pciclo.vo2enVa,pciclo.morfCurva,pciclo.EqCo2enVa,pciclo.vslopeCo2,pciclo.oues,pciclo.reservaVent,pciclo.ventOscilante "
                  "FROM pruebasDiagnosticasCiclo pciclo "
                  "WHERE pciclo.personId = :id");
    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            cicloBean.setFechaCiclo(query.value(0).toString());
            cicloBean.setModalidad(query.value(1).toString());
            cicloBean.setVo2Indexado(query.value(2).toString());
            cicloBean.setVo2PicoPredicho(query.value(3).toString());
            cicloBean.setRer(query.value(4).toString());
            cicloBean.setVo2enVa(query.value(5).toString());
            cicloBean.setMorfCurva(query.value(6).toString());
            cicloBean.setEqCo2enVa(query.value(7).toString());
            cicloBean.setVslopeCo2(query.value(8).toString());
            cicloBean.setOues(query.value(9).toString());
            cicloBean.setReservVentilatoria(query.value(10).toString());
            cicloBean.setVentOscilante(query.value(11).toString());

            cicloList.append(cicloBean);
        }
    }
     return cicloList;
}
