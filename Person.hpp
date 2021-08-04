#pragma once

#include <optional>
#include <string>
#include "Address.hpp"
#include "Gender.hpp"

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

    [[nodiscard]] virtual const std::string& getFirstName() const = 0;
    [[nodiscard]] virtual const std::string& getSurName() const = 0;
    [[nodiscard]] virtual const std::string getAddress() const = 0;
    [[nodiscard]] virtual const std::string& getPesel() const = 0;
    [[nodiscard]] virtual Gender getGender() const = 0;
    [[nodiscard]] virtual const std::string& getCity() const = 0;
    [[nodiscard]] virtual const std::string& getStreet() const = 0;
    [[nodiscard]] virtual std::optional<size_t> getIndexNumber() const { return {}; }
    [[nodiscard]] virtual std::optional<size_t> getIncome() const { return {}; }

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};
