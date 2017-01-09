#ifndef INITDB_H
#define INITDB_H

#include <QtSql>

class initDB
{
public:
    initDB();
    QSqlError startDb();
};

#endif // INITDB_H
