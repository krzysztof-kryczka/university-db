#pragma once
#include "Command.hpp"

class SearchOption : public Command {
public:
    void run() override;
    std::string getName() const override;
};
