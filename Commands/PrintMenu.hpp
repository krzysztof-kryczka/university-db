#pragma once
#include "Command.hpp"

class PrintMenu : public Command {
public:
    PrintMenu(const std::map<std::string, std::shared_ptr<Command>>& options,
            std::vector<std::string> order);

    void run() override;
    std::string getName() const override;

private:
    const std::map<std::string, std::shared_ptr<Command>>& options_;
    std::vector<std::string> order_;
};
