#include "initdb.h"

#include <QMessageBox>

InitDb::InitDb()
{

}

QSqlError InitDb::startDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString dataBaseLocation = QDir::currentPath();

    db.setDatabaseName(dataBaseLocation+"/valvulares.db");

    if (!db.open())
        return db.lastError();

    QSqlQuery query;      
    // Avoid error trying to create the table.
    query.exec("CREATE TABLE person (id INTEGER PRIMARY KEY, "
               "name varchar(20), "
               "lastname varchar(20), "
               "genre varchar(20), "
               "birthdate varchar(20))");
    query.exec("CREATE UNIQUE INDEX idx_id ON person(id)");
    query.exec("CREATE TABLE etiology (etiologyId int, "
               "etiology varchar(20), "
               "cause varchar(20), "
               "valvularPatology varchar(20), "
               "mixedVpatology varchar(5), "
               "valvularPatologySecondary varchar(20),"
               "FOREIGN KEY(etiologyId) REFERENCES person(id))");
    query.exec("CREATE TABLE protesicDisfunction (disfuncionId int, "
               "causa varchar(20), "
               "protesis varchar(20), "
               "modelo varchar(20), "
               "numero varchar(20), "
               "fechaCirugia varchar(20), "
               "FOREIGN KEY(disfuncionId) REFERENCES person(id))");
    query.exec("CREATE TABLE cita (visitId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateVisit varchar(20), "
               "rhythm varchar(20), "
               "functionalGrade varchar(20), "
               "FRCV varchar(20), "               
               "HB varchar(20), "
               "creatinina varchar(20), "
               "FG varchar(20), "
               "proBNP varchar(20), "
               "potasio varchar(20), "                                 
               "indicacionQuirurgica varchar(20), "
               "euroScore varchar(20), "
               "tratamiento varchar(40), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE pruebasDiagnosticasEco (pruebasDiagnosticasEcoId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateEco varchar(20), "
               "volumenAuriculaIzquierda varchar(20), "
               "fevi varchar(20), "
               "dilatacionVi varchar(20), "
               "vtdVi varchar(20), "
               "dilatacionVd varchar(20), "
               "tapse varchar(20), "
               "raizAortica varchar(20), "
               "aortaAscecndente varchar(20), "
               "FOREIGN KEY(pruebasDiagnosticasEcoId) REFERENCES person(id))");
    query.exec("CREATE TABLE pruebasDiagnosticasReso (pruebasDiagnosticasResoId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateReso varchar(20), "
               "fevi varchar(20), "
               "vtvdi varchar(20), "
               "dilatacionVi varchar(20), "
               "dilatacionVd varchar(20), "
               "fracRegMit varchar(20), "
               "fracRegAo varchar(20), "
               "raizAortica varchar(20), "
               "aortaAscecndente varchar(20), "
               "realceTardio varchar(20), "
               "varios varchar(20), "
               "FOREIGN KEY(pruebasDiagnosticasResoId) REFERENCES person(id))");
    query.exec("CREATE TABLE pruebasDiagnosticasCiclo (pruebasDiagnosticasCicloId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateCiclo varchar(20), "
               "fevi varchar(20), "
               "modalidad varchar(20), "
               "vo2indexado varchar(20), "
               "vo2picoperdicho varchar(20), "
               "rer varchar(20), "
               "vo2enVa varchar(20), "
               "morfCurva varchar(20), "
               "EqCo2enVa varchar(20), "
               "vslopeCo2 varchar(20), "
               "oues varchar(20), "
               "reservaVent varchar(20), "
               "ventOscilante varchar(20), "
               "FOREIGN KEY(pruebasDiagnosticasCicloId) REFERENCES person(id))");
    query.exec("CREATE TABLE mitral (mitralId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateMitral varchar(20), "
               "gradienteMedioMitral varchar(20), "
               "avmPorThp varchar(20), "
               "vOndaE varchar(20), "
               "ore varchar(20), "
               "vR varchar(20), "
               "vC varchar(20), "
               "inversionSistolicaVvpp varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE aorta (aortaId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateAorta varchar(20), "
               "gradientePicoAo varchar(20), "
               "gradienteMedioAo varchar(20), "
               "relacionDeIntegrales varchar(20), "
               "areaAortica varchar(20), "
               "ore varchar(20), "
               "vrIao varchar(20), "
               "vcIao varchar(20), "
               "relacionAlturaJetIaoItsvi varchar(20), "
               "inversionIao varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE tricuspide (tricuspideId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateTri varchar(20), "
               "psap varchar(20), "
               "grado varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE pulmonar (pulmonarID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "datePulmonar varchar(20), "
               "gradienteMaximo varchar(20), "
               "gradienteMedio varchar(20), "
               "ip varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE protesisBiologica (protesisBiologicaId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateAorta varchar(20), "
               "biologica varchar(20), "
               "gradienteMaximo varchar(20), "
               "gradienteMedio varchar(20), "
               "relacionIntegrales varchar(20), "
               "leakPeriprotesico varchar(20), "
               "avmXtHp varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE protesisMecanica (protesisMecanicaId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateAorta varchar(20), "
               "mecanica varchar(20), "
               "gradienteMaximo varchar(20), "
               "gradienteMedio varchar(20), "
               "leakPeriprotesico varchar(20), "
               "tAcao varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE anillo (anilloId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateAorta varchar(20), "
               "posicion varchar(20), "
               "gradienteMedio varchar(20), "
               "leakPeriprotesico varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE resonancia (resonanciaId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
               "personId int, "
               "dateAorta varchar(20), "
               "nivelIao varchar(20), "
               "raizAorta varchar(20), "
               "aortaAscendente varchar(20), "
               "realceTardio varchar(20), "
               "descripcion varchar(20), "
               "FOREIGN KEY(personId) REFERENCES person(id))");
    return QSqlError();
}

