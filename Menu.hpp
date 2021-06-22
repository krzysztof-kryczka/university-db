#pragma once
#include <iostream>
#include "Database.hpp"
#include "Student.hpp"

class Menu {
public:
    Menu() {}

    void selectOption(Database& db) const;

private:
    void showMenu() const;
};
