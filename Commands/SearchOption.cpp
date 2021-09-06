#include "SearchOption.hpp"
#include <iostream>
#include "../Person.hpp"

void SearchOption::run() {
    std::vector<PersonType> personsVec;
    std::string what;
    std::cout << "Enter the search type: firstname / surname / city / street" << what << ":";
    std::cin >> what;

    if (what == "surname") {
        std::string surName;
        std::cout << "enter the search " << what << ": ";
        std::cin >> surName;
        personsVec = db_->searchBySurName(surName);
    } else if (what == "firstname") {
        std::string firstName;
        std::cout << "enter the search " << what << ": ";
        std::cin >> firstName;
        personsVec = db_->searchByFirstName(firstName);
    } else if (what == "city") {
        std::string city;
        std::cout << "enter the search " << what << ": ";
        std::cin >> city;
        personsVec = db_->searchByCity(city);
    } else if (what == "street") {
        std::string street;
        std::cout << "enter the search " << what << ": ";
        std::cin >> street;
        personsVec = db_->searchByStreet(street);
    } else {
        std::cout << "Error. Unknown option, please choose from : surname, firstname, city, street\n";
        return;
    }
    if (!personsVec.empty()) {
        for (const auto& person : personsVec) {
            person->printPerson();
        }
    } else {
        std::cout << "Not found Student with this " << what << '\n';
    }
}

std::string SearchOption::getName() {
    return "Search";
}
