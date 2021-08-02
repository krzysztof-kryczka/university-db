#include "Command.hpp"

extern std::array<std::unique_ptr<Command>,13> options_;
extern Database db_;
extern bool menuQuit;

class PrintMenu: public Command{
public:
    void run() override{
        std::cout << "*************************************" << '\n';
        std::cout << "****** UNIVERSITY-DB DATABASE *******" << '\n';
        std::cout << "*************************************" << '\n';
        int orderIndex = 0;
        for (const auto& option : options_) {
            std::cout << orderIndex << ".  " << option->getName() << '\n';
            ++orderIndex;
        }
    }

    std::string getName(){
        return "Show Menu";
    }
};

class PrintAllRecords: public Command{
public:
    void run() override{
        std::cout << "---------PRINT RECORDS FROM FILE-----------\n";
        db_.printAll();
    }

    std::string getName(){
        return "Print All Records";
    }
};

class LoadRecords: public Command{
public:
    void run() override{
        std::cout << "---------LOAD RECORD FROM FILE-----------\n";
        db_.loadFromFile("db.txt");
    }

    std::string getName(){
        return "Load Records";
    }
};

class AddStudent: public Command{
public:
    void run() override{
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
                Student s{firstName, surName, city, street, numberOfStreet, index, pesel, gender};
                auto isSuccess = db_.addStudent(s);
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

    std::string getName(){
        return "Add Student";
    }
};

class SortBySurname: public Command{
public:
    void run() override{
        std::cout << "---------SORT BY SURNAME (AFTER)-----------\n";
        db_.sortBySurName();
        db_.printAll();
    }

    std::string getName(){
        return "Sort By Surname";
    }
};

class SortByPesel: public Command{
public:
    void run() override{
        std::cout << "---------SORT BY PESEL (AFTER)-----------\n";
        db_.sortByPesel();
        db_.printAll();
    }

    std::string getName(){
        return "Sort By Pesel";
    }
};

class EndProgram: public Command{
public:
    void run() override{
        menuQuit = true;
    }

    std::string getName(){
        return "End Program";
    }
};

void printStudent(const Student& student){
    std::cout << "*******************************************\n";
    std::cout << "FirstName: " << student.getFirstName() << '\n';
    std::cout << "SurName:   " << student.getSurName() << '\n';
    std::cout << "Address:   " << student.getAddress() << '\n';
    std::cout << "Index:     " << student.getIndexNumber() << '\n';
    std::cout << "Pesel:     " << student.getPesel() << '\n';
    std::cout << "*******************************************\n";
}

class SearchOption: public Command{
public:
    void run() override{
        std::vector<Student> result;
        std::string what;
        std::cout << "Enter the search type: firstname / surname / city / street" << what << ":";
        std::cin >> what;

        if (what == "surname") {
            std::string sn;
            std::cout << "enter the search " << what << ": ";
            std::cin >> sn;
            result = db_.searchBySurName(sn);
        } else if (what == "firstname") {
            std::string fn;
            std::cout << "enter the search " << what << ": ";
            std::cin >> fn;
            result = db_.searchByFirstName(fn);
        } else if (what == "city") {
            std::string ct;
            std::cout << "enter the search " << what << ": ";
            std::cin >> ct;
            result = db_.searchByCity(ct);
        } else if (what == "street") {
            std::string st;
            std::cout << "enter the search " << what << ": ";
            std::cin >> st;
            result = db_.searchByStreet(st);
        } else {
            std::cout << "Error. Unknown option, please choose from : surname, firstname, city, street\n";
            return;
        }
        if (!result.empty()) {
            for (const auto& el : result) {
                printStudent(el);
            }
        } else {
            std::cout << "Not found Student with this " << what << '\n';
        }
    }

    std::string getName(){
        return "Search";
    }
};

class SearchByPesel: public Command{
public:
    void run() override{
        std::string p;
        std::cout << "enter the search pesel: ";
        std::cin >> p;
        auto result = db_.searchByPesel(p);
        if (!result.empty()) {
            for (const auto& el : result) {
                printStudent(el);
            }
        } else {
            std::cout << "Not found Student with this pesel\n";
        }
    }

    std::string getName(){
        return "Search By Pesel";
    }
};

class DeleteByPesel: public Command{
public:
    void run() override{
        std::string p;
        std::cout << "enter the pesel to be remove: ";
        std::cin >> p;
        std::cout << "---------DELETE BY PESEL (AFTER)-----------\n";
        db_.deleteByPesel(p);
        db_.printAll();
    }

    std::string getName(){
        return "Delete By Pesel";
    }
};

class DeleteByIndexNumber: public Command{
public:
    void run() override{
        size_t index;
        std::cout << "enter the index number to be remove: ";
        std::cin >> index;
        std::cout << "---------DELETE BY INDEX (AFTER)-----------\n";
        db_.deleteByIndex(index);
        db_.printAll();
    }

    std::string getName(){
        return "Delete By Index";
    }
};

class ValidatePeselNumber: public Command{
public:
    void run() override{
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

    std::string getName(){
        return "Validate PESEL";
    }
};

class SaveRecords: public Command{
public:
    void run() override{
        std::cout << "---------SAVE RECORD TO FILE-----------\n";
        db_.saveToFile("db.txt");
    }

    std::string getName(){
        return "Save Records";
    }
};