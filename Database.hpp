#pragma once

#include <algorithm>
#include <vector>
#include "Student.hpp"

class Database {
public:
    Database() {}

    bool addStudent(Student student);
    void printById(const size_t& id) const;
    void printAll() const;
    void saveToFile(std::string fileName) const;
    void loadFromFile(std::string fileName);

    size_t getNumberOfStudents() const;

    std::vector<Student> searchByPesel(const std::string& pesel) const;
    std::vector<Student> searchByFirstName(const std::string& firstName) const;
    std::vector<Student> searchBySurName(const std::string& surName) const;
    std::vector<Student> searchByStreet(const std::string& street) const;
    std::vector<Student> searchByCity(const std::string& city) const;

    void sortByPesel();
    void sortBySurName();

    void deleteByPesel(std::string pesel);
    void deleteByIndex(size_t indexNumber);
    void deleteByFirstName(std::string FirstName);
    void deleteBySurName(std::string SurName);

private:
    std::vector<Student> students_;
};
