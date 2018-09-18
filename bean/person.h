#ifndef PERSON_H
#define PERSON_H

#include<QString>

class Person
{
public:
    Person();
    void setNumeroHistoria(QString nHistoria);
    QString getNumeroHistoria();
    void setNombre(QString name);
    QString getNombre();
    void setApellidos(QString surname);
    QString getApellidos();
    void setGenero(QString genre);
    QString getGenero();
    void setEdad(QString age);
    QString getEdad();

private:
    QString numeroHistoria;
    QString nombre;
    QString apellidos;
    QString genero;
    QString edad;
};

#endif // PERSON_H
