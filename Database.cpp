#include "Database.hpp"
#include <fstream>

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getFirstName() << " " << student.getSurName() << " " << student.getAddress() << " " << student.getIndexNumber() << " " << student.getPesel() << " " << translateGender[student.getGender()] << '\n';
    return os;
}

void Database::addStudent(Student student) {
    students_.push_back(student);
}

void Database::addStudent() {
    std::string firstName, surName, city, street, numberOfStreet, pesel;
    size_t indexNumber;
    Gender gender;
    
    std::cout << "\n First Name: ";
    std::cin >> firstName;

    std::cout << " Surname: ";
    std::cin >> surName;

    std::cout << " Address (city): ";
    std::cin >> city;

    std::cout << " Address (street): ";
    std::cin >> street;

    std::cout << " Address (numberOfStreet): ";
    std::cin >> numberOfStreet;

    std::cout << " Pesel: ";
    std::cin >> pesel;

    std::cout << " Index Number: ";
    std::cin >> indexNumber;

    std::cout << " Gender [male][female][Undefined] : ";
    std::cin >> translateGender[gender];

    if (checkPesel(pesel)) {
        Student s{firstName, surName, city, street, numberOfStreet, indexNumber, pesel, gender};
        addStudent(s);
        std::cout << "Student added.\n";
    } else {
        std::cout << "\nError: wrong PESEL number! Student not added! \n\n";
    }
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
    std::ifstream ifs;

    std::string firstName, surName, city, street, numberOfStreet, pesel;
    size_t indexNumber;
    Gender gender;

    ifs.open(fileName);
    if (ifs.is_open()) {
        while (ifs >> firstName >> surName >> city >> street >> numberOfStreet >> indexNumber >> pesel >> translateGender[gender]) {
            Student s{firstName, surName, city, street, numberOfStreet, indexNumber, pesel, gender};
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
    std::vector <Student> result;
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

void Database::deleteByIndex(size_t indexNumber) {
    auto it = std::remove_if(begin(students_), end(students_),
                             [indexNumber](auto student) { return student.getIndexNumber() == indexNumber; });
    students_.erase(it, students_.end());
}
void Database::deleteByFirstName(std::string FirstName){
     auto it = std::remove_if(begin(students_), end(students_),
                             [FirstName](auto student) { return student.getFirstName() == FirstName; });
    students_.erase(it, students_.end());

}
void Database::deleteBySurName(std::string SurName){
     auto it = std::remove_if(begin(students_), end(students_),
                             [SurName](auto student) { return student.getSurName() == SurName; });
    students_.erase(it, students_.end());

}
