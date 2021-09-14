#include "ChangeIncome.hpp"
#include "../CheckPesel.hpp"
#include "../Student.hpp"

#include <iostream>

void ChangeIncome::run() {
    std::string pesel;
    std::string income;
    char letter = 0;

    int incorrectPeselTries = 3;
    while (true) {
        std::cout << "\n Worker Pesel: ";
        std::cin >> pesel;

        if (checkPesel(pesel)) {
            //search worker with pesel
            const auto workers = db_->searchByPesel(pesel);
            if(workers.size() != 1){
                std::cout << "\nNo worker with this pesel in database.\n";
                continue;
            }

            if(auto income = workers[0]->getIncome(); !income){
                std::cout << "\nThis person is not worker.\n";
                continue;
            } 

            //print worker
            workers[0]->printPerson();

            //wanna change income?
            letter = 0;
            std::cout << " Want to change income (y/n)\n";
            std::cin >> letter;
            std::cout << letter << '\n';

            if (letter == 'n') {
                std::cout << "\nNo change.\n";
                return;
            }

            size_t income = 0;
            std::string incomeText;
            std::cout << " New Income value:\n";
            std::cin >> incomeText;
            income = std::stoi(incomeText);
            if(income < 0){
                std::cout << "\nNo change (less than zero ignored).\n";
                return;
            }
            workers[0]->setIncome(income);
            std::cout << "\nIncome changed to: " << income << '\n';
            return;
        }

        std::cout << "\nError: PESEL number not walid!\n";
        --incorrectPeselTries;
        letter = 0;

        std::cout << " Try insert PESEL again (y/n)\n";
        std::cin >> letter;
        std::cout << letter << '\n';

        if (letter == 'n' or incorrectPeselTries == 0) {
            std::cout << "\nNo change.\n";
            return;
        }
    }
}

std::string ChangeIncome::getName() const {
    return "Change income";
}
