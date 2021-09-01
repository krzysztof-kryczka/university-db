#pragma once
#include <algorithm>
#include <memory>
#include <vector>
#include "DatabaseInterface.hpp"
#include "Student.hpp"
#include "Worker.hpp"

class Database : public DatabaseInterface {
public:
    Database() {}
    ~Database() override = default;

    [[nodiscard]] bool addPerson(const PersonType& person) override;
    void printById(size_t id) const override;
    void printAll() const override;
    void saveToFile(const std::string& fileName) const override;
    void loadFromFile(const std::string& fileName) override;

    [[nodiscard]] std::vector<PersonType> searchByPesel(const std::string& pesel) const override;
    [[nodiscard]] std::vector<PersonType> searchByFirstName(const std::string& firstName) const override;
    [[nodiscard]] std::vector<PersonType> searchBySurName(const std::string& surName) const override;
    [[nodiscard]] std::vector<PersonType> searchByStreet(const std::string& street) const override;
    [[nodiscard]] std::vector<PersonType> searchByCity(const std::string& city) const override;

    void sortByPesel(std::function<bool(const std::string&, const std::string&)> compare) override;
    void sortBySurName(std::function<bool(const std::string&, const std::string&)> compare) override;
    void sortByIncome(std::function<bool(const size_t&, const size_t&)> compare) override;

    void deleteByPesel(const std::string& pesel) override;
    void deleteByIndex(size_t indexNumber) override;
    void deleteByFirstName(const std::string& FirstName) override;
    void deleteBySurName(const std::string& SurName) override;

    size_t getNumberOfStudents() const override;

    [[nodiscard]] const std::vector<PersonType>& getPersons() const override;

private:
    std::vector<PersonType> persons_{};
};
