#ifndef PROTESISMECANICA_H
#define PROTESISMECANICA_H

#include<QString>

class ProtesisMecanicaBean
{
public:
    ProtesisMecanicaBean();


    QString getDateProtesisMecanica() const;
    void setDateProtesisMecanica(const QString &value);

    QString getTipoProtesisMecanica() const;
    void setTipoProtesisMecanica(const QString &value);

    QString getGradienteMax() const;
    void setGradienteMax(const QString &value);

    QString getGradienteMed() const;
    void setGradienteMed(const QString &value);

    QString getTAcenAo() const;
    void setTAcenAo(const QString &value);

    QString getLeak() const;
    void setLeak(const QString &value);

private:
    QString dateProtesisMecanica;
    QString tipoProtesisMecanica;
    QString gradienteMax;
    QString gradienteMed;
    QString tAcenAo;
    QString leak;
};

#endif // PROTESISMECANICA_H

