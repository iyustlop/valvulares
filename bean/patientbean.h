#ifndef PATIENT_H
#define PATIENT_H

#include<QString>
#include "person.h"
#include "etiology.h"


class PatientBean
{
public:
    PatientBean();
    Person getPersona();
    void setPersona(Person person);
    Etiology getEtiologia();
    void setEtiologia(Etiology etiology);


private:
    Person persona;
    Etiology etiologia;

};

#endif // PATIENT_H
