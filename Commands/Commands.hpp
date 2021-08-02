#include "../Database.hpp"
#include "Command.hpp"

extern std::array<std::unique_ptr<Command>, 13> options_;
extern Database db_;
extern bool menuQuit;

class PrintMenu : public Command {
public:
    void run() override {
        std::cout << "*************************************" << '\n';
        std::cout << "****** UNIVERSITY-DB DATABASE *******" << '\n';
        std::cout << "*************************************" << '\n';
        int orderIndex = 0;
        for (const auto& option : options_) {
            std::cout << orderIndex << ".  " << option->getName() << '\n';
            ++orderIndex;
        }
    }

    std::string getName() {
        return "Show Menu";
    }
};

class PrintAllRecords : public Command {
public:
    void run() override {
        std::cout << "---------PRINT RECORDS FROM FILE-----------\n";
        db_.printAll();
    }

    std::string getName() {
        return "Print All Records";
    }
};

class LoadRecords : public Command {
public:
    void run() override {
        std::cout << "---------LOAD RECORD FROM FILE-----------\n";
        db_.loadFromFile("db.txt");
    }

    std::string getName() {
        return "Load Records";
    }
};

class AddStudent : public Command {
public:
    void run() override {
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
                auto isSuccess = db_.addPerson(student);
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

    std::string getName() {
        return "Add Student";
    }
};

class SortBySurname : public Command {
public:
    void run() override {
        std::cout << "---------SORT BY SURNAME (AFTER)-----------\n";
        db_.sortBySurName();
        db_.printAll();
    }

    std::string getName() {
        return "Sort By Surname";
    }
};

class SortByPesel : public Command {
public:
    void run() override {
        std::cout << "---------SORT BY PESEL (AFTER)-----------\n";
        db_.sortByPesel();
        db_.printAll();
    }

    std::string getName() {
        return "Sort By Pesel";
    }
};

class EndProgram : public Command {
public:
    void run() override {
        menuQuit = true;
    }

    std::string getName() {
        return "End Program";
    }
};

void printPerson(const PersonType& person) {
    std::cout << "*******************************************\n";
    std::cout << "FirstName: " << person->getFirstName() << '\n';
    std::cout << "SurName:   " << person->getSurName() << '\n';
    std::cout << "Address:   " << person->getAddress() << '\n';
    std::cout << "Index:     " << person->getIndexNumber() << '\n';
    std::cout << "Pesel:     " << person->getPesel() << '\n';
    std::cout << "*******************************************\n";
}

class SearchOption : public Command {
public:
    void run() override {
        std::vector<PersonType> personsVec;
        std::string what;
        std::cout << "Enter the search type: firstname / surname / city / street" << what << ":";
        std::cin >> what;

        if (what == "surname") {
            std::string surName;
            std::cout << "enter the search " << what << ": ";
            std::cin >> surName;
            personsVec = db_.searchBySurName(surName);
        } else if (what == "firstname") {
            std::string firstName;
            std::cout << "enter the search " << what << ": ";
            std::cin >> firstName;
            personsVec = db_.searchByFirstName(firstName);
        } else if (what == "city") {
            std::string city;
            std::cout << "enter the search " << what << ": ";
            std::cin >> city;
            personsVec = db_.searchByCity(city);
        } else if (what == "street") {
            std::string street;
            std::cout << "enter the search " << what << ": ";
            std::cin >> street;
            personsVec = db_.searchByStreet(street);
        } else {
            std::cout << "Error. Unknown option, please choose from : surname, firstname, city, street\n";
            return;
        }
        if (!personsVec.empty()) {
            for (const auto& person : personsVec) {
                printPerson(person);
            }
        } else {
            std::cout << "Not found Student with this " << what << '\n';
        }
    }

    std::string getName() {
        return "Search";
    }
};

class SearchByPesel : public Command {
public:
    void run() override {
        std::string p;
        std::cout << "enter the search pesel: ";
        std::cin >> p;
        auto personsVec = db_.searchByPesel(p);
        if (!personsVec.empty()) {
            for (const auto& person : personsVec) {
                printPerson(person);
            }
        } else {
            std::cout << "Not found Student with this pesel\n";
        }
    }

    std::string getName() {
        return "Search By Pesel";
    }
};

class DeleteByPesel : public Command {
public:
    void run() override {
        std::string p;
        std::cout << "enter the pesel to be remove: ";
        std::cin >> p;
        std::cout << "---------DELETE BY PESEL (AFTER)-----------\n";
        db_.deleteByPesel(p);
        db_.printAll();
    }

    std::string getName() {
        return "Delete By Pesel";
    }
};

class DeleteByIndexNumber : public Command {
public:
    void run() override {
        size_t index;
        std::cout << "enter the index number to be remove: ";
        std::cin >> index;
        std::cout << "---------DELETE BY INDEX (AFTER)-----------\n";
        db_.deleteByIndex(index);
        db_.printAll();
    }

    std::string getName() {
        return "Delete By Index";
    }
};

class ValidatePeselNumber : public Command {
public:
    void run() override {
        std::string p;
        std::cout << "enter the pesel to be check: ";
        std::cin >> p;
        std::cout << "---------CHECK PESEL-----------\n";
        bool peselValid = checkPesel(p);
        if (peselValid) {
            std::cout << "Pesel valid\n";
        } else {
            std::cout << "Pesel not valid\n";
        }
    }

    std::string getName() {
        return "Validate PESEL";
    }
};

class SaveRecords : public Command {
public:
    void run() override {
        std::cout << "---------SAVE RECORD TO FILE-----------\n";
        db_.saveToFile("db.txt");
    }

    std::string getName() {
        return "Save Records";
    }
};
