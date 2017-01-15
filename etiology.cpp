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

void Etiology::setNumeroHistoria(QString nHistoria){
    numeroHistoria = nHistoria;
}

QString Etiology::getNumeroHistoria(){
    return numeroHistoria;
}

void Etiology::setPatologiaValvular(QString patology){
    patologiaValvular = patology;
}

QString Etiology::getPatlogiaValvular(){
    return patologiaValvular;
}

QString Etiology::getValvularPatologySecondary()
{
    return valvularPatologySecondary;
}

void Etiology::setValvularPatologySecondary(QString valvularPatologiaSecundaria)
{
    valvularPatologySecondary = valvularPatologiaSecundaria;
}

QString Etiology::getMixedVpatology()
{
    return mixedVpatology;
}

void Etiology::setMixedVpatology(QString mixedVpatologia)
{
    mixedVpatology = mixedVpatologia;
}

ProtesicDisfunction Etiology::getDisfuncionProtesica()
{
    return disfuncionProtesica;
}

void Etiology::setDisfuncionProtesica(ProtesicDisfunction disfunctionP)
{
    disfuncionProtesica = disfunctionP;
}
