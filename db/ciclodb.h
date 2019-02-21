#ifndef CICLODB_H
#define CICLODB_H
#include "bean/ciclo/ciclobean.h"
#include <QtSql>

class CicloDb
{
public:
    CicloDb();
    QSqlError insertCiclo(QString numeroHistoria, CicloBean cicloBean);
    QList<CicloBean> readCiclo(QString queryId);
};

#endif // CICLODB_H
