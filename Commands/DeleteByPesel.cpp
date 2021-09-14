#include "DeleteByPesel.hpp"
#include <iostream>

void DeleteByPesel::run() {
    std::string pesel;
    std::cout << "enter the pesel to be remove: ";
    std::cin >> pesel;
    std::cout << "---------DELETE BY PESEL (AFTER)-----------\n";
    db_->deleteByPesel(pesel);
    db_->printAll();
}

std::string DeleteByPesel::getName() const {
    return "Delete By Pesel";
}
