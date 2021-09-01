#include "PrintMenu.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

void PrintMenu::run() {
    std::cout << "*************************************" << '\n';
    std::cout << "****** UNIVERSITY-DB DATABASE *******" << '\n';
    std::cout << "*************************************" << '\n';
    std::cout << "   COMMAND -> EFFECT\n";
    std::cout << "-------------------------------------\n";
    for (const auto& option : order_) {
        std::cout << std::setw(10) << option << " -> " << options_[option]->getName() << '\n';
    }
}

std::string PrintMenu::getName() {
    return "Show Menu";
}
