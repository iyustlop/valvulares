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
    query.exec("create table person (id int primary key, "
               "name varchar(20), "
               "lastname varchar(20), "
               "genre varchar(20), "
               "birthdate varchar(20))");
    query.exec("create table etiology (etiologyId int, "
               "etiology varchar(20), "
               "cause varchar(20), "
               "valvularPatology varchar(20), "
               "mixedVpatology varchar(5), "
               "valvularPatologySecondary varchar(20),"
               "FOREIGN KEY(etiologyId) REFERENCES person(id))");
    query.exec("create table prosesicDisfunction (disfuncionId int, "
               "causa varchar(20), "
               "protesis varchar(20), "
               "modelo varchar(20), "
               "numero varchar(20), "
               "fechaCirugia varchar(20), "
               "FOREIGN KEY(disfuncionId) REFERENCES person(id))");

    return QSqlError();
}

QSqlError initDB::insertDB(Patient paciente){

    Person persona;
    Etiology etiologia;
    ProtesicDisfunction disfuncionProtesica;

    persona = paciente.getPersona();
    etiologia = paciente.getEtiologia();
    disfuncionProtesica = etiologia.getDisfuncionProtesica();

    QSqlQuery query;

    if (!query.prepare("insert into person values(:id, :name, :lastname, :genre, :birthdate)"))
        return query.lastError();
    query.bindValue(":id",persona.getNumeroHistoria());
    query.bindValue(":name",persona.getNombre());
    query.bindValue(":lastname",persona.getApellidos());
    query.bindValue(":genre",persona.getGenero());
    query.bindValue(":birthdate",persona.getFechaNacimiento());
    if (!query.exec())
        return query.lastError();

    if (!query.prepare("insert into etiology values(:etiologyId,:etiology, :cause, :valvularPatology, "
                       ":mixedVpatology, :valvularPatologySecondary)"))
        return query.lastError();
    query.bindValue(":etiologyId",persona.getNumeroHistoria());
    query.bindValue(":etiology",etiologia.getEtiologia());
    query.bindValue(":cause",etiologia.getCausa());
    query.bindValue(":valvularPatology",etiologia.getPatlogiaValvular());
    query.bindValue(":mixedVpatology", etiologia.getMixedVpatology());
    query.bindValue(":valvularPatologySecondary",etiologia.getValvularPatologySecondary());

    if (!query.exec())
        return query.lastError();

    if (etiologia.getPatlogiaValvular() == "Disfunción Protésica"){
        if (!query.prepare("insert into prosesicDisfunction values(:protesicDisfunctionID,:causa, :protesis, "
                           ":modelo, :numero, :fechaCirugia)"))
            return query.lastError();
        query.bindValue(":protesicDisfunctionID",persona.getNumeroHistoria());
        query.bindValue(":causa",disfuncionProtesica.getCausa());
        query.bindValue(":protesis",disfuncionProtesica.getProtesis());
        query.bindValue(":modelo",disfuncionProtesica.getModelo());
        query.bindValue(":numero", disfuncionProtesica.getNumero());
        query.bindValue(":fechaCirugia",disfuncionProtesica.getFechaCirugia());

        if (!query.exec())
            return query.lastError();
    }

    return QSqlError();
}

Patient initDB::readDB(QString queryId){
    QSqlQuery query;

    Patient readPaciente;
    Person readPatient;
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

    return readPaciente;
}

QSqlError initDB::updateDB(Patient paciente){
    QSqlQuery query;

    Person persona;
    Etiology etiologia;

    persona = paciente.getPersona();
    etiologia = paciente.getEtiologia();

    if (!query.prepare("update person set firstname=:name, lastname=:lastname, genre=:genre, etiology=:etiology, "
                       "cause=:cause, valvularPatology=:valvularPatology"))
        return query.lastError();

    query.bindValue(":name",persona.getNombre());
    query.bindValue(":lastname",persona.getApellidos());
    query.bindValue(":genre",persona.getGenero());
    query.bindValue(":etiology",etiologia.getEtiologia());
    query.bindValue(":cause",etiologia.getCausa());
    query.bindValue(":valvularPatology",etiologia.getPatlogiaValvular());

    if (!query.exec())
        return query.lastError();

    return QSqlError();
}
