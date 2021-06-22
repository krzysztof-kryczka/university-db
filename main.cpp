#include "Database.hpp"
#include "Student.hpp"
#include "Menu.hpp"
#include <iostream>

void printStudent(const Student& student);
void useCaseSort(Database& db);
void useCaseCheckPesel();
void useCaseSaveDb(const Database& db);
void useCaseDeleteDb(Database& db);
void useCaseSearchDb(const Database& db);
void useCaseLoadDb(Database& db);

int main() {
    Database db;
    db.printAll();  //for empty db print

    Menu mnu;
    mnu.selectOption(db);
}

void printStudent(const Student& student) {
    std::cout << "*******************************************\n";
    std::cout << "FirstName: " << student.getFirstName() << '\n';
    std::cout << "SurName:   " << student.getSurName() << '\n';
    std::cout << "Address:   " << student.getAddress() << '\n';
    std::cout << "Index:     " << student.getIndexNumber() << '\n';
    std::cout << "Pesel:     " << student.getPesel() << '\n';
    std::cout << "*******************************************\n";
}

void useCaseSort(Database& db) {
    db.printAll();
    std::cout << "---------SORT BY PESEL-----------\n";
    db.sortByPesel();
    db.printAll();

    std::cout << "---------SORT BY SURNAME-----------\n";
    db.sortBySurName();
    db.printAll();
}

void useCaseCheckPesel() {
    std::cout << "---------CHECK PESEL-----------\n";
    bool peselValid = checkPesel("12345678901");
    if (peselValid) {
        std::cout << "Pesel valid\n";
    } else {
        std::cout << "Pesel not valid\n";
    }
}

void useCaseSaveDb(const Database& db) {
    std::cout << "---------SAVE RECORD TO FILE-----------\n";
    db.saveToFile("db.txt");
}

void useCaseDeleteDb(Database& db) {
    db.deleteByPesel("12345678901");
    db.deleteByIndex(123);
    db.printAll();
}

void useCaseSearchDb(const Database& db) {
    auto result = db.searchByPesel("98876543210");
    if (!result.empty()) {
        for (const auto& el : result) {
            //std::cout << el;  //better but used for save file by now
            printStudent(el);
        }
    } else {
        std::cout << "Not found Student with this pesel\n";
    }
}

void useCaseLoadDb(Database& db) {
    std::cout << "---------LOAD RECORD FROM FILE-----------\n";
    db.loadFromFile("db.txt");
    db.printAll();
}
