#include "Database.hpp"
#include <fstream>

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os  << student.getFirstName() 
        << " " << student.getSurName() 
        << " " << student.getAddress() 
        << " " << student.getIndexNumber() 
        << " " << student.getPesel() 
        << " " << translateGender(student.getGender()) << '\n';
    return os;
}

bool Database::addStudent(Student student) {
    auto exist = std::any_of(begin(students_), end(students_), [&student](const auto& other) {
        return student.getPesel() == other.getPesel();
    });

    if (exist) {
        std::cout << "Student already exist. Adding abort.\n";
        return false;
    }
    students_.push_back(student);
    return true;
}

void Database::printById(const size_t& id) const {}

void Database::printAll() const {
    std::cout << "\t Database: \n";
    if (students_.empty()) {
        std::cout << "Error! Empty Database!\n";
        return;
    }
    for (const auto& student : students_) {
        std::cout << student;
    }
    std::cout << "\n";
}

void Database::saveToFile(std::string fileName) const {
    std::ofstream ofs;
    ofs.open(fileName);

    if (ofs.is_open()) {
        for (const auto& student : students_) {
            ofs << student;
        }
    } else {
        std::cout << "Error! Could not open " << fileName << " !\n";
    }
}
void Database::loadFromFile(std::string fileName) {
    students_.clear();
    std::ifstream ifs;

    std::string firstName, surName, city, street, numberOfStreet, pesel;
    size_t indexNumber;
    std::string gender_text;

    ifs.open(fileName);
    if (ifs.is_open()) {
        while (ifs  >> firstName 
                    >> surName 
                    >> city 
                    >> street 
                    >> numberOfStreet 
                    >> indexNumber 
                    >> pesel 
                    >> gender_text) 
        {
            Student s{firstName, surName, city, street, numberOfStreet, indexNumber, pesel, textToGender(gender_text)};
            addStudent(s);
        }
    } else {
        std::cout << "Error. Invalid data";
    }
}

size_t Database::getNumberOfStudents() const {
    return students_.size();
}

std::vector<Student> Database::searchByPesel(const std::string& pesel) const {
    std::vector<Student> result;
    for (const auto& el : students_) {
        if (el.getPesel() == pesel) {
            result.push_back(el);
        }
    }
    return result;
}

std::vector<Student> Database::searchByFirstName(const std::string& firstName) const {
    std::vector<Student> result;
    for (const auto& el : students_) {
        if (el.getFirstName() == firstName) {
            result.push_back(el);
        }
    }
    return result;
}

std::vector<Student> Database::searchBySurName(const std::string& surName) const {
    std::vector<Student> result;
    for (const auto& el : students_) {
        if (el.getSurName() == surName) {
            result.push_back(el);
        }
    }
    return result;
}
std::vector<Student> Database::searchByStreet(const std::string& street) const {
    std::vector<Student> result;
    for (const auto& el : students_) {
        if (el.getStreet() == street) {
            result.push_back(el);
        }
    }
    return result;
}

std::vector<Student> Database::searchByCity(const std::string& city) const {
    std::vector<Student> result;
    for (const auto& el : students_) {
        if (el.getCity() == city) {
            result.push_back(el);
        }
    }
    return result;
}

void Database::deleteByPesel(std::string pesel) {
    auto it = std::remove_if(begin(students_), end(students_),
                             [pesel](const auto& student) { return student.getPesel() == pesel; });
    students_.erase(it, students_.end());
}

void Database::deleteByIndex(size_t indexNumber) {
    auto it = std::remove_if(begin(students_), end(students_),
                             [indexNumber](const auto& student) { return student.getIndexNumber() == indexNumber; });
    students_.erase(it, students_.end());
}
void Database::deleteByFirstName(std::string FirstName) {
    auto it = std::remove_if(begin(students_), end(students_),
                             [FirstName](const auto& student) { return student.getFirstName() == FirstName; });
    students_.erase(it, students_.end());
}
void Database::deleteBySurName(std::string SurName) {
    auto it = std::remove_if(begin(students_), end(students_),
                             [SurName](const auto& student) { return student.getSurName() == SurName; });
    students_.erase(it, students_.end());
}
