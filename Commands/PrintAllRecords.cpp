#include "PrintAllRecords.hpp"
#include <iostream>

void PrintAllRecords::run() {
    std::cout << "---------PRINT RECORDS FROM FILE-----------\n";
    db_->printAll();
}

std::string PrintAllRecords::getName() const {
    return "Print All Records";
}
