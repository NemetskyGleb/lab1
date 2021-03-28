#include "company.h"


Company::Company(QString &name, QVector<QString> &owners, double income, double area, int numOfEmps)
{
    name_ = name;
    owners_ = owners;
    income_ = income;
    area_ = area;
    numberOfEmployees_ = numOfEmps;
}


Company::type PrivateCompany::getCompanyType()
{
    return type::Private;
}

PrivateCompany::PrivateCompany(QString &name, QVector<QString> &owners,
                               double income, double area, int numberOfEmployees)
                               : Company(name, owners, income, area, numberOfEmployees) {}

double PrivateCompany::getTaxPerMonth()
{
    return getNumberOfEmployess() * getArea() / getIncome() * 2.5;
}


MultinationalCompany::MultinationalCompany(QString &name, QVector<QString> &owners,
                               double income, double area, int numberOfEmployees)
                               : Company(name, owners, income, area, numberOfEmployees) {}

Company::type MultinationalCompany::getCompanyType()
{
    return type::Multinational;
}

double MultinationalCompany::getTaxPerMonth()
{
    return getNumberOfEmployess() * getArea() / getIncome() * 3;
}


GovernmentCompany::GovernmentCompany(QString &name, QVector<QString> &owners,
                               double income, double area, int numberOfEmployees)
                               : Company(name, owners, income, area, numberOfEmployees) {}

Company::type GovernmentCompany::getCompanyType()
{
    return type::Government;
}

double GovernmentCompany::getTaxPerMonth()
{
    return getNumberOfEmployess() * getArea() / getIncome() * 1;
}
