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

    std::string getAddress() {
        return city_ + " " + street_ + " " + numberOfStreet_;
    }
};

class Student {
public:
    Student(std::string firstName, std::string sureName, std::string city, std::string street, std::string numberOfStreet, std::string Pesel);

    void setFirstName(const std::string& firstName);
    void setSureName(const std::string& sureName);
    void setCity(const std::string& city);
    void setStreet(const std::string& street);
    void setNumberOfStreet(const std::string& numberOfStreet);
    void setPesel(const std::string& numberOfStreet);
    void setGender(const Gender& gender);

    std::string getFirstName() const;
    std::string getSureName() const;
    std::string getCity() const;
    std::string getStreet() const;
    std::string getNumberOfStreet() const;
    std::string getPesel() const;

    void printbyId(const size_t& id);
    void printAll();

    void searchByFirstName();
    void searchBySecondName();
    void searchByStreet();
    void searchByCity();

private:
    std::string firstName_ = defaultName;
    std::string sureName_ = defaultName;
    Address address;
    std::string pesel_ = defaultName;
    Gender gender_ = Gender::Undefined;
};
