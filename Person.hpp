#pragma once
#include <optional>
#include <string>
#include "Address.hpp"
#include "Gender.hpp"

class Person {
public:
    Person(const std::string& firstName, 
        const std::string& surName, 
        const std::string& city, const std::string& street, const std::string& numberOfStreet, 
        const std::string& pesel, 
        Gender gender);
    virtual ~Person() = default;

    virtual void setFirstName(const std::string& firstName);
    virtual void setSurName(const std::string& surName);
    virtual void setCity(const std::string& city);
    virtual void setStreet(const std::string& street);
    virtual void setNumberOfStreet(const std::string& numberOfStreet);
    virtual void setPesel(const std::string& pesel);
    virtual void setGender(const Gender& gender);
    virtual void setIndexNumber(const size_t& indexNumber);
    virtual void setIncome(const size_t income);

    [[nodiscard]] virtual const std::string& getFirstName() const;
    [[nodiscard]] virtual const std::string& getSurName() const;
    [[nodiscard]] virtual const std::string getAddress() const;
    [[nodiscard]] virtual const std::string& getPesel() const;
    [[nodiscard]] virtual Gender getGender() const;
    [[nodiscard]] virtual const std::string& getCity() const;
    [[nodiscard]] virtual const std::string& getStreet() const;
    [[nodiscard]] virtual std::optional<size_t> getIndexNumber() const;
    [[nodiscard]] virtual std::optional<size_t> getIncome() const;

    virtual void printPerson() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

protected:
    std::string firstName_;
    std::string surName_;
    std::string pesel_;
    Address address_;
    Gender gender_ = Gender::Undefined;
};
