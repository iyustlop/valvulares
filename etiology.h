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
    void setMixedVpatology(QString mixedVpatologia);
    QString getMixedVpatology();
    void setValvularPatologySecondary(QString valvularPatologiaSecundaria);
    QString getValvularPatologySecondary();
private:
    QString numeroHistoria;
    QString etiologia;
    QString causa;
    QString patologiaValvular;
    QString mixedVpatology;
    QString valvularPatologySecondary;
};

#endif // ETIOLOGY_H
