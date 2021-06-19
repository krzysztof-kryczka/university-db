#include "Student.hpp"
#include "Database.hpp"

#include <iostream>

int main() {
    Student student{"Jan", "Nowak", "A", "a", "1", 123, "12345678901"};

    std::cout << "address: " << student.getAddress() << '\n';

    return 0;
}
