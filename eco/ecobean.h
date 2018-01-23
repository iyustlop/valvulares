#ifndef ECO_H
#define ECO_H

#include<QString>

class ecoBean
{
public:
    ecoBean();
    QString getVolAi() const;
    void setVolAi(const QString &value);

    QString getFevi() const;
    void setFevi(const QString &value);

    QString getRaizAo() const;
    void setRaizAo(const QString &value);

    QString getAoAscend() const;
    void setAoAscend(const QString &value);

    QString getDilataVi() const;
    void setDilataVi(const QString &value);

    QString getDilataVd() const;
    void setDilataVd(const QString &value);

    QString getTapse() const;
    void setTapse(const QString &value);

    QString getFechaEco() const;
    void setFechaEco(const QString &value);

private:
    QString fechaEco;
    QString volAi;
    QString fevi;
    QString raizAo;
    QString aoAscend;
    QString dilataVi;
    QString dilataVd;
    QString tapse;
};

#endif // ECO_H
