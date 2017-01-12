#ifndef PROTESICDISFUNCTION_H
#define PROTESICDISFUNCTION_H

#include<QString>

class ProtesicDisfunction
{
public:
    ProtesicDisfunction();
    QString getCausa();
    void setCausa(QString cause);

    QString getProtesis();
    void setProtesis(QString nProtesis);

    QString getModelo();
    void setModelo(QString model);

    QString getNumero();
    void setNumero(QString number);

    QString getFechaCirugia();
    void setFechaCirugia(QString surgeonDate);

private:
    QString numeroHistoria;
    QString causa;
    QString protesis;
    QString modelo;
    QString numero;
    QString fechaCirugia;
};

#endif // PROTESICDISFUNCTION_H
