#pragma once
#include "Command.hpp"

class DeleteByPesel : public Command {
public:
    void run() override;
    std::string getName() const override;
};
