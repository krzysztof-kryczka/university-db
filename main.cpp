#include "Student.hpp"
#include "Database.hpp"

#include <iostream>

int main() {
    Student student{"Jan", "Nowak", "Poznań", "smutna", "1", 123, "12345678901", Gender::Male};
    Student student2{"Anna", "Kowalska", "Katowice", "wesoła", "1", 4321, "98876543210", Gender::Female};
    Student student3{"Justyna", "Dunka", "Poznan", "wesoła", "1", 4321, "98876543210", Gender::Female};

    Database db;
    db.printAll();
    db.addStudent(student);
    db.addStudent(student2);
    db.addStudent(student3);
    db.printAll();
    auto result = db.searchByPesel("98876543210");
    if (!result.empty()) {
           for (const auto& el : result) {
                std::cout << el.getFirstName() << "  ";
                std::cout << el.getSureName() << ", ";
                std::cout << el.getAddress() << " | Pesel: ";
                std::cout << el.getPesel() << '\n';
           } 
    }
    else {
        std::cout << "Not found Student with this pesel\n";
    }
    return 0;
}
