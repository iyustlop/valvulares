#ifndef AORTADB_H
#define AORTADB_H

#include <QtSql>
#include "bean/aorta/aortabean.h"

class AortaDB
{
public:
    AortaDB();
    QSqlError insertAorta(QString numeroHistoria, AortaBean aortaBean);
    QList<AortaBean> readAorta(QString queryId);
};

#endif // AORTADB_H
