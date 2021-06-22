#include "Menu.hpp"

void Menu::showMenu() const {
    std::cout << "*************************************" << '\n';
    std::cout << "****** UNIVERSITY-DB DATABASE *******" << '\n';
    std::cout << "*************************************" << '\n';
    int lp = 0;
    for (const auto& option : options_) {
        std::cout << lp++ << ".  " << option.optionDescription << '\n';
    }
}

void Menu::run() {
    size_t chosedOption = options_.size();
    Menu::showMenu();

    auto runOption = [this](size_t index) {
        if (index >= 0 and index < options_.size()) {
            (this->*options_[index].caledMethod)();  //ugly i know
        } else {
            std::cout << "Wrong option!\n";
        }
    };

    while (!menuQuit) {
        std::cout << "Select Option: ";
        std::cin >> chosedOption;
        runOption(chosedOption);
    }
}

void Menu::printMenu(){
    showMenu();
}

void Menu::printAllRecords(){
    std::cout << "---------PRINT RECORDS FROM FILE-----------\n";
    db_.printAll();
}

void Menu::loadRecords() {
    std::cout << "---------LOAD RECORD FROM FILE-----------\n";
    db_.loadFromFile("db.txt");
}
void Menu::addStudent() {
    std::string firstName, surName, city, street, numberOfStreet, pesel;
    size_t indexNumber;
    std::string genderInput;
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

    std::cout << " Gender [male][female][Undefined] : ";
    std::cin >> genderInput;

    std::vector sexes{Gender::Male, Gender::Female, Gender::Undefined};
    for (const auto& sex : sexes) {
        if (translateGender[sex] == genderInput) {
            std::cout << " Gender selected: " << translateGender[sex] << '\n';
            gender = sex;
        }
    }
    int incorrectPeselTries = 3;
    while (true) {
        std::cout << " Pesel: ";
        std::cin >> pesel;

        if (checkPesel(pesel)) {
            Student s{firstName, surName, city, street, numberOfStreet, indexNumber, pesel, gender};
            db_.addStudent(s);
            std::cout << "Student added.\n";
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
void Menu::sortBySurname() {
    std::cout << "---------SORT BY SURNAME (AFTER)-----------\n";
    db_.sortBySurName();
    db_.printAll();
}
void Menu::sortByPesel() {
    std::cout << "---------SORT BY PESEL (AFTER)-----------\n";
    db_.sortByPesel();
    db_.printAll();
}
void Menu::searchBySurname() {
    std::cout << "NOT IMPMLEMENTED\n";
}
void Menu::searchByPesel() {
    std::string p;
    std::cout << "enter the search pesel: ";
    std::cin >> p;
    auto result = db_.searchByPesel(p);
    if (!result.empty()) {
        int i = 1;
        for (const auto& el : result) {
            //std::cout << el;  //better but used for save file by now
            std::cout << "\n****************** record: " << i << " ******************\n";
            std::cout << "FirstName: " << el.getFirstName() << '\n';
            std::cout << "SurName:   " << el.getSurName() << '\n';
            std::cout << "Address:   " << el.getAddress() << '\n';
            std::cout << "Index:     " << el.getIndexNumber() << '\n';
            std::cout << "Pesel:     " << el.getPesel() << '\n';
            std::cout << "***********************************************\n";
            i++;
        }
    } else {
        std::cout << "Not found Student with this pesel\n";
    }
}
void Menu::deleteByPesel() {
    std::string p;
    std::cout << "enter the pesel to be remove: ";
    std::cin >> p;
    std::cout << "---------DELETE BY PESEL (AFTER)-----------\n";
    db_.deleteByPesel(p);
    db_.printAll();
}
void Menu::deleteByIndexNumber() {
    size_t index;
    std::cout << "enter the index number to be remove: ";
    std::cin >> index;
    std::cout << "---------DELETE BY INDEX (AFTER)-----------\n";
    db_.deleteByIndex(index);
    db_.printAll();
}
void Menu::validatePeselNumber() {
    std::string p;
    std::cout << "enter the pesel to be check: ";
    std::cin >> p;
    std::cout << "---------CHECK PESEL-----------\n";
    bool peselValid = checkPesel(p);
    if (peselValid) {
        std::cout << "Pesel valid\n";
    } else {
        std::cout << "Pesel not valid\n";
    }
}
void Menu::saveRecords() {
    std::cout << "---------SAVE RECORD TO FILE-----------\n";
    db_.saveToFile("db.txt");
}
void Menu::endProgram() {
    menuQuit = true;
}
