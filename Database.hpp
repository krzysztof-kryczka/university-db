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


private:
    std::vector<Student> students_;
};
