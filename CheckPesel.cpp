#include "CheckPesel.hpp"

bool checkPesel(std::string pesel) {
    const std::string& listValidation = "1379137913";
    int sum = 0;
    if (pesel.size() != 11) {
        return false;
    }
    for (auto i = 0; i < 10; i++) {
        sum += ((pesel[i] - '0') * (listValidation[i] - '0')) % 10;
    }
    if (sum > 10) {
        sum = sum % 10;
    }
    if (sum) {
        sum = 10 - sum;
    }
    return sum == (pesel[10] - '0');
}
