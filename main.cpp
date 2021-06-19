#include "Student.hpp"
#include "Database.hpp"

#include <iostream>

int main() {
    Student student{"Jan", "Nowak", "Poznań", "smutna", "1", 123, "12345678901", Gender::Male};
    Student student2{"Anna", "Kowalska", "Katowice", "wesoła", "1", 4321, "98876543210", Gender::Female};

    Database db;
    db.printAll();
    db.addStudent(student);
    db.addStudent(student2);
    db.printAll();

    return 0;
}
