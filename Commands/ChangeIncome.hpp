#pragma once
#include "Command.hpp"

class ChangeIncome : public Command {
public:
    void run() override;
    std::string getName() const override;
};
