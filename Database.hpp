#pragma once

#include <algorithm>
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

    void sortByPesel() {
        std::sort(begin(students_), end(students_), [](const auto& lhs, const auto& rhs) {
            return std::less{}(lhs.getPesel(), rhs.getPesel());
        });
    }

    void sortbySurename() {
        std::sort(begin(students_), end(students_), [](const auto& lhs, const auto& rhs) {
            return std::less{}(lhs.getSurName(), rhs.getSurName());
        });
    }

void deleteByPesel(std::string pesel);   

private:
    std::vector<Student> students_;
};
