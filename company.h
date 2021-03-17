#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include <QVector>

class Company
{
private:
    QString name_;
    QVector<QString> owners_;
    double income_;
    double area_;
    int numberOfEmployees_;
    enum type { Private, Public, Multinational, Government };
public:
    virtual type getCompanyType() = 0;
    virtual double getTaxPerMonth() = 0;
};



#endif // COMPANY_H
