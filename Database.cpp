#include "Database.hpp"

void Database::addStudent(Student student) {
    students_.push_back(student);
}

void Database::printbyId(const size_t& id) {}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getFirstName() << " " << student.getSurName() << " " << student.getAddress() << " " << student.getIndexNumber() << " " << student.getPesel() << " " << translateGender[student.getGender()] << '\n';
    return os;
}

void Database::printAll() {
    std::cout << "\t Database: \n";

    if (students_.empty())
        std::cout << "Error! Empty Database!\n";

    for (const auto& student : students_) {
        std::cout << student;
    }
    std::cout << "\n";
}
void Database::saveToFile(std::string fileName) {}
void Database::loadFromFile(std::string fileName) {}
