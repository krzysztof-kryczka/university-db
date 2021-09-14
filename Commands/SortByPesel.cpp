#include "SortByPesel.hpp"
#include <iostream>

void SortByPesel::run() {
    std::cout << "---------SORT BY PESEL (AFTER)-----------\n";
    db_->sortByPesel(std::less<>{});
    db_->printAll();
}

std::string SortByPesel::getName() const {
    return "Sort By Pesel";
}
