#pragma once
#include "Command.hpp"

class SaveRecords : public Command {
public:
    void run() override;
    std::string getName() const override;
};
