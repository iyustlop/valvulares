#include "patient.h"

Patient::Patient()
{

}

void Patient::setNumeroHistoria(QString nHistoria){
    numeroHistoria = nHistoria;
}

QString Patient::getNumeroHistoria(){
    return numeroHistoria;
}

void Patient::setNombre(QString name){
    nombre = name;
}
QString Patient::getNombre(){
    return nombre;
}

void Patient::setApellidos(QString surname){
    apellidos = surname;
}

QString Patient::getApellidos(){
    return apellidos;
}

void Patient::setEtiologia(QString etiology){
    etiologia = etiology;
}

QString Patient::getEtiologia(){
    return etiologia;
}

void Patient::setCausa(QString cause){
    causa = cause;
}

QString Patient::getCausa(){
    return causa;
}

void Patient::setPatologiaValvular(QString patology){
    patologiaValvular = patology;
}

QString Patient::getPatlogiaValvular(){
    return patologiaValvular;
}
