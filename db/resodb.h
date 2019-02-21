#ifndef RESODB_H
#define RESODB_H
#include "bean/reso/resonanciabean.h"
#include <QtSql>

class ResoDb
{
public:
    ResoDb();
    QSqlError insertReso(QString numeroHistoria, ResonanciaBean resoBean);
    QList<ResonanciaBean> readReso(QString queryId);
};

#endif // RESODB_H
