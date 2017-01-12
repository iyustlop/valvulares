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

void Patient::setGenero(QString genre){
    genero = genre;
}

QString Patient::getGenero(){
    return genero;
}

QString Patient::getFechaNacimiento()
{
    return fechaNacimiento;
}

void Patient::setFechaNacimiento(QString birthdate)
{
    fechaNacimiento = birthdate;
}
