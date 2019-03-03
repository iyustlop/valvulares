#ifndef PROTESISBIOLOGICA_H
#define PROTESISBIOLOGICA_H

#include<QString>

class ProtesisBiologicaBean
{
public:
    ProtesisBiologicaBean();
    QString getDateProtesisBiologica() const;
    void setDateProtesisBiologica(const QString &value);

    QString getTipoProtesisBiologica() const;
    void setTipoProtesisBiologica(const QString &value);

    QString getGradienteMax() const;
    void setGradienteMax(const QString &value);

    QString getGradienteMed() const;
    void setGradienteMed(const QString &value);

    QString getRi() const;
    void setRi(const QString &value);

    QString getLeak() const;
    void setLeak(const QString &value);

private:
    QString dateProtesisBiologica;
    QString tipoProtesisBiologica;
    QString gradienteMax;
    QString gradienteMed;
    QString ri;
    QString leak;
};

#endif // PROTESISBIOLOGICA_H
