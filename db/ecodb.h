#ifndef ECODB_H
#define ECODB_H
#include "eco/ecobean.h"
#include <QtSql>


class ecoDb
{
public:
    ecoDb();
    QSqlError insertEco(QString numeroHistoria, ecoBean ecoBean);
    QList<ecoBean> readEcoBeanDB(QString queryId);
};

#endif // ECODB_H
