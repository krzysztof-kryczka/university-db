#pragma once

#include <iostream>
#include "Person.hpp"

class Student : public Person {
public:
    Student(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, size_t indexNumber, std::string Pesel, Gender Gender);

    void setFirstName(const std::string& firstName) override;
    void setSurName(const std::string& surName) override;
    void setCity(const std::string& city) override;
    void setStreet(const std::string& street) override;
    void setNumberOfStreet(const std::string& numberOfStreet) override;
    void setIndexNumber(const size_t& indexNumber) override;
    void setPesel(const std::string& pesel) override;
    void setGender(const Gender& gender) override;

    [[nodiscard]] const std::string& getFirstName() const override;
    [[nodiscard]] const std::string& getSurName() const override;
    [[nodiscard]] const std::string getAddress() const override;
    [[nodiscard]] size_t getIndexNumber() const override;
    [[nodiscard]] const std::string& getPesel() const override;
    [[nodiscard]] Gender getGender() const override;
    [[nodiscard]] const std::string& getCity() const override;
    [[nodiscard]] const std::string& getStreet() const override;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    std::string firstName_{};
    std::string surName_{};
    Address address_{};
    size_t indexNumber_{};
    std::string pesel_{};
    Gender gender_ = Gender::Undefined;
};

bool checkPesel(std::string pesel);
