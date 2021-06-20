#include "Database.hpp"
#include <fstream>

void Database::addStudent(Student student) {
    students_.push_back(student);
}

void Database::printById(const size_t& id) {}

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

void Database::saveToFile(std::string fileName) {
    std::ofstream ofs;
    ofs.open(fileName);

    if(ofs.is_open()){
        for(const auto& student : students_){
            ofs << student;
        }
    }
    else {
        std::cout << "Error! Could not open " << fileName << " !\n";
    }
}

void Database::loadFromFile(std::string fileName) {}

size_t Database::getNumberOfStudents() const {
    return students_.size();
}

std::vector<Student> Database::searchByPesel(const std::string& pesel) const {
    std::vector<Student> result;
    for (const auto& el : students_) {
        std::cout << el.getPesel() << "  " << pesel << '\n';
        if (el.getPesel().compare(pesel) == 0) {
            result.push_back(el);
        }
    }
    return result;
}

void Database::sortByPesel() {
    std::sort(begin(students_), end(students_), [](const auto& lhs, const auto& rhs) {
        return std::less{}(lhs.getPesel(), rhs.getPesel());
    });
}

void Database::sortBySurName() {
    std::sort(begin(students_), end(students_), [](const auto& lhs, const auto& rhs) {
        return std::less{}(lhs.getSurName(), rhs.getSurName());
    });
}

void Database::deleteByPesel(std::string pesel) {
    auto it = std::remove_if(begin(students_), end(students_),
                           [pesel](auto student) { return student.getPesel() == pesel; });
    students_.erase(it, students_.end());
}
