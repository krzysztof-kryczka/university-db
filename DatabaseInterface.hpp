#pragma once
#include <functional>
#include <memory>
#include <vector>

class Person;
using PersonType = std::shared_ptr<Person>;

class DatabaseInterface {
public:
    DatabaseInterface() {}
    virtual ~DatabaseInterface() = default;

    [[nodiscard]] virtual bool addPerson(const PersonType& person) = 0;

    virtual void printById(size_t id) const = 0;
    virtual void printAll() const = 0;

    virtual void saveToFile(const std::string& fileName) const = 0;
    virtual void loadFromFile(const std::string& fileName) = 0;

    [[nodiscard]] virtual std::vector<PersonType> searchByPesel(const std::string& pesel) const = 0;
    [[nodiscard]] virtual std::vector<PersonType> searchByFirstName(const std::string& firstName) const = 0;
    [[nodiscard]] virtual std::vector<PersonType> searchBySurName(const std::string& surName) const = 0;
    [[nodiscard]] virtual std::vector<PersonType> searchByStreet(const std::string& street) const = 0;
    [[nodiscard]] virtual std::vector<PersonType> searchByCity(const std::string& city) const = 0;

    virtual void sortByPesel(std::function<bool(const std::string&, const std::string&)> compare) = 0;
    virtual void sortBySurName(std::function<bool(const std::string&, const std::string&)> compare) = 0;
    virtual void sortByIncome(std::function<bool(const size_t&, const size_t&)> compare) = 0;

    virtual void deleteByPesel(const std::string& pesel) = 0;
    virtual void deleteByIndex(size_t indexNumber) = 0;
    virtual void deleteByFirstName(const std::string& FirstName) = 0;
    virtual void deleteBySurName(const std::string& SurName) = 0;

    virtual size_t getNumberOfPersons() const = 0;

    [[nodiscard]] virtual const std::vector<PersonType>& getPersons() const = 0;
};
