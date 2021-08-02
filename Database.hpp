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

    [[nodiscard]] bool addPerson(const PersonType& person);
    void printById(size_t id) const;
    void printAll() const;
    void saveToFile(const std::string& fileName) const;
    void loadFromFile(const std::string& fileName);

    [[nodiscard]] size_t getNumberOfStudents() const;

    [[nodiscard]] std::vector<PersonType> searchByPesel(const std::string& pesel) const;
    [[nodiscard]] std::vector<PersonType> searchByFirstName(const std::string& firstName) const;
    [[nodiscard]] std::vector<PersonType> searchBySurName(const std::string& surName) const;
    [[nodiscard]] std::vector<PersonType> searchByStreet(const std::string& street) const;
    [[nodiscard]] std::vector<PersonType> searchByCity(const std::string& city) const;

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

    void deleteByPesel(const std::string& pesel);
    void deleteByIndex(size_t indexNumber);
    void deleteByFirstName(const std::string& FirstName);
    void deleteBySurName(const std::string& SurName);

    [[nodiscard]] const std::vector<PersonType>& getPersons() const;

private:
    std::vector<PersonType> persons_{};
};
