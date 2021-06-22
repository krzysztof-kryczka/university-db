#include "Menu.hpp"

void Menu::showMenu() const {
    std::cout << "*************************************" << '\n';
    std::cout << "****** UNIVERSITY-DB DATABASE *******" << '\n';
    std::cout << "*************************************" << '\n';
    std::cout << "1. Load records from database file" << '\n';
    std::cout << "2. Add new student to database" << '\n';
    std::cout << "3. Sort by SURNAME" << '\n';
    std::cout << "4. Sort by PESEL" << '\n';
    std::cout << "5. Search student by SURNAME" << '\n';
    std::cout << "6. Search student by PESEL" << '\n';
    std::cout << "7. Delete by / PESEL" << '\n';
    std::cout << "8. Delete by INDEX NUMBER" << '\n';
    std::cout << "9. Validation PESEL number" << '\n';
    std::cout << "10. Save all records to database file" << '\n';
    std::cout << "0. Exit" << '\n';
}

void Menu::selectOption(Database& db) const {
    int option = 1;

    Menu::showMenu();

    while (true) {
        std::cout << "Select Option: ";
        std::cin >> option;

        switch (option) {
        case 1: {
            std::cout << "---------LOAD RECORD FROM FILE-----------\n";
            db.loadFromFile("db.txt");
            db.printAll();
            break;
        }
        case 2: {
            db.addStudent();
            db.printAll();
            break;
        }
        case 3: {
            std::cout << "---------SORT BY SURNAME (BEFORE)-----------\n";
            db.printAll();
            std::cout << "---------SORT BY SURNAME (AFTER)-----------\n";
            db.sortBySurName();
            db.printAll();
            break;
        }
        case 4: {
            std::cout << "---------SORT BY PESEL (BEFORE)-----------\n";
            db.printAll();
            std::cout << "---------SORT BY PESEL (AFTER)-----------\n";
            db.sortByPesel();
            db.printAll();
            break;
        }
        case 5: {
            std::cout << "NOT IMPMLEMENTED\n";
            break;
        }
        case 6: {
            std::string p;
            std::cout << "enter the search pesel: ";
            std::cin >> p;
            auto result = db.searchByPesel(p);
            if (!result.empty()) {
                int i = 1;
                for (const auto& el : result) {
                    //std::cout << el;  //better but used for save file by now
                    std::cout << "\n****************** record: " << i << " ******************\n";
                    std::cout << "FirstName: " << el.getFirstName() << '\n';
                    std::cout << "SurName:   " << el.getSurName() << '\n';
                    std::cout << "Address:   " << el.getAddress() << '\n';
                    std::cout << "Index:     " << el.getIndexNumber() << '\n';
                    std::cout << "Pesel:     " << el.getPesel() << '\n';
                    std::cout << "***********************************************\n";
                    i++;
                }
            } else {
                std::cout << "Not found Student with this pesel\n";
            }
            break;
        }
        case 7: {
            std::string p;
            std::cout << "enter the pesel to be remove: ";
            std::cin >> p;
            std::cout << "---------DELETE BY PESEL (BEFORE)-----------\n";
            db.printAll();
            std::cout << "---------DELETE BY PESEL (AFTER)-----------\n";
            db.deleteByPesel(p);
            db.printAll();
            break;
        }
        case 8: {
            size_t index;
            std::cout << "enter the index number to be remove: ";
            std::cin >> index;
            std::cout << "---------DELETE BY INDEX (BEFORE)-----------\n";
            db.printAll();
            std::cout << "---------DELETE BY INDEX (AFTER)-----------\n";
            db.deleteByIndex(index);
            db.printAll();
            break;
        }
        case 9: {
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
            break;
        }
        case 10: {
            std::cout << "---------SAVE RECORD TO FILE-----------\n";
            db.saveToFile("db.txt");
            break;
        }
        case 0: {
            exit(0);
        }
        default: {
            std::cout << "Wrong option!\n";
        }
        }
    }
}
