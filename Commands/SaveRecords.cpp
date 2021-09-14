#include "SaveRecords.hpp"
#include <iostream>

void SaveRecords::run() {
    std::cout << "---------SAVE RECORD TO FILE-----------\n";
    db_->saveToFile("db.txt");
}

std::string SaveRecords::getName() const {
    return "Save Records";
}