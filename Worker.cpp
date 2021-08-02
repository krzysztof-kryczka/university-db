#include "Worker.hpp"

Worker::Worker(std::string firstName, std::string surName, std::string city, std::string street, std::string numberOfStreet, size_t indexNumber, std::string pesel, Gender gender)
    : firstName_(firstName), surName_(surName), address_{city, street, numberOfStreet}, indexNumber_(indexNumber), pesel_(pesel), gender_(gender) {}

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

void Worker::setIndexNumber(const size_t& indexNumber) {
    indexNumber_ = indexNumber;
}

const std::string& Worker::getFirstName() const {
    return firstName_;
}

const std::string& Worker::getSurName() const {
    return surName_;
}

const std::string Worker::getAddress() const {
    return address_.city_ + " " + address_.street_ + " " + address_.numberOfStreet_;
}

const std::string& Worker::getPesel() const {
    return pesel_;
}

size_t Worker::getIndexNumber() const {
    return indexNumber_;
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
