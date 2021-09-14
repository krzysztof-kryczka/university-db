#pragma once
#include "Command.hpp"

class SearchByPesel : public Command {
public:
    void run() override;
    std::string getName() const override;
};
