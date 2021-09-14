#include "LoadRecords.hpp"
#include <iostream>

void LoadRecords::run() {
    std::cout << "---------LOAD RECORD FROM FILE-----------\n";
    db_->loadFromFile("db.txt");
}

std::string LoadRecords::getName() const {
    return "Load Records";
}
