#include "patientbean.h"

PatientBean::PatientBean()
{

}

void PatientBean::setPersona(Person nPersona){
    persona = nPersona;
}

Person PatientBean::getPersona(){
    return persona;
}

void PatientBean::setEtiologia(Etiology nEtiologia){
    etiologia = nEtiologia;
}
Etiology PatientBean::getEtiologia(){
    return etiologia;
}

