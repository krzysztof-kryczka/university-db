#pragma once
#include <map>
#include <string>
#include "../DatabaseInterface.hpp"

class Command {
public:
    virtual ~Command() = default;

    virtual void run() = 0;
    virtual std::string getName() const = 0;

    static std::unique_ptr<DatabaseInterface> db_;
};
