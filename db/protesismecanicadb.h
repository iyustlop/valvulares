#ifndef PROTESISMECANICADB_H
#define PROTESISMECANICADB_H

#include <QtSql>
#include "bean/protesis/protesismecanicacabean.h"

class ProtesisMecanicaDb
{
public:
    ProtesisMecanicaDb();
    QSqlError insertProtesisMecanicaDb(QString numeroHistoria, ProtesisMecanicaBean protesisMecanicaBean);
    QList<ProtesisMecanicaBean> readProtesisMecanicaDb(QString queryId);
};

#endif // PROTESISMECANICADB_H
