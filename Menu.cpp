#include "Menu.hpp"

#include <array>
#include <iostream>
#include <memory>
#include "Commands/Commands.hpp"

Database db_;
bool menuQuit = false;
std::array<std::unique_ptr<Command>,13> options_{
        std::make_unique<PrintMenu>(),
        std::make_unique<PrintAllRecords>(),
        std::make_unique<LoadRecords>(),
        std::make_unique<AddStudent>(),
        std::make_unique<SearchOption>(),
        std::make_unique<SearchByPesel>(),
        std::make_unique<SortBySurname>(),
        std::make_unique<SortByPesel>(),
        std::make_unique<DeleteByPesel>(),
        std::make_unique<DeleteByIndexNumber>(),
        std::make_unique<ValidatePeselNumber>(),
        std::make_unique<SaveRecords>(),
        std::make_unique<EndProgram>()
    };


void Menu::run() {
    options_[0]->run();//show menu

    auto runOption = [this](size_t index) {
        if (index >= 0 and index < options_.size()) {
            options_[index]->run();
        } else {
            std::cout << "Wrong option!\n";
        }
    };

    std::string chosedOption;
    while (!menuQuit) {
        std::cout << "Select Option: ";
        std::cin >> chosedOption;
        size_t indexOption = 0;
        try {
            indexOption = std::stoi(chosedOption);  //todo: change to nothrowing function
        } catch (std::invalid_argument& err) {
            std::cout << "Wrong command!\n";
            continue;
        }
        runOption(indexOption);
    }
}
