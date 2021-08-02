#include "Student.hpp"

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
    return address_.city_ + " " + address_.street_ + " " + address_.numberOfStreet_;;
}

const std::string& Student::getPesel() const {
    return pesel_;
}

size_t Student::getIndexNumber() const {
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
