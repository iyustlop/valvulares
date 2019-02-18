#ifndef RESONANCIADB_H
#define RESONANCIADB_H
#include "bean/eco/ecobean.h"
#include <QtSql>

class ResonanciaDb
{
public:
    ResonanciaDb();
    QSqlError insertResonancia(QString numeroHistoria, ecoBean ecoBean);
    QList<ecoBean> readResonancia(QString queryId);
};

#endif // RESONANCIADB_H
