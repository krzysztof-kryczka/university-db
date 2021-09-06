#pragma once
#include "Command.hpp"

class SortByIncome : public Command {
public:
    void run() override;
    std::string getName() override;
};
