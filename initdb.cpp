#include "initdb.h"

#include <QMessageBox>

initDB::initDB()
{

}

QSqlError initDB::startDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString dataBaseLocation = QDir::currentPath();

    db.setDatabaseName(dataBaseLocation+"/valvulares.db");

    if (!db.open())
        return db.lastError();

    QSqlQuery query;
    /*if(!query.exec("create table person (id int primary key, "
                   "firstname varchar(20), lastname varchar(20))"))
            return query.lastError();*/   
    // Avoid error trying to create the table.
    query.exec("create table person (id int primary key, name varchar(20), lastname varchar(20), "
               "genre varchar(20), birthdate varchar(20))");
    query.exec("create table etiologia (etiologyId int, etiology varchar(20), cause varchar(20), "
               "valvularPatology varchar(20),mixedVpatology varchar(5),valvularPatologySecondary varchar(20),"
               "FOREIGN KEY(etiologyId) REFERENCES person(id))");
    query.exec("create table disfuncionProtesica (disfuncionId int, causa varchar(20), protesis varchar(20), "
               "modelo varchar(20), numero varchar(20), fechaCirugia varchar(20),"
               "FOREIGN KEY(disfuncionId) REFERENCES person(id))");

    return QSqlError();
}

QSqlError initDB::insertDB(Patient patient, Etiology etiology){
    QSqlQuery query;

    if (!query.prepare("insert into person values(:id, :name, :lastname, :genre, :birthdate)"))
        return query.lastError();
    query.bindValue(":id",patient.getNumeroHistoria());
    query.bindValue(":name",patient.getNombre());
    query.bindValue(":lastname",patient.getApellidos());
    query.bindValue(":genre",patient.getGenero());
    query.bindValue(":birthdate",patient.getFechaNacimiento());
    if (!query.exec())
        return query.lastError();

    if (!query.prepare("insert into etiologia values(:etiology, :cause, :valvularPatology)"))
    query.bindValue(":etiology",etiology.getEtiologia());
    query.bindValue(":cause",etiology.getCausa());
    query.bindValue(":valvularPatology",etiology.getPatlogiaValvular());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}

Patient initDB::readDB(QString queryId){
    QSqlQuery query;
    Patient readPatient;
    Etiology readEtiology;

    query.prepare("select * from person where id = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        if (query.next()){
            readPatient.setNumeroHistoria(query.value(0).toString());
            readPatient.setNombre(query.value(1).toString());
            readPatient.setApellidos(query.value(2).toString());
            readPatient.setGenero(query.value(3).toString());
          //  readEtiology.setEtiologia(query.value(4).toString());
          //  readEtiology.setCausa(query.value(5).toString());
          //  readEtiology.setPatologiaValvular(query.value(6).toString());
        }
    }

    return readPatient;
}

QSqlError initDB::updateDB(Patient patient, Etiology etiology){
    QSqlQuery query;

    if (!query.prepare("update person set firstname=:name, lastname=:lastname, genre=:genre, etiology=:etiology, "
                       "cause=:cause, valvularPatology=:valvularPatology"))
        return query.lastError();

    query.bindValue(":name",patient.getNombre());
    query.bindValue(":lastname",patient.getApellidos());
    query.bindValue(":genre",patient.getGenero());
    query.bindValue(":etiology",etiology.getEtiologia());
    query.bindValue(":cause",etiology.getCausa());
    query.bindValue(":valvularPatology",etiology.getPatlogiaValvular());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}
