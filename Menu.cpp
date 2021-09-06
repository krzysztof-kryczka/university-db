#include "Menu.hpp"
#include <array>
#include <iostream>
#include <memory>
#include "Commands/Commands.hpp"
#include "Database.hpp"
#include <map>

std::unique_ptr<DatabaseInterface> db_ = std::make_unique<Database>();
bool menuQuit = false;

std::vector<std::string> order_{
    "menu",
    "show",
    "load",
    "save",
    "a",
    "search1",
    "search2",
    "sort1",
    "sort2",
    "sort3",
    "del1",
    "del2",
    "vpesel",
    "q",
    "w",
    "s"
};

std::map<std::string, std::shared_ptr<Command>> options_{
    {"menu", std::make_shared<PrintMenu>()},
    {"show", std::make_shared<PrintAllRecords>()},
    {"load", std::make_shared<LoadRecords>()},
    {"a", std::make_shared<AddStudent>()},
    {"search1", std::make_shared<SearchOption>()},
    {"search2", std::make_shared<SearchByPesel>()},
    {"sort1", std::make_shared<SortBySurname>()},
    {"sort2", std::make_shared<SortByPesel>()},
    {"sort3", std::make_shared<SortByIncome>()},
    {"del1", std::make_shared<DeleteByPesel>()},
    {"del2", std::make_shared<DeleteByIndexNumber>()},
    {"vpesel", std::make_shared<ValidatePeselNumber>()},
    {"save", std::make_shared<SaveRecords>()},
    {"q", std::make_shared<EndProgram>()},
    {"w", std::make_shared<GenerateWorker>()},
    {"s", std::make_shared<GenerateStudent>()}
};

void Menu::run() {
    options_["menu"]->run();  //show menu

    auto runOption = [this](const std::string& command) {
        try {
            options_.at(command)->run();
        } catch (const std::out_of_range& err) {
            std::cout << "Wrong option!\n";
        }
    };

    std::string command;
    while (!menuQuit) {
        std::cout << "Write command: ";
        std::cin >> command;
        runOption(command);
    }
}
