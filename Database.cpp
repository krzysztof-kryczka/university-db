#include "Database.hpp"
#include <fstream>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Person& person) {
    if (const auto worker = dynamic_cast<const Worker*>(&person)) {
        os << *worker;
        return os;
    } 
    if (const auto student = dynamic_cast<const Student*>(&person)) {
        os << *student;
        return os;
    }
    std::cout << "Unknown person type(push to stream ignored).\n";
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, PersonType& person) {
    std::string type;
    std::string firstName, surName, city, street, numberOfStreet, pesel;
    size_t indexNumber;
    std::string gender_text;
    size_t income;

    ifs >> type;
    if (type == "WORKER") {
        ifs >> std::quoted(firstName)
            >> std::quoted(surName)
            >> std::quoted(city)
            >> std::quoted(street)
            >> std::quoted(numberOfStreet)
            >> std::quoted(pesel)
            >> gender_text 
            >> income;
        person = std::make_shared<Worker>(firstName, surName, city, street, numberOfStreet, pesel, textToGender(gender_text), income);
        return ifs;
    } 
    if (type == "STUDENT") {
        ifs >> std::quoted(firstName)
            >> std::quoted(surName)
            >> std::quoted(city)
            >> std::quoted(street)
            >> std::quoted(numberOfStreet)
            >> indexNumber 
            >> std::quoted(pesel)
            >> gender_text;
        person = std::make_shared<Student>(firstName, surName, city, street, numberOfStreet, indexNumber, pesel, textToGender(gender_text));
        return ifs;
    }
    if (type == "") {
        return ifs;
    }
    throw std::logic_error("Don't know how to read this type of person:" + type);
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

void Database::printById(size_t id) const {}

void Database::printAll() const {
    std::cout << "\t Database: \n";
    if (persons_.empty()) {
        std::cout << "Error! Empty Database!\n";
        return;
    }
    for (const auto& person : persons_) {
        person->printPerson();
    }
    std::cout << "\n";
}

void Database::saveToFile(const std::string& fileName) const {
    std::ofstream ofs;
    ofs.open(fileName);

    if (ofs.is_open()) {
        for (const auto& person : persons_) {
            ofs << *person;
        }
    } else {
        std::cout << "Error! Could not open " << fileName << " !\n";
    }
}

void Database::loadFromFile(const std::string& fileName) {
    persons_.clear();
    std::ifstream ifs;
    PersonType person;

    ifs.open(fileName);
    if (ifs.is_open()) {
        while (ifs >> person) {
            auto result = addPerson(person);
            if (!result) {
                std::cout << "Add person to database from file failed.\n";
            }
        }
    } else {
        std::cout << "Error! Invalid data.\n";
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

void Database::sortByPesel(std::function<bool(const std::string&, const std::string&)> compare) {
    std::sort(begin(persons_), end(persons_), [&compare](const PersonType& lhs, const PersonType& rhs) {
        return compare(lhs->getPesel(), rhs->getPesel());
    });
}

void Database::sortBySurName(std::function<bool(const std::string&, const std::string&)> compare) {
    std::sort(begin(persons_), end(persons_), [&compare](const PersonType& lhs, const PersonType& rhs) {
        return compare(lhs->getSurName(), rhs->getSurName());
    });
}

void Database::sortByIncome(std::function<bool(const size_t&, const size_t&)> compare) {
    std::sort(begin(persons_), end(persons_), [&compare](const PersonType& lhs, const PersonType& rhs) {
        if (auto lIncome = lhs->getIncome()) {
            if (auto rIncome = rhs->getIncome()) {
                return compare(lIncome.value(), rIncome.value());
            } else {
                return true;
            }
        } else {
            return false;
        }
    });
}

void Database::deleteByPesel(const std::string& pesel) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [&pesel](const auto& person) { return person->getPesel() == pesel; });
    persons_.erase(it, persons_.end());
}

void Database::deleteByIndex(size_t indexNumber) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [indexNumber](const auto& person) {
                                 if (auto index = person->getIndexNumber()) {
                                     return index.value() == indexNumber;
                                 }
                                 return false;
                             });
    persons_.erase(it, persons_.end());
}

void Database::deleteByFirstName(const std::string& firstName) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [&firstName](const auto& person) { return person->getFirstName() == firstName; });
    persons_.erase(it, persons_.end());
}

void Database::deleteBySurName(const std::string& surName) {
    auto it = std::remove_if(begin(persons_), end(persons_),
                             [&surName](const auto& person) { return person->getSurName() == surName; });
    persons_.erase(it, persons_.end());
}

const std::vector<PersonType>& Database::getPersons() const {
    return persons_;
}
