#include "Commands.hpp"
#include "../Database.hpp"
#include "AddStudent.hpp"
#include "DeleteByIndexNumber.hpp"
#include "DeleteByPesel.hpp"
#include "EndGame.hpp"
#include "GenerateStudent.hpp"
#include "GenerateWorker.hpp"
#include "LoadRecords.hpp"
#include "PrintAllRecords.hpp"
#include "PrintMenu.hpp"
#include "SaveRecords.hpp"
#include "SearchByPesel.hpp"
#include "SearchOption.hpp"
#include "SortByIncome.hpp"
#include "SortByPesel.hpp"
#include "SortBySurname.hpp"
#include "ValidatePeselNumber.hpp"

std::unique_ptr<DatabaseInterface> Command::db_ = std::make_unique<Database>();

bool Command::quit = false;

std::vector<std::string> Command::order_{
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
    "q",
    "w",
    "s"};

std::map<std::string, std::shared_ptr<Command>> Command::options_{
    {"menu", std::make_shared<PrintMenu>()},
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
    {"save", std::make_shared<SaveRecords>()},
    {"q", std::make_shared<EndProgram>()},
    {"w", std::make_shared<GenerateWorker>()},
    {"s", std::make_shared<GenerateStudent>()}};
