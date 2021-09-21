#pragma once
#include "Address.hpp"
#include "Person.hpp"

class Worker : public Person {
public:
    Worker(const std::string& firstName, 
            const std::string& surName,
            const std::string& city, 
            const std::string& street, 
            const std::string& numberOfStreet, 
            const std::string& pesel, 
            Gender gender, 
            size_t income);
    ~Worker() override = default;

    void setIncome(const size_t income) override;
    std::optional<size_t> getIncome() const override;

    void printPerson() const override;

    friend std::ostream& operator<<(std::ostream& os, const Worker& worker);

private:
    size_t income_{};
};

std::ostream& operator<<(std::ostream& os, const Worker& worker);
