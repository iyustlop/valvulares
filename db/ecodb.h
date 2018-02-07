#ifndef ECODB_H
#define ECODB_H
#include "eco/ecobean.h"
#include <QtSql>

class EcoDb
{
public:
    EcoDb();
    QSqlError insertEco(QString numeroHistoria, ecoBean ecoBean);
    QList<ecoBean> readEco(QString queryId);
};

#endif // ECODB_H
