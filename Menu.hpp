#pragma once
#include <iostream>
#include "Database.hpp"
#include "Student.hpp"

class Menu {
public:
    Menu() {}
    void run();
private:
    void showMenu() const;

    struct Option {
        using CallMethod = void (Menu::*)();
        CallMethod caledMethod;
        std::string optionDescription;
    };

    std::vector<Option> options_{
        {&Menu::printMenu, "Print Menu"},
        {&Menu::printAllRecords, "Print All Records"},
        {&Menu::loadRecords, "Load Record"},
        {&Menu::addStudent, "Add Student"},
        {&Menu::sortBySurname, "Sort By Surname"},
        {&Menu::sortByPesel, "Sort By Pesel"},
        {&Menu::searchBySurname, "Search By Surname"},
        {&Menu::searchByPesel, "Search By Pesel"},
        {&Menu::deleteByPesel, "Delete By Pesel"},
        {&Menu::deleteByIndexNumber, "Delete By Index"},
        {&Menu::validatePeselNumber, "Validate PESEL"},
        {&Menu::saveRecords, "Save Records"},
        {&Menu::endProgram, "End Program"}};

    void printMenu();
    void printAllRecords();
    void loadRecords();
    void addStudent();
    void sortBySurname();
    void sortByPesel();
    void searchBySurname();
    void searchByPesel();
    void deleteByPesel();
    void deleteByIndexNumber();
    void validatePeselNumber();
    void saveRecords();
    void endProgram();

    bool menuQuit = false;
    Database db_;
};
