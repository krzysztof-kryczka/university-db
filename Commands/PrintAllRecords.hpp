#pragma once
#include "Command.hpp"

class PrintAllRecords : public Command {
public:
    void run() override;
    std::string getName() const override;
};
