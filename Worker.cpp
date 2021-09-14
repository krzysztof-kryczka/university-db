#include "Worker.hpp"
#include <iostream>
#include <iomanip>

Worker::Worker(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, std::string pesel, Gender gender, size_t income)
    : firstName_(firstName), surName_(surName), address_{city, street, numberOfStreet}, pesel_(pesel), gender_(gender), income_(income) {}

void Worker::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Worker::setSurName(const std::string& surName) {
    surName_ = surName;
}

void Worker::setCity(const std::string& city) {
    address_.city_ = city;
}

void Worker::setStreet(const std::string& street) {
    address_.street_ = street;
}

void Worker::setNumberOfStreet(const std::string& numberOfStreet) {
    address_.numberOfStreet_ = numberOfStreet;
}

void Worker::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}

void Worker::setGender(const Gender& gender) {
    gender_ = gender;
}

const std::string& Worker::getFirstName() const {
    return firstName_;
}

const std::string& Worker::getSurName() const {
    return surName_;
}

const std::string Worker::getAddress() const {
    std::stringstream ss;
    ss << std::quoted(address_.city_) << " " << std::quoted(address_.street_) << " " << std::quoted(address_.numberOfStreet_);
    return ss.str();
}

const std::string& Worker::getPesel() const {
    return pesel_;
}

std::optional<size_t> Worker::getIncome() const {
    return income_;
}

Gender Worker::getGender() const {
    return gender_;
}

const std::string& Worker::getCity() const {
    return address_.city_;
}

const std::string& Worker::getStreet() const {
    return address_.street_;
}

void Worker::printPerson() const {
    std::cout << "*******************************************\n";
    std::cout << "FirstName: " << getFirstName() << '\n';
    std::cout << "SurName:   " << getSurName() << '\n';
    std::cout << "Address:   " << getAddress() << '\n';
    std::cout << "Pesel:     " << getPesel() << '\n';
    std::cout << "Income:    " << getIncome().value() << '\n';
    std::cout << "*******************************************\n";
}

std::ostream& operator<<(std::ostream& os, const Worker& worker) {
    os << "WORKER"
       << ' ' << std::quoted(worker.getFirstName())
       << ' ' << std::quoted(worker.getSurName())
       << ' ' << worker.getAddress()
       << ' ' << std::quoted(worker.getPesel())
       << ' ' << translateGender(worker.getGender())
       << ' ' << worker.getIncome().value() << '\n';
    return os;
}
