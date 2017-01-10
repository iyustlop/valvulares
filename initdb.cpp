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
    /*if(!query.exec("create table person (id int primary key, "
                   "firstname varchar(20), lastname varchar(20))"))
            return query.lastError();*/
    // Avoid error trying to create the table.
    query.exec("create table person (id int primary key, firstname varchar(20), lastname varchar(20), genre varchar(20), etiology varchar(20), cause varchar(20), valvularPatology varchar(20))");

    return QSqlError();
}

QSqlError initDB::insertDB(Patient patient){
    QSqlQuery query;

    if (!query.prepare("insert into person values(:id, :name, :lastname, :genre, :etiology, :cause, :valvularPatology)"))
        return query.lastError();
    query.bindValue(":id",patient.getNumeroHistoria());
    query.bindValue(":name",patient.getNombre());
    query.bindValue(":lastname",patient.getApellidos());
    query.bindValue(":genre",patient.getGenero());
    query.bindValue(":etiology",patient.getEtiologia());
    query.bindValue(":cause",patient.getCausa());
    query.bindValue(":valvularPatology",patient.getPatlogiaValvular());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}
