#ifndef RESONANCIA_H
#define RESONANCIA_H

#include<QString>

class ResonanciaBean
{
public:
    ResonanciaBean();
    QString getFevi() const;
    void setFevi(const QString &value);

    QString getVtdVi() const;
    void setVtdVi(const QString &value);

    QString getDilataVi() const;
    void setDilataVi(const QString &value);

    QString getDilataVd() const;
    void setDilataVd(const QString &value);

    QString getFracRegValMit() const;
    void setFracRegValMit(const QString &value);

    QString getFracRegValAo() const;
    void setFracRegValAo(const QString &value);

    QString getRaizAo() const;
    void setRaizAo(const QString &value);

    QString getAoAscend() const;
    void setAoAscend(const QString &value);

    QString getRealceTardio() const;
    void setRealceTardio(const QString &value);

    QString getVarios() const;
    void setVarios(const QString &value);

    QString getFechaReso() const;
    void setFechaReso(const QString &value);

private:
    QString fechaReso;
    QString fevi;
    QString vtdVi;
    QString dilataVi;
    QString dilataVd;
    QString fracRegValMit;
    QString fracRegValAo;
    QString raizAo;
    QString aoAscend;
    QString realceTardio;
    QString varios;
};

#endif // RESONANCIA_H


