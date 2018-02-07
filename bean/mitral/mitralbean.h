#ifndef MITRALBEAN_H
#define MITRALBEAN_H

#include<QString>

class MitralBean
{
public:
    MitralBean();
    QString getGrdMedio() const;
    void setGrdMedio(const QString &value);

    QString getAvmXtmp() const;
    void setAvmXtmp(const QString &value);

    QString getVOndaE() const;
    void setVOndaE(const QString &value);

    QString getORe() const;
    void setORe(const QString &value);

    QString getVR() const;
    void setVR(const QString &value);

    QString getVC() const;
    void setVC(const QString &value);

    QString getInvSistolicaVvpp() const;
    void setInvSistolicaVvpp(const QString &value);

    QString getFecha() const;
    void setFecha(const QString &value);

private:
    QString fecha;
    QString grdMedio;
    QString avmXtmp;
    QString vOndaE;
    QString oRe;
    QString vR;
    QString vC;
    QString invSistolicaVvpp;
};

#endif // MITRALBEAN_H
