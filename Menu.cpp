#include "Menu.hpp"
#include <iostream>
#include "Commands/Commands.hpp"

void Menu::run() {
    Command::options_["menu"]->run();  //show menu

    auto runOption = [](const std::string& command) {
        auto it = Command::options_.find(command);
        if (it != Command::options_.end()) {
            it->second->run();
        } else {
            std::cout << "Wrong option!\n";
        }
    };

    while (!Command::quit) {
        std::string command;
        std::cout << "Write command: ";
        std::cin >> command;
        runOption(command);
    }
}
