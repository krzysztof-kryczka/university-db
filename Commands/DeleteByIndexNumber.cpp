#include "DeleteByIndexNumber.hpp"
#include <iostream>

void DeleteByIndexNumber::run() {
    size_t index;
    std::cout << "enter the index number to be remove: ";
    std::cin >> index;
    std::cout << "---------DELETE BY INDEX (AFTER)-----------\n";
    db_->deleteByIndex(index);
    db_->printAll();
}

std::string DeleteByIndexNumber::getName() {
    return "Delete By Index";
}
