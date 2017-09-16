#ifndef CITA_H
#define CITA_H

#include <QString>

class Cita
{
public:
    Cita();
    QString getFechaConsulta() const;
    void setFechaConsulta(const QString &value);

    QString getRitmo() const;
    void setRitmo(const QString &value);

    QString getGradoFuncional() const;
    void setGradoFuncional(const QString &value);

    QString getFrcv() const;
    void setFrcv(const QString &value);

private:
    QString fechaConsulta;
    QString ritmo;
    QString gradoFuncional;
    QString frcv;
};

#endif // CITA_H
