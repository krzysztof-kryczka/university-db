#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include "Student.hpp"
#include "Worker.hpp"

using PersonType = std::shared_ptr<Person>;

class Database {
public:
    Database() {}
    ~Database() = default;

    [[nodiscard]]bool addPerson(const PersonType& person);
    void printById(const size_t& id) const;
    void printAll() const;
    void saveToFile(std::string fileName) const;
    void loadFromFile(std::string fileName);

    size_t getNumberOfStudents() const;

    std::vector<PersonType> searchByPesel(const std::string& pesel) const;
    std::vector<PersonType> searchByFirstName(const std::string& firstName) const;
    std::vector<PersonType> searchBySurName(const std::string& surName) const;
    std::vector<PersonType> searchByStreet(const std::string& street) const;
    std::vector<PersonType> searchByCity(const std::string& city) const;

    template <typename C = std::less<>>
    void sortByPesel(C compare = C{}) {
        std::sort(begin(persons_), end(persons_), [&compare](const auto& lhs, const auto& rhs) {
            return compare(lhs->getPesel(), rhs->getPesel());
        });
    }

    template <typename C = std::less<>>
    void sortBySurName(C compare = C{}) {
        std::sort(begin(persons_), end(persons_), [&compare](const auto& lhs, const auto& rhs) {
            return compare(lhs->getSurName(), rhs->getSurName());
        });
    }

    void deleteByPesel(std::string pesel);
    void deleteByIndex(size_t indexNumber);
    void deleteByFirstName(std::string FirstName);
    void deleteBySurName(std::string SurName);

    const std::vector<PersonType>& getPersons() const {
        return persons_;
    }

private:
    std::vector<PersonType> persons_{};
};
