#include "SortByIncome.hpp"
#include <iostream>

void SortByIncome::run() {
    std::cout << "---------SORT BY INCOME (AFTER)-----------\n";
    db_->sortByIncome(std::less<>{});
    db_->printAll();
}

std::string SortByIncome::getName() {
    return "Sort By Income";
}
