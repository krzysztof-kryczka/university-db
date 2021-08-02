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

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os  << person.getFirstName() 
        << " " << person.getSurName() 
        << " " << person.getAddress() 
        << " " << person.getIndexNumber() 
        << " " << person.getPesel() 
        << " " << translateGender(person.getGender()) << '\n';
    if(auto income = person.getIncome()){
        os << "Income: " << income.value() <<'\n';
    }
    return os;
}

bool Database::addPerson(const PersonType& person) {
    auto exist = std::any_of(begin(persons_), end(persons_), [&person](const auto& other) {
        return person->getPesel() == other->getPesel();
    });

    if (exist) {
        std::cout << "Person already exist. Adding abort.\n";
        return false;
    }
    persons_.push_back(person);
    return true;
}

void Database::printById(const size_t& id) const {}

void Database::printAll() const {
    std::cout << "\t Database: \n";
    if (persons_.empty()) {
        std::cout << "Error! Empty Database!\n";
        return;
    }
    for (const auto& student : persons_) {
        std::cout << *student;
    }
    std::cout << "\n";
}

void Database::saveToFile(std::string fileName) const {
    std::ofstream ofs;
    ofs.open(fileName);

    if (ofs.is_open()) {
        for (const auto& student : persons_) {
            ofs << *student;
        }
    } else {
        std::cout << "Error! Could not open " << fileName << " !\n";
    }
}
void Database::loadFromFile(std::string fileName) {
    persons_.clear();
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
            PersonType student = std::make_shared<Student>(firstName, surName, city, street, numberOfStreet, indexNumber, pesel, textToGender(gender_text));
            auto result = addPerson(student);
            if(!result){
                std::cout << "Add person to database from file failed.";
            }
        }
    } else {
        std::cout << "Error. Invalid data";
    }
}

size_t Database::getNumberOfStudents() const {
    return persons_.size();
}

std::vector<PersonType> Database::searchByPesel(const std::string& pesel) const {
    std::vector<PersonType> result;
    for (const auto& person : persons_) {
        if (person->getPesel() == pesel) {
            result.push_back(person);
        }
    }
    return result;
}

std::vector<PersonType> Database::searchByFirstName(const std::string& firstName) const {
    std::vector<PersonType> result;
    for (const auto& person : persons_) {
        if (person->getFirstName() == firstName) {
            result.push_back(person);
        }
    }
    return result;
}

std::vector<PersonType> Database::searchBySurName(const std::string& surName) const {
    std::vector<PersonType> result;
    for (const auto& person : persons_) {
        if (person->getSurName() == surName) {
            result.push_back(person);
        }
    }
    return result;
}
std::vector<PersonType> Database::searchByStreet(const std::string& street) const {
    std::vector<PersonType> result;
    for (const auto& person : persons_) {
        if (person->getStreet() == street) {
            result.push_back(person);
        }
    }
    return result;
}

std::vector<PersonType> Database::searchByCity(const std::string& city) const {
    std::vector<PersonType> result;
    for (const auto& person : persons_) {
        if (person->getCity() == city) {
            result.push_back(person);
        }
    }
    return result;
}

void Database::deleteByPesel(std::string pesel) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [pesel](const auto& person) { return person->getPesel() == pesel; });
    persons_.erase(it, persons_.end());
}

void Database::deleteByIndex(size_t indexNumber) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [indexNumber](const auto& person) { return person->getIndexNumber() == indexNumber; });
    persons_.erase(it, persons_.end());
}
void Database::deleteByFirstName(std::string FirstName) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [FirstName](const auto& person) { return person->getFirstName() == FirstName; });
    persons_.erase(it, persons_.end());
}
void Database::deleteBySurName(std::string SurName) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [SurName](const auto& person) { return person->getSurName() == SurName; });
    persons_.erase(it, persons_.end());
}
