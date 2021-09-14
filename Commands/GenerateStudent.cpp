#include "GenerateStudent.hpp"
#include "../CheckPesel.hpp"
#include "../Student.hpp"
#include "GeneratorData.hpp"

void GenerateStudent::run() {
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

    PersonType student = std::make_shared<Student>(name, lastName, city, street, numberOfStreet, randomizer(1'000'000), pesel, gender);
    auto isSuccess = db_->addPerson(student);
    if (isSuccess) {
        std::cout << "Student added.\n";
    } else {
        std::cout << "Student NOT added.\n";
    }
}

std::string GenerateStudent::getName() const {
    return "Generate Student";
}
