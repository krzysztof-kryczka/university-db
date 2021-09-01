#pragma once
#include "Command.hpp"

class PrintMenu : public Command {
public:
    void run() override;
    std::string getName() override;
};
