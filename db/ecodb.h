#ifndef ECODB_H
#define ECODB_H
#include "eco/ecobean.h"
#include <QtSql>


class ecoDb
{
public:
    ecoDb();
    QSqlError insertEco(QString numeroHistoria, ecoBean ecoBean);
};

#endif // ECODB_H
