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
