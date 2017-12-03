#ifndef ETIOLOGY_H
#define ETIOLOGY_H

#include "protesicdisfunction.h"

#include<QString>
#include<QList>

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
    ProtesicDisfunction getDisfuncionProtesica();
    void setDisfuncionProtesica(ProtesicDisfunction protesicDisfunction);
private:
    QString numeroHistoria;
    QString etiologia;
    QString causa;
    QString patologiaValvular;
    QString mixedVpatology;
    QString valvularPatologySecondary;
    ProtesicDisfunction disfuncionProtesica;
};

#endif // ETIOLOGY_H
