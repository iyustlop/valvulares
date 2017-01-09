#include "initdb.h"

initDB::initDB()
{

}

QSqlError initDB::startDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\iyust\\Documents\\Desarrollo\\valvulares.db");

    if (!db.open())
        return db.lastError();

    QSqlQuery query;
    if(!query.exec("create table person (id int primary key, "
                   "firstname varchar(20), lastname varchar(20))"))
            return query.lastError();

    return QSqlError();
}

QSqlError initDB::insertDB(Patient patient){
    QSqlQuery query;

    if (!query.prepare("insert into person values(:id, :name, :surname)"))
        return query.lastError();
    query.bindValue(":id",patient.getNumeroHistoria());
    query.bindValue(":name",patient.getNombre());
    query.bindValue(":surname",patient.getApellidos());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}
