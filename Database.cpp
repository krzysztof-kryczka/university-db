#include "DataBase.hpp"

void Database::addStudent(Student student) {
    students_.push_back(student);
}

void Database::printbyId(const size_t& id) {}
void Database::printAll() {}
void Database::saveToFile(std::string fileName) {}
void Database::loadFromFile(std::string fileName) {}
