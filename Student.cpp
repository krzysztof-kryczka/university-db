#include "Student.hpp"

std::map<Gender, std::string> translateGender{
    {Gender::Male, "Male"},
    {Gender::Female, "Female"},
    {Gender::Undefined, "Undefined"}};

Student::Student(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, size_t indexNumber, std::string pesel, Gender gender)
    : firstName_(firstName), surName_(surName), address{city, street, numberOfStreet}, indexNumber_(indexNumber), pesel_(pesel), gender_(gender) {}

void Student::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Student::setSurName(const std::string& surName) {
    surName_ = surName;
}

void Student::setCity(const std::string& city) {
    address.city_ = city;
}

void Student::setStreet(const std::string& street) {
    address.street_ = street;
}

void Student::setNumberOfStreet(const std::string& numberOfStreet) {
    address.numberOfStreet_ = numberOfStreet;
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
std::string Student::getFirstName() const {
    return firstName_;
}

std::string Student::getSurName() const {
    return surName_;
}

std::string Student::getAddress() const {
    return address.getAddress();
}

std::string Student::getPesel() const {
    return pesel_;
}

size_t Student::getIndexNumber() const {
    return indexNumber_;
}

Gender Student::getGender() const {
    return gender_;
}