QSqlError InitDb::updateDB(PatientBean paciente){
    QSqlQuery query;

    Person persona;
    Etiology etiologia;
    ProtesicDisfunction disfuncionProtesica;

    persona = paciente.getPersona();
    etiologia = paciente.getEtiologia();
    disfuncionProtesica = etiologia.getDisfuncionProtesica();

    if (!query.prepare("update person "
                       "set name=:name, lastname=:lastname, genre=:genre, birthdate=:nacimiento "
                       "where id=:myId;"))
        return query.lastError();
    query.bindValue(":myId",persona.getNumeroHistoria());
    query.bindValue(":name",persona.getNombre());
    query.bindValue(":lastname",persona.getApellidos());
    query.bindValue(":genre",persona.getGenero());
    query.bindValue(":nacimiento",persona.getEdad());

    if (!query.exec())
        return query.lastError();

    if (!query.prepare("update etiology "
                       "set etiology=:etiologia, cause=:causa, valvularPatology=:patologiaValvular, "
                       "mixedVpatology=:combinada, valvularPatologySecondary=:secundaria "
                       "where etiologyId=:myId;"))
        return query.lastError();
    query.bindValue(":myId",persona.getNumeroHistoria());
    query.bindValue(":etiologia",etiologia.getEtiologia());
    query.bindValue(":causa",etiologia.getCausa());
    query.bindValue(":patologiaValvular",etiologia.getPatlogiaValvular());
    query.bindValue(":combinada",etiologia.getMixedVpatology());
    query.bindValue(":secundaria",etiologia.getValvularPatologySecondary());

    if (!query.exec())
        return query.lastError();

    if (etiologia.getPatlogiaValvular()=="Disfunción Protésica"){

        if (!query.prepare("update protesicDisfunction "
                           "set causa=:cause, protesis=:myProtesis, modelo=:model, numero=:number, "
                           "fechaCirugia=:surgueryDate "
                           "where disfuncionId=:myId;"))
            return query.lastError();

        query.bindValue(":myId",persona.getNumeroHistoria());
        query.bindValue(":cause",disfuncionProtesica.getCausa());
        query.bindValue(":myProtesis",disfuncionProtesica.getProtesis());
        query.bindValue(":model",disfuncionProtesica.getModelo());
        query.bindValue(":number",disfuncionProtesica.getNumero());
        query.bindValue(":surgueryDate",disfuncionProtesica.getFechaCirugia());

        if (!query.exec())
            return query.lastError();
    }

    return QSqlError();
}


