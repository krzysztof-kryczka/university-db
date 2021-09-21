#include "Menu.hpp"
#include <iostream>
#include <iomanip>
#include "Commands/Commands.hpp"
#include "Database.hpp"

std::unique_ptr<DatabaseInterface> Command::db_ = std::make_unique<Database>();

namespace {
std::map<std::string, std::shared_ptr<Command>> options;
bool quit = false;
}

Menu::Menu() {
    options = std::map<std::string, std::shared_ptr<Command>>{
    {"menu", std::make_shared<PrintMenu>(options,
                                    std::vector<std::string>{ // print order
                                        "menu",
                                        "show",
                                        "load",
                                        "save",
                                        "search1",
                                        "search2",
                                        "sort1",
                                        "sort2",
                                        "sort3",
                                        "del1",
                                        "del2",
                                        "vpesel",
                                        "change",
                                        "q",
                                        "w",
                                        "s"})},
    {"show", std::make_shared<PrintAllRecords>()},
    {"load", std::make_shared<LoadRecords>()},
    {"add", std::make_shared<AddStudent>()},
    {"search1", std::make_shared<SearchOption>()},
    {"search2", std::make_shared<SearchByPesel>()},
    {"sort1", std::make_shared<SortBySurname>()},
    {"sort2", std::make_shared<SortByPesel>()},
    {"sort3", std::make_shared<SortByIncome>()},
    {"del1", std::make_shared<DeleteByPesel>()},
    {"del2", std::make_shared<DeleteByIndexNumber>()},
    {"vpesel", std::make_shared<ValidatePeselNumber>()},
    {"change", std::make_shared<ChangeIncome>()},
    {"save", std::make_shared<SaveRecords>()},
    {"q", std::make_shared<EndProgram>(quit)},
    {"w", std::make_shared<GenerateWorker>()},
    {"s", std::make_shared<GenerateStudent>()}};
}

void Menu::run() {
    options["menu"]->run();  //show menu

    auto runOption = [](const std::string& command) {
        auto it = options.find(command);
        if (it != options.end()) {
            it->second->run();
            return;
        } 
        std::cout << "Wrong option!\n";
    };

    while (!quit) {
        std::cout << "Write command: ";
        std::string command;
        std::cin >> command;
        runOption(command);
    }
}
