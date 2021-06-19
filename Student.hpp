#pragma once

#include <iostream>
#include <string>

enum class Gender {
    Male,
    Female,
    Undefined
};

constexpr auto defaultName = "UNDEFINED";

struct Address {
    std::string city_ = defaultName;
    std::string street_ = defaultName;
    std::string numberOfStreet_ = defaultName;

    std::string getAddress() const {
        return city_ + " " + street_ + " " + numberOfStreet_;
    }
};

class Student {
public:
    Student(std::string firstName
    , std::string sureName
    , std::string city
    , std::string street
    , std::string numberOfStreet
    , size_t indexNumber
    , std::string Pesel
    , Gender Gender);

    void setFirstName(const std::string& firstName);
    void setSureName(const std::string& sureName);
    void setCity(const std::string& city);
    void setStreet(const std::string& street);
    void setNumberOfStreet(const std::string& numberOfStreet);
    void setIndexNumber(const size_t& indexNumber);
    void setPesel(const std::string& numberOfStreet);
    void setGender(const Gender& gender);

    std::string getFirstName() const;
    std::string getSureName() const;
    std::string getAddress() const;
    size_t getIndexNumber() const;
    std::string getPesel() const;
    Gender getGender() const;

    void searchByFirstName();
    void searchBySecondName();
    void searchByStreet();
    void searchByCity();

private:
    std::string firstName_ = defaultName;
    std::string sureName_ = defaultName;
    Address address;
    size_t indexNumber_ = 0;
    std::string pesel_ = defaultName;
    Gender gender_ = Gender::Undefined;
};
