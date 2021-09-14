#include "SortBySurname.hpp"
#include <iostream>

void SortBySurname::run() {
    std::cout << "---------SORT BY SURNAME (AFTER)-----------\n";
    db_->sortBySurName(std::less<>{});
    db_->printAll();
}

std::string SortBySurname::getName() const {
    return "Sort By Surname";
}
