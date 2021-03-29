#include <QCoreApplication>
#include <QTextStream>
#include "companyregistry.h"



void getInfoByType(Company::type tp, CompanyRegistry& cr, QTextStream& out)
{
    switch (tp) {
    case Company::type::Private:
        out << "Private companies: " << Qt::endl;
        break;
    case Company::type::Multinational:
        out << "Multinational companies: " << Qt::endl;
        break;
    case Company::type::Government:
        out << "Government companies: " << Qt::endl;
        break;
    }
    for (int i = 0; i < cr.getRegistrySize(); i++) {
        if (cr.getCompanyByIndex(i)->getCompanyType() == tp) {
            out << "Name: " << cr.getCompanyByIndex(i)->getCompanyName() << Qt::endl;
            out << "Owners: ";
            for (int j = 0; j < cr.getCompanyByIndex(i)->getCompanyOwners().size(); j++)
            {
                out << cr.getCompanyByIndex(i)->getCompanyOwners().operator[](j);
                if (j != cr.getCompanyByIndex(i)->getCompanyOwners().size() - 1)
                    out << ", ";
            }
            out << Qt::endl;
            out << "Income: " << cr.getCompanyByIndex(i)->getIncome() << Qt::endl;
            out << "Area: " << cr.getCompanyByIndex(i)->getArea() << Qt::endl;
            out << "Number of employees: " << cr.getCompanyByIndex(i)->getNumberOfEmployess() << Qt::endl;
        }
    }
}
void getAverageValues(Company::type tp, CompanyRegistry& cr, QTextStream& out)
{
    int n = 0;
    float sumIncome = 0;
    float sumArea = 0;
    float sumNumberOfEmployees = 0;
    for (int i = 0; i < cr.getRegistrySize(); i++) {
        if (tp == cr.getCompanyByIndex(i)->getCompanyType()) {
            sumIncome += cr.getCompanyByIndex(i)->getIncome();
            sumArea += cr.getCompanyByIndex(i)->getArea();
            sumNumberOfEmployees += cr.getCompanyByIndex(i)->getNumberOfEmployess();
            n++;
        }
    }
    out << "Average income = " << sumIncome / n << Qt::endl;
    out << "Average area = " << sumArea / n << Qt::endl;
    out << "Average number of employees = " << sumNumberOfEmployees / n << Qt::endl;
}

void getCompaniesByOwner(QString&& owner, CompanyRegistry& cr, QTextStream& out)
{
    bool found = false;
    if (!owner.isEmpty()) {
        int companies_per_owner = 0;
        for (int i = 0; i < cr.getRegistrySize(); i++) {
            for (int j = 0; j < cr.getCompanyByIndex(i)->getCompanyOwners().size(); j++) {
                if (owner == cr.getCompanyByIndex(i)->getCompanyOwners().at(j)) {
                    if (companies_per_owner > 0)
                        out << ", " << cr.getCompanyByIndex(i)->getCompanyName();
                    else
                        out << owner << " owns " << cr.getCompanyByIndex(i)->getCompanyName();
                    companies_per_owner++;
                    found = true;
                }
            }
        }
    }
    if (!found)
        out << "Nothing found!";
    out << Qt::endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);
    /* Initializing Microsoft data */
    QVector<QString> mowners;
    QString mname = "Microsoft";
    mowners.append(QString::fromUtf8("Bill Gates"));
    mowners.append(QString::fromUtf8("Paul Allen"));
    Company* mc = new MultinationalCompany(mname, mowners, 100000, 40000, 300);
    /* Initializing Skype data */
    QVector<QString> sowners;
    QString sname = "Skype";
    sowners.append(QString::fromUtf8("Bill Gates"));
    Company* pc1 = new PrivateCompany(sname, sowners, 40000, 10000, 250);
    /* Initializing IKEA data */
    QVector<QString> iowners;
    QString iname = "IKEA";
    iowners.append(QString::fromUtf8("Ingvar Kamprad"));
    Company* pc2 = new PrivateCompany(iname, iowners, 60000, 20000, 450);
    /* Initializing Gazprom data */
    QVector<QString> gowners;
    QString gname = "Gazprom";
    gowners.append(QString::fromUtf8("Alexey Miller"));
    Company* gc = new GovernmentCompany(gname, gowners, 80000, 40000, 300);


    CompanyRegistry& cr = CompanyRegistry::getInstance();
    cr.AddCompany(*mc);
    cr.AddCompany(*pc1);
    cr.AddCompany(*pc2);
    cr.AddCompany(*gc);

    // 1. Вывести в консоль информацию о предприятиях определённого типа.
    getInfoByType(Company::type::Multinational, cr, out);
    // 2. Вывести в консоль все предприятия, принадлежащие определённому владельцу.
    out << Qt::endl;
    getCompaniesByOwner(QString::fromUtf8("Bill Gates"), cr, out);
    // 3. Вывести в консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.
    out << Qt::endl;
    getAverageValues(Company::type::Private, cr, out);

    delete mc;
    delete pc1;
    delete pc2;
    delete gc;
    return app.exec();
}
