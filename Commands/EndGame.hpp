#pragma once
#include "Command.hpp"

class EndProgram : public Command {
public:
    void run() override;
    std::string getName() override;
};
