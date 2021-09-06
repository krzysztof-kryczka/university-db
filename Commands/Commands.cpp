#include "Commands.hpp"

#include <iomanip>
#include <map>
#include "../CheckPesel.hpp"
#include "../DatabaseInterface.hpp"
#include "../Gender.hpp"
#include "../Student.hpp"
#include "../Worker.hpp"

extern std::vector<std::string> order_;
extern std::map<std::string, std::shared_ptr<Command>> options_;
extern std::unique_ptr<DatabaseInterface> db_;
extern bool menuQuit;

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

void PrintAllRecords::run() {
    std::cout << "---------PRINT RECORDS FROM FILE-----------\n";
    db_->printAll();
}

std::string PrintAllRecords::getName() {
    return "Print All Records";
}

void LoadRecords::run() {
    std::cout << "---------LOAD RECORD FROM FILE-----------\n";
    db_->loadFromFile("db.txt");
}

std::string LoadRecords::getName() {
    return "Load Records";
}

void AddStudent::run() {
    std::string firstName;
    std::string surName;
    std::string city;
    std::string street;
    std::string numberOfStreet;
    std::string pesel;
    std::string indexNumber;
    std::string genderInput;
    size_t index;
    Gender gender = Gender::Undefined;

    std::cout << "\n First Name: ";
    std::cin >> firstName;

    std::cout << " Surname: ";
    std::cin >> surName;

    std::cout << " Address (city): ";
    std::cin >> city;

    std::cout << " Address (street): ";
    std::cin >> street;

    std::cout << " Address (numberOfStreet): ";
    std::cin >> numberOfStreet;

    std::cout << " Index Number: ";
    std::cin >> indexNumber;
    index = std::stoi(indexNumber);

    std::cout << " Gender [Male][Female][Undefined] : ";
    std::cin >> genderInput;
    gender = textToGender(genderInput);
    std::cout << "Gender set : " << translateGender(gender) << '\n';

    int incorrectPeselTries = 3;
    while (true) {
        std::cout << " Pesel: ";
        std::cin >> pesel;

        if (checkPesel(pesel)) {
            PersonType student = std::make_shared<Student>(firstName, surName, city, street, numberOfStreet, index, pesel, gender);
            auto isSuccess = db_->addPerson(student);
            if (isSuccess) {
                std::cout << "Student added.\n";
            } else {
                std::cout << "Student NOT added.\n";
            }
            return;
        }

        std::cout << "\nError: wrong PESEL number!\n";
        --incorrectPeselTries;
        char letter = 0;

        std::cout << " Try insert PESEL again (y/n)\n";
        std::cin >> letter;
        std::cout << letter << '\n';

        if (letter == 'n' or incorrectPeselTries == 0) {
            std::cout << "\nStudent NOT added!\n";
            return;
        }
    }
}

std::string AddStudent::getName() {
    return "Add Student";
}

void SortBySurname::run() {
    std::cout << "---------SORT BY SURNAME (AFTER)-----------\n";
    db_->sortBySurName(std::less<>{});
    db_->printAll();
}

std::string SortBySurname::getName() {
    return "Sort By Surname";
}

void SortByPesel::run() {
    std::cout << "---------SORT BY PESEL (AFTER)-----------\n";
    db_->sortByPesel(std::less<>{});
    db_->printAll();
}

std::string SortByPesel::getName() {
    return "Sort By Pesel";
}

void SortByIncome::run() {
    std::cout << "---------SORT BY INCOME (AFTER)-----------\n";
    db_->sortByIncome(std::less<>{});
    db_->printAll();
}

std::string SortByIncome::getName() {
    return "Sort By Income";
}
void EndProgram::run() {
    menuQuit = true;
}

std::string EndProgram::getName() {
    return "End Program";
}
namespace {
void printPerson(const PersonType& person) {
    std::cout << "*******************************************\n";
    std::cout << "FirstName: " << person->getFirstName() << '\n';
    std::cout << "SurName:   " << person->getSurName() << '\n';
    std::cout << "Address:   " << person->getAddress() << '\n';
    if (auto index = person->getIndexNumber()) {
        std::cout << "Index:     " << index.value() << '\n';
    }
    if (auto income = person->getIncome()) {
        std::cout << "Income:    " << income.value() << '\n';
    }
    std::cout << "Pesel:     " << person->getPesel() << '\n';
    std::cout << "*******************************************\n";
}
}  // namespace

void SearchOption::run() {
    std::vector<PersonType> personsVec;
    std::string what;
    std::cout << "Enter the search type: firstname / surname / city / street" << what << ":";
    std::cin >> what;

    if (what == "surname") {
        std::string surName;
        std::cout << "enter the search " << what << ": ";
        std::cin >> surName;
        personsVec = db_->searchBySurName(surName);
    } else if (what == "firstname") {
        std::string firstName;
        std::cout << "enter the search " << what << ": ";
        std::cin >> firstName;
        personsVec = db_->searchByFirstName(firstName);
    } else if (what == "city") {
        std::string city;
        std::cout << "enter the search " << what << ": ";
        std::cin >> city;
        personsVec = db_->searchByCity(city);
    } else if (what == "street") {
        std::string street;
        std::cout << "enter the search " << what << ": ";
        std::cin >> street;
        personsVec = db_->searchByStreet(street);
    } else {
        std::cout << "Error. Unknown option, please choose from : surname, firstname, city, street\n";
        return;
    }
    if (!personsVec.empty()) {
        for (const auto& person : personsVec) {
            printPerson(person);
        }
    } else {
        std::cout << "Not found Student with this " << what << '\n';
    }
}

