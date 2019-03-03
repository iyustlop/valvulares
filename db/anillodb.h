#ifndef ANILLODB_H
#define ANILLODB_H

#include <QtSql>
#include "bean/protesis/anillobean.h"

class AnilloDb
{
public:
    AnilloDb();
    QSqlError insertAnilloDb(QString numeroHistoria, AnilloBean anilloBean);
    QList<AnilloBean> readAnilloDb(QString queryId);
};

#endif // ANILLODB_H
