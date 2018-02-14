#ifndef TRIDB_H
#define TRIDB_H

#include <QtSql>
#include "bean/tri/tribean.h"
class TriDb
{
public:
    TriDb();
    QSqlError insertTri(QString numeroHistoria, TriBean triBean);
    QList<TriBean> readTri(QString queryId);
};

#endif // TRIDB_H
