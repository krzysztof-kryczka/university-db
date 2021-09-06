#pragma once
#include "Command.hpp"

class AddStudent : public Command {
public:
    void run() override;
    std::string getName() override;
};
