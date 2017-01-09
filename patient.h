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
    void setEtiologia(QString etiology);
    QString getEtiologia();
    void setCausa(QString cause);
    QString getCausa();
    void setPatologiaValvular(QString patology);
    QString getPatlogiaValvular();
private:
    QString numeroHistoria;
    QString nombre;
    QString apellidos;
    QString etiologia;
    QString causa;
    QString patologiaValvular;
};

#endif // PATIENT_H
