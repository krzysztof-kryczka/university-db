#include "Person.hpp"
#include <iostream>
#include <iomanip>

Person::Person(const std::string& firstName, 
        const std::string& surName, 
        const std::string& city, 
        const std::string& street, 
        const std::string& numberOfStreet, 
        const std::string& pesel, 
        Gender gender) 
    : firstName_(firstName)
    , surName_(surName)
    , pesel_(pesel)
    , address_{city, street, numberOfStreet}
    , gender_(gender) {}

void Person::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Person::setSurName(const std::string& surName) {
    surName_ = surName;
}

void Person::setCity(const std::string& city) {
    address_.city_ = city;
}

void Person::setStreet(const std::string& street) {
    address_.street_ = street;
}

void Person::setNumberOfStreet(const std::string& numberOfStreet) {
    address_.numberOfStreet_ = numberOfStreet;
}

void Person::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}

void Person::setGender(const Gender& gender) {
    gender_ = gender;
}

void Person::setIndexNumber(const size_t& indexNumber) {}
void Person::setIncome(const size_t income) {}

const std::string& Person::getFirstName() const {
    return firstName_;
}

const std::string& Person::getSurName() const {
    return surName_;
}

const std::string Person::getAddress() const {
    std::stringstream ss;
    ss << std::quoted(address_.city_) << " " << std::quoted(address_.street_) << " " << std::quoted(address_.numberOfStreet_);
    return ss.str();
}

const std::string& Person::getPesel() const {
    return pesel_;
}

Gender Person::getGender() const {
    return gender_;
}

const std::string& Person::getCity() const {
    return address_.city_;
}

const std::string& Person::getStreet() const {
    return address_.street_;
}

std::optional<size_t> Person::getIndexNumber() const { return {}; }
std::optional<size_t> Person::getIncome() const { return {}; }
