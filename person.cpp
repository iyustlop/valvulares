#include "person.h"

Person::Person()
{

}

void Person::setNumeroHistoria(QString nHistoria){
    numeroHistoria = nHistoria;
}

QString Person::getNumeroHistoria(){
    return numeroHistoria;
}

void Person::setNombre(QString name){
    nombre = name;
}
QString Person::getNombre(){
    return nombre;
}

void Person::setApellidos(QString surname){
    apellidos = surname;
}

QString Person::getApellidos(){
    return apellidos;
}

void Person::setGenero(QString genre){
    genero = genre;
}

QString Person::getGenero(){
    return genero;
}

QString Person::getFechaNacimiento()
{
    return fechaNacimiento;
}

void Person::setFechaNacimiento(QString birthdate)
{
    fechaNacimiento = birthdate;
}

