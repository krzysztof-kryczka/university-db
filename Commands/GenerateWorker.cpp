#include "GenerateWorker.hpp"
#include <iostream>
#include "../CheckPesel.hpp"
#include "../Worker.hpp"
#include "GeneratorData.hpp"

void GenerateWorker::run() {
    auto randomizer = [](size_t limit) {
        return rand() % limit;
    };

    auto gender = genders[randomizer(genders.size())];
    std::string name;
    if (gender == Gender::Male) {
        name = maleNames[randomizer(maleNames.size())];
    } else {
        name = femaleNames[randomizer(femaleNames.size())];
    }
    auto city = cities[randomizer(cities.size())];
    auto street = streets[randomizer(streets.size())];
    auto numberOfStreet = streetsNumber[randomizer(streetsNumber.size())];
    auto lastName = lastNames[randomizer(lastNames.size())];

    std::string pesel(11, '1');
    while (!checkPesel(pesel)) {
        for (auto& letter : pesel) {
            letter = '0' + rand() % 10;
        }
    }

    size_t income = rand() % 50'000;

    PersonType worker = std::make_shared<Worker>(name, lastName, city, street, numberOfStreet, pesel, gender, income);
    auto isSuccess = db_->addPerson(worker);
    if (isSuccess) {
        std::cout << "Worker added.\n";
    } else {
        std::cout << "Worker NOT added.\n";
    }
}

std::string GenerateWorker::getName() {
    return "Generate Worker";
}
