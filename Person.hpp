#pragma once

#include <optional>
#include <string>
#include "Gender.hpp"
#include "Address.hpp"

class Person {
public:
    Person() {}
    virtual ~Person() = default;

    virtual void setFirstName(const std::string& firstName) {}
    virtual void setSurName(const std::string& surName) {}
    virtual void setCity(const std::string& city) {}
    virtual void setStreet(const std::string& street) {}
    virtual void setNumberOfStreet(const std::string& numberOfStreet) {}
    virtual void setIndexNumber(const size_t& indexNumber) {}
    virtual void setPesel(const std::string& pesel) {}
    virtual void setGender(const Gender& gender) {}
    virtual void setIncome(const size_t income) {}

    virtual std::string getFirstName() const = 0;
    virtual std::string getSurName() const = 0;
    virtual std::string getAddress() const = 0;
    virtual size_t getIndexNumber() const = 0;
    virtual std::string getPesel() const = 0;
    virtual Gender getGender() const = 0;
    virtual std::string getCity() const = 0;
    virtual std::string getStreet() const = 0;
    virtual std::optional<size_t> getIncome() const { return {}; }

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};