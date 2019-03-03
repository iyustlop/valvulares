#ifndef ANILLOBEAN_H
#define ANILLOBEAN_H

#include<QString>

class AnilloBean
{
public:
    AnilloBean();

    QString getDateAnillo() const;
    void setDateAnillo(const QString &value);

    QString getTipoAnillo() const;
    void setTipoAnillo(const QString &value);

    QString getGradiente() const;
    void setGradiente(const QString &value);

    QString getLeak() const;
    void setLeak(const QString &value);

private:
    QString dateAnillo;
    QString tipoAnillo;
    QString gradiente;
    QString leak;
};

#endif // ANILLOBEAN_H

