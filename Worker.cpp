#include "Worker.hpp"
#include <iostream>
#include <iomanip>

Worker::Worker(const std::string& firstName, 
        const std::string& surName, 
        const std::string& city, const std::string& street, const std::string& numberOfStreet, 
        const std::string& pesel, 
        Gender gender, 
        size_t income)
    : Person(firstName
        , surName
        , city
        , street
        , numberOfStreet
        , pesel
        , gender)
    , income_(income) {}

void Worker::setIncome(const size_t income) { 
    income_ = income; 
}

std::optional<size_t> Worker::getIncome() const {
    return income_;
}

void Worker::printPerson() const {
    std::cout << "******************WORKER*******************\n";
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
