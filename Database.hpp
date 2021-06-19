#pragma once

#include <vector>

#include "Student.hpp"

class Database {
public:
    Database() {}

    void addStudent(Student student);
    void printbyId(const size_t& id);
    void printAll();
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);

private:
    std::vector<Student> students_;
};
