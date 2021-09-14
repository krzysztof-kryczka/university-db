#include "PrintMenu.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>

PrintMenu::PrintMenu(const std::map<std::string, std::shared_ptr<Command>>& options,
                    std::vector<std::string> order)
    : options_(options), order_(std::move(order)) {}

void PrintMenu::run() try {
    std::cout << "*************************************" << '\n';
    std::cout << "****** UNIVERSITY-DB DATABASE *******" << '\n';
    std::cout << "*************************************" << '\n';
    std::cout << "   COMMAND -> EFFECT\n";
    std::cout << "-------------------------------------\n";
    for (const auto& option : order_) {
        std::cout << std::setw(10) << option << " -> " << options_.at(option)->getName() << '\n';
    }
} catch (const std::out_of_range& error) { //remove order_ strings not existing as key in map options_
    std::cout << "Warning: option in order don't exist(removing it from menu).\n";
    order_.erase(std::remove_if(begin(order_), end(order_), [this](const auto& option){
        return std::none_of(begin(this->options_), end(this->options_), [&option](const auto& pair){
            return pair.first == option;
        });
    }), end(order_));
    run(); // rerun menu printing
}

std::string PrintMenu::getName() const {
    return "Show Menu";
}
