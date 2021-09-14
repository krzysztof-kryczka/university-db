#include "Student.hpp"
#include <iostream>
#include <iomanip>

Student::Student(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, size_t indexNumber, std::string pesel, Gender gender)
    : firstName_(firstName), surName_(surName), address_{city, street, numberOfStreet}, indexNumber_(indexNumber), pesel_(pesel), gender_(gender) {}

void Student::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Student::setSurName(const std::string& surName) {
    surName_ = surName;
}

void Student::setCity(const std::string& city) {
    address_.city_ = city;
}

void Student::setStreet(const std::string& street) {
    address_.street_ = street;
}

void Student::setNumberOfStreet(const std::string& numberOfStreet) {
    address_.numberOfStreet_ = numberOfStreet;
}

void Student::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}

void Student::setGender(const Gender& gender) {
    gender_ = gender;
}

void Student::setIndexNumber(const size_t& indexNumber) {
    indexNumber_ = indexNumber;
}

const std::string& Student::getFirstName() const {
    return firstName_;
}

const std::string& Student::getSurName() const {
    return surName_;
}

const std::string Student::getAddress() const {
    std::stringstream ss;
    ss << std::quoted(address_.city_) << " " << std::quoted(address_.street_) << " " << std::quoted(address_.numberOfStreet_);
    return ss.str();
}

const std::string& Student::getPesel() const {
    return pesel_;
}

std::optional<size_t> Student::getIndexNumber() const {
    return indexNumber_;
}

Gender Student::getGender() const {
    return gender_;
}

const std::string& Student::getCity() const {
    return address_.city_;
}

const std::string& Student::getStreet() const {
    return address_.street_;
}

void Student::printPerson() const {
    std::cout << "*******************************************\n";
    std::cout << "FirstName: " << getFirstName() << '\n';
    std::cout << "SurName:   " << getSurName() << '\n';
    std::cout << "Address:   " << getAddress() << '\n';
    std::cout << "Index:     " << getIndexNumber().value() << '\n';
    std::cout << "Pesel:     " << getPesel() << '\n';
    std::cout << "*******************************************\n";
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "STUDENT"
       << ' ' << std::quoted(student.getFirstName())
       << ' ' << std::quoted(student.getSurName())
       << ' ' << student.getAddress()
       << ' ' << student.getIndexNumber().value()
       << ' ' << std::quoted(student.getPesel())
       << ' ' << translateGender(student.getGender()) << '\n';
    return os;
}
