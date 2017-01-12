#ifndef ETIOLOGY_H
#define ETIOLOGY_H

#include<QString>

class Etiology
{
public:
    Etiology();
    void setNumeroHistoria(QString nHistoria);
    QString getNumeroHistoria();
    void setEtiologia(QString etiology);
    QString getEtiologia();
    void setCausa(QString cause);
    QString getCausa();
    void setPatologiaValvular(QString patology);
    QString getPatlogiaValvular();
private:
    QString numeroHistoria;
    QString etiologia;
    QString causa;
    QString patologiaValvular;
};

#endif // ETIOLOGY_H
