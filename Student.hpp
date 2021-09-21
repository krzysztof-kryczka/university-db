#pragma once
#include <iostream>
#include "Person.hpp"

class Student : public Person {
public:
    Student(const std::string& firstName, 
            const std::string& surName, 
            const std::string& city, 
            const std::string& street, 
            const std::string& numberOfStreet, 
            size_t indexNumber, 
            const std::string& Pesel, 
            Gender Gender);
    ~Student() override = default;

    void setIndexNumber(const size_t& indexNumber) override;
    std::optional<size_t> getIndexNumber() const override;

    void printPerson() const override;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    size_t indexNumber_{};
};

std::ostream& operator<<(std::ostream& os, const Student& student);
