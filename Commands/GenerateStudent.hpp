#pragma once
#include "Command.hpp"

class GenerateStudent : public Command {
public:
    void run() override;
    std::string getName() const override;
};
