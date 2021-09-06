#pragma once
#include <map>
#include <string>
#include "../DatabaseInterface.hpp"

class Command {
public:
    virtual ~Command() = default;

    virtual void run() = 0;
    virtual std::string getName() = 0;

    static std::map<std::string, std::shared_ptr<Command>> options_;
    static std::unique_ptr<DatabaseInterface> db_;
    static std::vector<std::string> order_;
    static bool quit;
};
