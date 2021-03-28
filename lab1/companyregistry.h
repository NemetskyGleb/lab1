#ifndef COMPANY_REGISTRY_H
#define COMPANY_REGISTRY_H
#include <QList>
#include "company.h"
/**
 * @brief Реестр предприятий представляет собой класс Singleton,
 *   содержащий список (QList) предприятий и методы, необходимые для работы со списком:
 * - добавление/удаление предприятия;
 * - получение предприятия по индексу;
 * - получение размера реестра (числа предприятий)
 */
class CompanyRegistry 
{
private:
    QList<Company* > companylist_; 
    CompanyRegistry(const QList<Company* >& cl) : companylist_(cl) {}
public:
    CompanyRegistry() {}
    CompanyRegistry(CompanyRegistry& other) = delete;
    void operator=(const CompanyRegistry& cr) = delete;
    static CompanyRegistry& getInstance(const QList<Company* >& cl);
    void AddCompany(Company& c);
    Company* getCompanyByIndex(int index) const;
    int getRegistrySize() const;
};

#endif //COMPANY_REGISTRY_H
