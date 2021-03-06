#ifndef PARAMETROSANALITICOS_H
#define PARAMETROSANALITICOS_H

#include <QString>

class ParametrosAnaliticos
{
public:
    ParametrosAnaliticos();
    QString getHB() const;
    void setHB(const QString &value);

    QString getCreatinina() const;
    void setCreatinina(const QString &value);

    QString getFG() const;
    void setFG(const QString &value);

    QString getProBNP() const;
    void setProBNP(const QString &value);

    QString getPotasio() const;
    void setPotasio(const QString &value);

    QString getTratamiento() const;
    void setTratamiento(const QString &value);

    QString getIndicacionQr() const;
    void setIndicacionQr(const QString &value);

    QString getEuroScore() const;
    void setEuroScore(const QString &value);

private:
    QString HB;
    QString creatinina;
    QString FG;
    QString proBNP;
    QString potasio;
    QString tratamiento;
    QString indicacionQr;
    QString euroScore;


};

#endif // PARAMETROSANALITICOS_H
