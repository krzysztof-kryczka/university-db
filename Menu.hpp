#pragma once
#include <iostream>
#include "Database.hpp"
#include "Student.hpp"

class Menu {
public:
    Menu() {}
    void run();
private:
    
    struct Option {
        using CallMethod = void (Menu::*)();
        CallMethod caledMethod;
        std::string optionDescription;
    };

    std::vector<Option> options_{
        {&Menu::printMenu, "Show Menu"},
        {&Menu::printAllRecords, "Print All Records"},
        {&Menu::loadRecords, "Load Record"},
        {&Menu::addStudent, "Add Student"},
        {&Menu::sortBySurname, "Sort By Surname"},
        {&Menu::sortByPesel, "Sort By Pesel"},
        {&Menu::searchOption, "Search"},
        {&Menu::searchByPesel, "Search By Pesel"},
        {&Menu::deleteByPesel, "Delete By Pesel"},
        {&Menu::deleteByIndexNumber, "Delete By Index"},
        {&Menu::validatePeselNumber, "Validate PESEL"},
        {&Menu::saveRecords, "Save Records"},
        {&Menu::endProgram, "End Program"}};

    void showMenu() const;

    void printMenu(){showMenu();}

    void printAllRecords();

    void loadRecords();

    void addStudent();

    void sortBySurname();
    void sortByPesel();

    void searchOption();
    void searchByPesel();

    void deleteByPesel();
    void deleteByIndexNumber();

    void validatePeselNumber();
    void saveRecords();
    void endProgram();

    bool menuQuit = false;
    Database db_;

    void printStudent(const Student& student) const;
};
