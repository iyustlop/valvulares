#ifndef PATIENT_H
#define PATIENT_H

#include<QString>

class Patient
{
public:
    Patient();
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

#endif // PATIENT_H
