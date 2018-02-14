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

    QString getDateTri() const;
    void setDateTri(const QString &value);

private:
    QString dateTri;
    QString psap;
    QString grado;
};

#endif // TRIBEAN_H
