#include "Student.hpp"
#include "Database.hpp"

#include <iostream>

int main() {
    Student student{"Jan", "Nowak", "Poznań", "smutna", "1", 123, "12345678901", Gender::Male};
    Student student2{"Anna", "Kowalska", "Katowice", "wesoła", "1", 4321, "98876543210", Gender::Female};
    Student student3{"Anna", "Aleksandra", "Katowice", "wesoła", "1", 4321, "58876543210", Gender::Female};

    Database db;
    db.printAll();
    db.addStudent(student);
    db.addStudent(student2);
    db.addStudent(student3);
    db.printAll();

    std::cout<<"---------SORT BY PESEL-----------\n";
    db.sortByPesel();
    db.printAll();

    std::cout<<"---------SORT BY SURENAME-----------\n";
    db.sortbySurename();
    db.printAll();

    std::cout<<"---------SAVE EXSISTS RECORD TO FILE-----------\n";
    db.saveToFile("db.txt");
    
    return 0;
}
