
#include "../DatabaseInterface.hpp"
#include "Command.hpp"

class PrintMenu : public Command {
public:
    void run() override;
    std::string getName() override;
};

class PrintAllRecords : public Command {
public:
    void run() override;
    std::string getName() override;
};

class LoadRecords : public Command {
public:
    void run() override;
    std::string getName() override;
};

class AddStudent : public Command {
public:
    void run() override;
    std::string getName() override;
};

class SortBySurname : public Command {
public:
    void run() override;
    std::string getName() override;
};

class SortByPesel : public Command {
public:
    void run() override;
    std::string getName() override;
};

class SortByIncome : public Command {
public:
    void run() override;
    std::string getName() override;
};

class EndProgram : public Command {
public:
    void run() override;
    std::string getName() override;
};

class SearchOption : public Command {
public:
    void run() override;
    std::string getName() override;
};

class SearchByPesel : public Command {
public:
    void run() override;
    std::string getName() override;
};

class DeleteByPesel : public Command {
public:
    void run() override;
    std::string getName() override;
};

class DeleteByIndexNumber : public Command {
public:
    void run() override;
    std::string getName() override;
};

class ValidatePeselNumber : public Command {
public:
    void run() override;
    std::string getName() override;
};

class SaveRecords : public Command {
public:
    void run() override;
    std::string getName() override;
};

class GenerateStudent : public Command {
public:
    void run() override;
    std::string getName() override;
};

class GenerateWorker: public Command {
public:
    void run() override;
    std::string getName() override;
};
