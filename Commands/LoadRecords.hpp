#pragma once
#include "Command.hpp"

class LoadRecords : public Command {
public:
    void run() override;
    std::string getName() const override;
};
