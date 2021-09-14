#include "SearchByPesel.hpp"
#include <iostream>
#include "../Person.hpp"

void SearchByPesel::run() {
    std::string pesel;
    std::cout << "enter the search pesel: ";
    std::cin >> pesel;
    auto personsVec = db_->searchByPesel(pesel);
    if (!personsVec.empty()) {
        for (const auto& person : personsVec) {
            person->printPerson();
        }
    } else {
        std::cout << "Not found Student with this pesel\n";
    }
}

std::string SearchByPesel::getName() const {
    return "Search By Pesel";
}
