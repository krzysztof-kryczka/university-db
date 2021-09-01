#pragma once
#include "Command.hpp"

class SortBySurname : public Command {
public:
    void run() override;
    std::string getName() override;
};
