#include <cmath>
#include <iostream>
#include <string>

int testCheckPesel () {
    std::string numberCheck;
    const std::string& listValidation = "1379137913";
    int sum = 0;
    std::cout << "Write the Pesel number: ";
    getline (std::cin, numberCheck);

    if (numberCheck.size() != 11) {
        std::cout << "The length of pesel number is incorrect" << '\n';
        return 0;
    }
    for (auto i = 0 ; i < 10 ; i++) {
        sum += ((numberCheck [i] - '0') * (listValidation [i] - '0')) % 10;
    }
    
    if (sum > 10) {
        sum = sum % 10;
    } 
    
    if (sum) {
        sum = 10 - sum;
    }

    if (sum == (numberCheck[10] - '0')) {
        std::cout << "Pesel number it's correct!" << '\n';
    } else {
        std::cout << "Pesel number it's not correct" << '\n';
    }
}
