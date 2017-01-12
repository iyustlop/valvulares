#ifndef PATIENT_H
#define PATIENT_H

#include<QString>
#include "person.h"
#include "etiology.h"
#include "protesicdisfunction.h"

class Patient
{
public:
    Patient();
    Person getPersona();
    void setPersona(Person person);
    Etiology getEtiologia();
    void setEtiologia(Etiology etiology);
    ProtesicDisfunction getDisfuncionProtesica();
    void setDisfuncionProtesica(ProtesicDisfunction protesicDisfunction);

private:
    Person persona;
    Etiology etiologia;
    ProtesicDisfunction disfuncionProtesica;
};

#endif // PATIENT_H
