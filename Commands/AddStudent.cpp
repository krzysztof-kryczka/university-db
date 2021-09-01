#include "AddStudent.hpp"
#include "../CheckPesel.hpp"
#include "../Gender.hpp"
#include "../Student.hpp"

void AddStudent::run() {
    std::string firstName;
    std::string surName;
    std::string city;
    std::string street;
    std::string numberOfStreet;
    std::string pesel;
    std::string indexNumber;
    std::string genderInput;
    size_t index;
    Gender gender = Gender::Undefined;

    std::cout << "\n First Name: ";
    std::cin >> firstName;

    std::cout << " Surname: ";
    std::cin >> surName;

    std::cout << " Address (city): ";
    std::cin >> city;

    std::cout << " Address (street): ";
    std::cin >> street;

    std::cout << " Address (numberOfStreet): ";
    std::cin >> numberOfStreet;

    std::cout << " Index Number: ";
    std::cin >> indexNumber;
    index = std::stoi(indexNumber);

    std::cout << " Gender [Male][Female][Undefined] : ";
    std::cin >> genderInput;
    gender = textToGender(genderInput);
    std::cout << "Gender set : " << translateGender(gender) << '\n';

    int incorrectPeselTries = 3;
    while (true) {
        std::cout << " Pesel: ";
        std::cin >> pesel;

        if (checkPesel(pesel)) {
            PersonType student = std::make_shared<Student>(firstName, surName, city, street, numberOfStreet, index, pesel, gender);
            auto isSuccess = db_->addPerson(student);
            if (isSuccess) {
                std::cout << "Student added.\n";
            } else {
                std::cout << "Student NOT added.\n";
            }
            return;
        }

        std::cout << "\nError: wrong PESEL number!\n";
        --incorrectPeselTries;
        char letter = 0;

        std::cout << " Try insert PESEL again (y/n)\n";
        std::cin >> letter;
        std::cout << letter << '\n';

        if (letter == 'n' or incorrectPeselTries == 0) {
            std::cout << "\nStudent NOT added!\n";
            return;
        }
    }
}

std::string AddStudent::getName() {
    return "Add Student";
}
