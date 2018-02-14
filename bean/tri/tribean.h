#ifndef TRIBEAN_H
#define TRIBEAN_H

#include<QString>

class TriBean
{
public:
    TriBean();

    QString getPsap() const;
    void setPsap(const QString &value);

    QString getGrado() const;
    void setGrado(const QString &value);

private:
    QString psap;
    QString grado;
};

#endif // TRIBEAN_H
