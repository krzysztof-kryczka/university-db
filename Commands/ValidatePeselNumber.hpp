#pragma once
#include "Command.hpp"

class ValidatePeselNumber : public Command {
public:
    void run() override;
    std::string getName() const override;
};
