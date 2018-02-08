#ifndef AORTABEAN_H
#define AORTABEAN_H

#include<QString>

class AortaBean
{
public:
    AortaBean();
    QString getDate() const;
    void setDate(const QString &value);

    QString getGradAo() const;
    void setGradAo(const QString &value);

    QString getGradMedioAo() const;
    void setGradMedioAo(const QString &value);

    QString getRelacionDeInl() const;
    void setRelacionDeInl(const QString &value);

    QString getAreaAo() const;
    void setAreaAo(const QString &value);

    QString getOReIaO() const;
    void setOReIaO(const QString &value);

    QString getVRiAo() const;
    void setVRiAo(const QString &value);

    QString getVCiAo() const;
    void setVCiAo(const QString &value);

    QString getRelAltJetIao() const;
    void setRelAltJetIao(const QString &value);

    QString getInversionIao() const;
    void setInversionIao(const QString &value);

private:
    QString date;
    QString gradAo;
    QString gradMedioAo;
    QString relacionDeInl;
    QString areaAo;
    QString oReIaO;
    QString vRiAo;
    QString vCiAo;
    QString relAltJetIao;
    QString inversionIao;
};

#endif // AORTABEAN_H
