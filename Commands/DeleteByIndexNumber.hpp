#pragma once
#include "Command.hpp"

class DeleteByIndexNumber : public Command {
public:
    void run() override;
    std::string getName() override;
};
