#pragma once
#include "Command.hpp"

class GenerateWorker : public Command {
public:
    void run() override;
    std::string getName() const override;
};
