#pragma once

#include <iostream>
#include "Gender.hpp"
#include "Address.hpp"

class Student {
public:
    Student(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, size_t indexNumber, std::string Pesel, Gender Gender);

    void setFirstName(const std::string& firstName);
    void setSurName(const std::string& surName);
    void setCity(const std::string& city);
    void setStreet(const std::string& street);
    void setNumberOfStreet(const std::string& numberOfStreet);
    void setIndexNumber(const size_t& indexNumber);
    void setPesel(const std::string& pesel);
    void setGender(const Gender& gender);

    std::string getFirstName() const;
    std::string getSurName() const;
    std::string getAddress() const;
    size_t getIndexNumber() const;
    std::string getPesel() const;
    Gender getGender() const;
    std::string getCity() const;
    std::string getStreet() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    std::string firstName_ = defaultName;
    std::string surName_ = defaultName;
    Address address_{};
    size_t indexNumber_ = 0;
    std::string pesel_ = defaultName;
    Gender gender_ = Gender::Undefined;
};

bool checkPesel(std::string pesel);