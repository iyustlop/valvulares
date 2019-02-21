#ifndef RESONANCIADB_H
#define RESONANCIADB_H
#include "bean/reso/resonanciabean.h"
#include <QtSql>

class ResonanciaDb
{
public:
    ResonanciaDb();
    QSqlError insertResonancia(QString numeroHistoria, ResonanciaBean resonanciaBean);
    QList<ResonanciaBean> readResonancia(QString queryId);
};

#endif // RESONANCIADB_H
