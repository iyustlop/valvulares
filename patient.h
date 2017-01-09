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
private:
    QString numeroHistoria;
    QString nombre;
    QString apellidos;
};

#endif // PATIENT_H
