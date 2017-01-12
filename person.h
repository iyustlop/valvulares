#ifndef PERSON_H
#define PERSON_H

#include<QString>

class person
{
public:
    person();
    void setNumeroHistoria(QString nHistoria);
    QString getNumeroHistoria();
    void setNombre(QString name);
    QString getNombre();
    void setApellidos(QString surname);
    QString getApellidos();
    void setGenero(QString genre);
    QString getGenero();
    void setFechaNacimiento(QString birthdate);
    QString getFechaNacimiento();

private:
    QString numeroHistoria;
    QString nombre;
    QString apellidos;
    QString genero;
    QString fechaNacimiento;
};

#endif // PERSON_H
