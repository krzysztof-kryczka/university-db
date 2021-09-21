#include "Student.hpp"
#include <iostream>
#include <iomanip>

Student::Student(const std::string& firstName, 
        const std::string& surName, 
        const std::string& city, const std::string& street, const std::string& numberOfStreet, 
        size_t indexNumber, 
        const std::string& pesel, 
        Gender gender)
    : Person(firstName, surName, city, street, numberOfStreet, pesel, gender), indexNumber_(indexNumber) {}

void Student::setIndexNumber(const size_t& indexNumber) {
    indexNumber_ = indexNumber;
}

std::optional<size_t> Student::getIndexNumber() const {
    return indexNumber_;
}

void Student::printPerson() const {
    std::cout << "******************STUDENT*******************\n";
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
