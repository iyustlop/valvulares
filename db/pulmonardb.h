#ifndef PULMONARDB_H
#define PULMONARDB_H

#include <QtSql>
#include "bean/pulmonar/pulmonarbean.h"
class PulmonarDb
{
public:
    PulmonarDb();
    QSqlError insertPulmonar(QString numeroHistoria, PulmonarBean pulmonarBean);
    QList<PulmonarBean> readPulmonar(QString queryId);
};

#endif // PULMONARDB_H
