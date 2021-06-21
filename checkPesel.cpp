#include <cmath>
#include <iostream>
#include <string>

bool testCheckPesel (std::string pesel) {
    //std::string numberCheck;
    const std::string& listValidation = "1379137913";
    
    //std::cout << "Write the Pesel number: ";
    //getline (std::cin, numberCheck);

    int sum = 0;
    if (pesel.size() != 11) {
        std::cout << "The length of pesel number is incorrect" << '\n';
        return 0;
    }
    for (auto i = 0 ; i < 10 ; i++) {
        sum += ((pesel [i] - '0') * (listValidation [i] - '0')) % 10;
    }
    
    if (sum > 10) {
        sum = sum % 10;
    } 
    
    if (sum) {
        sum = 10 - sum;
    }

    if (sum == (pesel[10] - '0')) {
        return 1;
    } else {
        return 0;
    }
}

