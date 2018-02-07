#ifndef MITRALDB_H
#define MITRALDB_H

#include <QtSql>
#include "bean/mitral/mitralbean.h"

class MitralDB
{
public:
    MitralDB();
    QSqlError insertMitral(QString numeroHistoria, MitralBean mitralBean);
    QList<MitralBean> readMitral(QString queryId);
};

#endif // MITRALDB_H
