#pragma once

#include <vector>

#include "Student.hpp"

class Database {
public:
    Database() {}

    void addStudent(Student student);

private:
    std::vector<Student> students_;
};
