#include "companyregistry.h"

CompanyRegistry& CompanyRegistry::getInstance(const QList<Company* >& cl)
{
    static CompanyRegistry instance;  
    return instance;
}

void CompanyRegistry::AddCompany(Company& c)
{
    companylist_.append(&c);
}

Company* CompanyRegistry::getCompanyByIndex(int index) const
{
    return companylist_.at(index);
}

int CompanyRegistry::getRegistrySize() const
{
    return companylist_.size();
}
