#include <QCoreApplication>
#include <QTextStream>
#include "company.h"

void getCompanyInfo(Company& c, QTextStream& out)
{
    switch (c.getCompanyType()) {
    case Company::type::Private:
        out << "Type: Private" << Qt::endl;
        break;
    case Company::type::Multinational:
        out << "Type: Multinational" << Qt::endl;
        break;
    case Company::type::Government:
        out << "Type: Government" << Qt::endl;
        break;
    }
    out << "Tax: " << c.getTaxPerMonth() << Qt::endl;
    out << "Name: " << c.getCompanyName() << Qt::endl;
    out << "Owners: ";
    for (size_t i = 0; i < c.getCompanyOwners().size(); i++)
    {
        out << c.getCompanyOwners().operator[](i);
        if (i != c.getCompanyOwners().size() - 1)
            out << ", ";
    }
    out << Qt::endl;
    out << "Income: " << c.getIncome() << Qt::endl;
    out << "Area: " << c.getArea() << Qt::endl;
    out << "Number of employees: " << c.getNumberOfEmployess() << Qt::endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);
    QVector<QString> ownersm;
    QString namem = "Microsoft";
    ownersm.append(QString::fromUtf8("Bill Gates"));
    ownersm.append(QString::fromUtf8("Steve Jobs"));

    PrivateCompany pc(namem, ownersm, 100000, 40000, 300);
    getCompanyInfo(pc, out);

    return app.exec();
}
