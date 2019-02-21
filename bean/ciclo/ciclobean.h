#ifndef CICLOBEAN_H
#define CICLOBEAN_H

#include<QString>

class CicloBean
{
public:
    CicloBean();
    QString getFechaCiclo() const;
    void setFechaCiclo(const QString &value);

    QString getModalidad() const;
    void setModalidad(const QString &value);

    QString getVo2Indexado() const;
    void setVo2Indexado(const QString &value);

    QString getVo2PicoPredicho() const;
    void setVo2PicoPredicho(const QString &value);

    QString getRer() const;
    void setRer(const QString &value);

    QString getVo2enVa() const;
    void setVo2enVa(const QString &value);

    QString getMorfCurva() const;
    void setMorfCurva(const QString &value);

    QString getEqCo2enVa() const;
    void setEqCo2enVa(const QString &value);

    QString getVslopeCo2() const;
    void setVslopeCo2(const QString &value);

    QString getOues() const;
    void setOues(const QString &value);

    QString getReservVentilatoria() const;
    void setReservVentilatoria(const QString &value);

    QString getVentOscilante() const;
    void setVentOscilante(const QString &value);

private:
    QString fechaCiclo;
    QString modalidad;
    QString vo2Indexado;
    QString vo2PicoPredicho;
    QString rer;
    QString vo2enVa;
    QString morfCurva;
    QString eqCo2enVa;
    QString vslopeCo2;
    QString oues;
    QString reservVentilatoria;
    QString ventOscilante;
};

#endif // CICLOBEAN_H
