#pragma once
#include "Command.hpp"

class EndProgram : public Command {
public:
    EndProgram(bool& end);

    void run() override;
    std::string getName() const override;
private:
    bool& end_;
};
