#ifndef ERGOBEAN_H
#define ERGOBEAN_H
#include<QString>

class ErgoBean
{
public:
    ErgoBean();
    QString getFechaErgo() const;
    void setFechaErgo(const QString &value);

    QString getTEsfuerzo() const;
    void setTEsfuerzo(const QString &value);

    QString getMets() const;
    void setMets(const QString &value);

private:
    QString fechaErgo;
    QString tEsfuerzo;
    QString mets;
};

#endif // ERGOBEAN_H