std::string SearchOption::getName() {
    return "Search";
}

void SearchByPesel::run() {
    std::string pesel;
    std::cout << "enter the search pesel: ";
    std::cin >> pesel;
    auto personsVec = db_->searchByPesel(pesel);
    if (!personsVec.empty()) {
        for (const auto& person : personsVec) {
            printPerson(person);
        }
    } else {
        std::cout << "Not found Student with this pesel\n";
    }
}

std::string SearchByPesel::getName() {
    return "Search By Pesel";
}

void DeleteByPesel::run() {
    std::string pesel;
    std::cout << "enter the pesel to be remove: ";
    std::cin >> pesel;
    std::cout << "---------DELETE BY PESEL (AFTER)-----------\n";
    db_->deleteByPesel(pesel);
    db_->printAll();
}

std::string DeleteByPesel::getName() {
    return "Delete By Pesel";
}

void DeleteByIndexNumber::run() {
    size_t index;
    std::cout << "enter the index number to be remove: ";
    std::cin >> index;
    std::cout << "---------DELETE BY INDEX (AFTER)-----------\n";
    db_->deleteByIndex(index);
    db_->printAll();
}

std::string DeleteByIndexNumber::getName() {
    return "Delete By Index";
}

void ValidatePeselNumber::run() {
    std::string pesel;
    std::cout << "enter the pesel to be check: ";
    std::cin >> pesel;
    std::cout << "---------CHECK PESEL-----------\n";
    bool peselValid = checkPesel(pesel);
    if (peselValid) {
        std::cout << "Pesel valid\n";
    } else {
        std::cout << "Pesel not valid\n";
    }
}

std::string ValidatePeselNumber::getName() {
    return "Validate PESEL";
}

void SaveRecords::run() {
    std::cout << "---------SAVE RECORD TO FILE-----------\n";
    db_->saveToFile("db.txt");
}

std::string SaveRecords::getName() {
    return "Save Records";
}

std::array genders{Gender::Male, Gender::Female};

std::array maleNames{
    "Adam", "Karol", "Tomasz", "Jan", "Zbigniew"};

std::array femaleNames{
    "Anna", "Karolina", "Maria", "Magda", "Olga"};

std::array lastNames{
    "Kowalski", "Nowak", "Boruc", "Piątek", "Wolsztyn"};

std::array cities{
    "Gdańsk", "Bydgoszcz", "Warszawa", "Wrocław", "Kraków", "Olsztyn"};

std::array streets{
    "Gdańska", "Bydgoska", "Warszawska", "Wrocławska", "Krakowska"};

std::array streetsNumber{
    "1", "3a", "34", "5/12", "7-1"};

void GenerateStudent::run() {
    auto randomizer = [](size_t limit) {
        return rand() % limit;
    };

    auto gender = genders[randomizer(genders.size())];
    std::string name;
    if (gender == Gender::Male) {
        name = maleNames[randomizer(maleNames.size())];
    } else {
        name = femaleNames[randomizer(femaleNames.size())];
    }
    auto city = cities[randomizer(cities.size())];
    auto street = streets[randomizer(streets.size())];
    auto numberOfStreet = streetsNumber[randomizer(streetsNumber.size())];
    auto lastName = lastNames[randomizer(lastNames.size())];

    std::string pesel(11, '1');
    while (!checkPesel(pesel)) {
        for (auto& letter : pesel) {
            letter = '0' + rand() % 10;
        }
    }

    PersonType student = std::make_shared<Student>(name, lastName, city, street, numberOfStreet, randomizer(1'000'000), pesel, gender);
    auto isSuccess = db_->addPerson(student);
    if (isSuccess) {
        std::cout << "Student added.\n";
    } else {
        std::cout << "Student NOT added.\n";
    }
}

std::string GenerateStudent::getName() {
    return "Generate Student";
}

void GenerateWorker::run() {
    auto randomizer = [](size_t limit) {
        return rand() % limit;
    };

    auto gender = genders[randomizer(genders.size())];
    std::string name;
    if (gender == Gender::Male) {
        name = maleNames[randomizer(maleNames.size())];
    } else {
        name = femaleNames[randomizer(femaleNames.size())];
    }
    auto city = cities[randomizer(cities.size())];
    auto street = streets[randomizer(streets.size())];
    auto numberOfStreet = streetsNumber[randomizer(streetsNumber.size())];
    auto lastName = lastNames[randomizer(lastNames.size())];

    std::string pesel(11, '1');
    while (!checkPesel(pesel)) {
        for (auto& letter : pesel) {
            letter = '0' + rand() % 10;
        }
    }

    size_t income = rand() % 50'000;

    PersonType worker = std::make_shared<Worker>(name, lastName, city, street, numberOfStreet, pesel, gender, income);
    auto isSuccess = db_->addPerson(worker);
    if (isSuccess) {
        std::cout << "Worker added.\n";
    } else {
        std::cout << "Worker NOT added.\n";
    }
}

std::string GenerateWorker::getName() {
    return "Generate Worker";
}