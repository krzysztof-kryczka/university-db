#include "ValidatePeselNumber.hpp"
#include <iostream>
#include "../CheckPesel.hpp"

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
