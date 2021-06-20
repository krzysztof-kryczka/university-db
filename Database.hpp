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
    
    std::vector<Student> searchByPesel (const std::string& pesel) const {
        std::vector<Student> result;
        for (const auto& el : students_) {
            std::cout << el.getPesel() << "  " << pesel << '\n';
            if (el.getPesel().compare(pesel) == 0) {
                result.push_back(el);
            }
        }
        return result;
    }
    void searchByFirstName();
    void searchBySecondName();
    void searchByStreet();
    void searchByCity();

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
