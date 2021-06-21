#include "Database.hpp"
#include <fstream>

void Database::addStudent(Student student) {
    students_.push_back(student);
}

void Database::printbyId(const size_t& id) {}

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

void Database::loadFromFile(std::string fileName) {
    std::ifstream ifs;

    std::string firstName, surName, city, street, numberOfStreet, pesel;
    size_t indexNumber;
    Gender gender;

    ifs.open(fileName);
    if (ifs.is_open()) {
        while ( ifs >> firstName >> surName >> city >> street >> numberOfStreet >> indexNumber >> pesel >> translateGender[gender] ) {
            Student s{firstName, surName, city, street, numberOfStreet, indexNumber, pesel, gender};
            addStudent(s);
        }
    }
    else {
        std::cout << "Error. Invalid data";
    }
}

void Database::deleteByPesel(std::string pesel) {
    auto it = std::remove_if(begin(students_), end(students_),
                           [pesel](auto student) { return student.getPesel() == pesel; });
    students_.erase(it, students_.end());
}


void Database::deleteByIndex(size_t indexNumber) {
    auto it = std::remove_if(begin(students_), end(students_),
                           [indexNumber](auto student) { return student.getIndexNumber()  == indexNumber; });
    students_.erase(it, students_.end());
}
