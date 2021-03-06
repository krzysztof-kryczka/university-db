#pragma once
#include "Address.hpp"
#include "Person.hpp"

class Worker : public Person {
public:
    Worker(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, std::string pesel, Gender gender, size_t income);
    ~Worker() override = default;

    void setFirstName(const std::string& firstName) override;
    void setSurName(const std::string& surName) override;
    void setCity(const std::string& city) override;
    void setStreet(const std::string& street) override;
    void setNumberOfStreet(const std::string& numberOfStreet) override;
    void setPesel(const std::string& pesel) override;
    void setGender(const Gender& gender) override;
    void setIncome(const size_t income) override { income_ = income; }

    const std::string& getFirstName() const override;
    const std::string& getSurName() const override;
    const std::string getAddress() const override;
    const std::string& getPesel() const override;
    Gender getGender() const override;
    const std::string& getCity() const override;
    const std::string& getStreet() const override;
    std::optional<size_t> getIncome() const override;

    void printPerson() const override;

private:
    std::string firstName_;
    std::string surName_;
    std::string pesel_;
    Gender gender_ = Gender::Undefined;
    Address address_;
    size_t income_{};
};
