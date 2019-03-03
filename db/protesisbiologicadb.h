#ifndef PROTESISBIOLOGICADB_H
#define PROTESISBIOLOGICADB_H

#include <QtSql>
#include "bean/protesis/protesisbiologicabean.h"

class ProtesisBiologicaDb
{
public:
    ProtesisBiologicaDb();
    QSqlError insertProtesisBiologicaDb(QString numeroHistoria, ProtesisBiologicaBean protesisBiologicaBean);
    QList<ProtesisBiologicaBean> readProtesisBiologicaDb(QString queryId);
};

#endif // PROTESISBIOLOGICADB_H
