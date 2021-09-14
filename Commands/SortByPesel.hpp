#pragma once
#include "Command.hpp"

class SortByPesel : public Command {
public:
    void run() override;
    std::string getName() const override;
};
