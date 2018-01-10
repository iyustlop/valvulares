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
               "FOREIGN KEY(personId) REFERENCES person(id))");
    query.exec("CREATE TABLE parametrosAnaliticos (dateVisitParam varchar(20), "
               "HB varchar(20), "
               "creatinina varchar(20), "
               "FG varchar(20), "
               "proBNP varchar(20), "
               "potasio varchar(20), "
               "FOREIGN KEY(dateVisitParam) REFERENCES cita(dateVisit))");
    query.exec("CREATE TABLE tratamiento (tratamientoId int, "
               "tratamiento varchar(20), "
               "FOREIGN KEY(tratamientoId) REFERENCES cita(visitId))");
    query.exec("CREATE TABLE cirugia (cirugiaId int, "
               "indicacionQuirurgica varchar(20), "
               "euroScore varchar(20), "
               "cirugia varchar(20), "
               "causa varchar(20), "
               "FOREIGN KEY(cirugiaId) REFERENCES cita(visitId))");
    query.exec("CREATE TABLE pruebasDiagnosticasEco (pruebasDiagnosticasEcoId int, "
               "fecha varchar(20), "
               "volumenAuriculaIzquierda varchar(20), "
               "fevi varchar(20), "
               "dilatacionVi varchar(20), "
               "vtdVi varchar(20), "
               "dilatacionVd varchar(20), "
               "tapse varchar(20), "
               "raizAortica varchar(20), "
               "aortaAscecndente varchar(20), "
               "FOREIGN KEY(pruebasDiagnosticasEcoId) REFERENCES person(id))");
    query.exec("CREATE TABLE mitral (mitralId int, "
               "gradienteMedioMitral varchar(20), "
               "avmPorThp varchar(20), "
               "vOndaE varchar(20), "
               "ore varchar(20), "
               "vtdVi varchar(20), "
               "vrVc varchar(20), "
               "inversionSistolicaVvpp varchar(20), "
               "FOREIGN KEY(mitralId) REFERENCES person(id))");
    query.exec("CREATE TABLE aorta (aortaId int, "
               "gradientePicoAo varchar(20), "
               "gradienteMedioAo varchar(20), "
               "relacionDeIntegrales varchar(20), "
               "areaAortica varchar(20), "
               "ore varchar(20), "
               "iao varchar(20), "
               "vrIao varchar(20), "
               "vcIao varchar(20), "
               "relacionAlturaJetIaoItsvi varchar(20), "
               "inversionIao varchar(20), "
               "FOREIGN KEY(aortaId) REFERENCES person(id))");
    query.exec("CREATE TABLE tricuspide (tricuspideId int, "
               "psap varchar(20), "
               "grado varchar(20), "
               "FOREIGN KEY(tricuspideId) REFERENCES person(id))");
    query.exec("CREATE TABLE pulmonar (pulmonarID int, "
               "gradienteMaximo varchar(20), "
               "gradienteMedio varchar(20), "
               "ip varchar(20), "
               "FOREIGN KEY(pruebasDiagnosticasEcoId) REFERENCES person(id))");
    query.exec("CREATE TABLE protesisBiologica (protesisBiologicaId int, "
               "biologica varchar(20), "
               "gradienteMaximo varchar(20), "
               "gradienteMedio varchar(20), "
               "relacionIntegrales varchar(20), "
               "leakPeriprotesico varchar(20), "
               "avmXtHp varchar(20), "
               "FOREIGN KEY(protesisBiologicaId) REFERENCES person(id))");
    query.exec("CREATE TABLE protesisMecanica (protesisMecanicaId int, "
               "mecanica varchar(20), "
               "gradienteMaximo varchar(20), "
               "gradienteMedio varchar(20), "
               "leakPeriprotesico varchar(20), "
               "tAcao varchar(20), "
               "FOREIGN KEY(protesisMecanicaId) REFERENCES person(id))");
    query.exec("CREATE TABLE anillo (anilloId int, "
               "posicion varchar(20), "
               "gradienteMedio varchar(20), "
               "leakPeriprotesico varchar(20), "
               "FOREIGN KEY(anilloId) REFERENCES person(id))");
    query.exec("CREATE TABLE resonancia (resonanciaId int, "
               "nivelIao varchar(20), "
               "raizAorta varchar(20), "
               "aortaAscendente varchar(20), "
               "realceTardio varchar(20), "
               "descripcion varchar(20), "
               "FOREIGN KEY(anilloId) REFERENCES person(id))");
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
        if (!query.prepare("insert into protesicDisfunction values(:protesicDisfunctionID, :causa, :protesis, "
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
    Person readPerson;
    Etiology readEtiology;
    ProtesicDisfunction readProtesicDisfunction;

    query.prepare("select * from person "
                  "left join etiology on person.id = etiology.etiologyid "
                  "left join protesicDisfunction on protesicDisfunction.disfuncionId = person.id "
                  "where person.id = :id");

    query.bindValue(":id",queryId);

    if(query.exec()){
        if (query.next()){
            readPerson.setNumeroHistoria(query.value(0).toString());
            readPerson.setNombre(query.value(1).toString());
            readPerson.setApellidos(query.value(2).toString());
            readPerson.setGenero(query.value(3).toString());
            readPerson.setFechaNacimiento(query.value(4).toString());
            readEtiology.setEtiologia(query.value(6).toString());
            readEtiology.setCausa(query.value(7).toString());
            readEtiology.setPatologiaValvular(query.value(8).toString());
            readEtiology.setMixedVpatology(query.value(9).toString());
            readEtiology.setValvularPatologySecondary(query.value(10).toString());

            if (readEtiology.getPatlogiaValvular() == "Disfunción Protésica"){
                readProtesicDisfunction.setCausa(query.value(12).toString());
                readProtesicDisfunction.setProtesis(query.value(13).toString());
                readProtesicDisfunction.setModelo(query.value(14).toString());
                readProtesicDisfunction.setNumero(query.value(15).toString());
                readProtesicDisfunction.setFechaCirugia(query.value(16).toString());
            }
        }
    }

    readPaciente.setPersona(readPerson);
    readEtiology.setDisfuncionProtesica(readProtesicDisfunction);
    readPaciente.setEtiologia(readEtiology);
    return readPaciente;
}

QList<visit> initDB::readVisitaDB(QString queryId){
    QSqlQuery query;

    visit readVisita;
    QList<visit> readVisitas;
    Cita readCita;
    ParametrosAnaliticos readParametrosAnaliticos;

    query.prepare("select c.dateVisit, c.rhythm, c.functionalGrade, c.FRCV, pa.dateVisitParam, pa.HB, pa.creatinina, pa.FG, pa.proBNP, pa.potasio "
                  "FROM cita c "
                  "INNER join parametrosAnaliticos pa on c.dateVisit = pa.dateVisitParam "
                  "WHERE c.personId = :id");
    query.bindValue(":id",queryId);

    if(query.exec()){
        while (query.next()){
            readCita.setFechaConsulta(query.value(0).toString());
            readCita.setRitmo(query.value(1).toString());
            readCita.setGradoFuncional(query.value(2).toString());
            readCita.setFrcv(query.value(3).toString());
            readParametrosAnaliticos.setHB(query.value(5).toString());
            readParametrosAnaliticos.setCreatinina(query.value(6).toString());
            readParametrosAnaliticos.setFG(query.value(7).toString());
            readParametrosAnaliticos.setProBNP(query.value(8).toString());
            readParametrosAnaliticos.setPotasio(query.value(9).toString());

            readVisita.setCita(readCita);
            readVisita.setParametrosAnaliticos(readParametrosAnaliticos);

            readVisitas.append(readVisita);
        }
    }

    return readVisitas;
}

QSqlError initDB::updateDB(Patient paciente){
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
    query.bindValue(":nacimiento",persona.getFechaNacimiento());

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


