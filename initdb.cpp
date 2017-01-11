#include "initdb.h"

#include <QMessageBox>

initDB::initDB()
{

}

QSqlError initDB::startDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // direccion relativa
    QString dataBaseLocation = QDir::currentPath();

    db.setDatabaseName("..\\valvulares.db");

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

Patient initDB::readDB(QString queryId){
    QSqlQuery query;
    Patient readPatient;

    query.prepare("select * from person where id = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        if (query.next()){
            readPatient.setNumeroHistoria(query.value(0).toString());
            readPatient.setNombre(query.value(1).toString());
            readPatient.setApellidos(query.value(2).toString());
            readPatient.setGenero(query.value(3).toString());
            readPatient.setEtiologia(query.value(4).toString());
            readPatient.setCausa(query.value(5).toString());
            readPatient.setPatologiaValvular(query.value(6).toString());
        }
    }

    return readPatient;
}

QSqlError initDB::updateDB(Patient patient){
    QSqlQuery query;

    if (!query.prepare("update person set firstname=:name, lastname=:lastname, genre=:genre, etiology=:etiology, "
                       "cause=:cause, valvularPatology=:valvularPatology"))
        return query.lastError();

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
