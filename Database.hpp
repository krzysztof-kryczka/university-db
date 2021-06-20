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

    size_t getNumberOfStudents() const {
        return students_.size();
    }

    std::vector<Student> searchByPesel(const std::string& pesel) const {
        std::vector<Student> result;
        for (const auto& el : students_) {
            std::cout << el.getPesel() << "  " << pesel << '\n';
            if (el.getPesel().compare(pesel) == 0) {
                result.push_back(el);
            }
        }
        return result;
    }
    std::vector<Student> searchByFirstName(const std::string& firstname);
    std::vector<Student> searchBySecondName(const std::string& secondname);
    std::vector<Student> searchByStreet(const std::string& street);
    std::vector<Student> searchByCity(const std::string& city);

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
