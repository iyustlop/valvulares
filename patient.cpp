#include "patient.h"

Patient::Patient()
{

}

void Patient::setPersona(Person nPersona){
    persona = nPersona;
}

Person Patient::getPersona(){
    return persona;
}

void Patient::setEtiologia(Etiology nEtiologia){
    etiologia = nEtiologia;
}
Etiology Patient::getEtiologia(){
    return etiologia;
}

