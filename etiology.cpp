#include "etiology.h"

Etiology::Etiology()
{

}

void Etiology::setEtiologia(QString etiology){
    etiologia = etiology;
}

QString Etiology::getEtiologia(){
    return etiologia;
}

void Etiology::setCausa(QString cause){
    causa = cause;
}

QString Etiology::getCausa(){
    return causa;
}

void Etiology::setPatologiaValvular(QString patology){
    patologiaValvular = patology;
}

QString Etiology::getPatlogiaValvular(){
    return patologiaValvular;
}
