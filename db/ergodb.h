#ifndef ERGODB_H
#define ERGODB_H
#include <QtSql>
#include <bean/ergo/ergobean.h>

class ErgoDb
{
public:
    ErgoDb();
    QSqlError insertErgo(QString numeroHistoria, ErgoBean ergoBean);
    QList<ErgoBean> readErgo(QString queryId);
};

#endif // ERGODB_H
