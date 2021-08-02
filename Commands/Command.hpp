#pragma once

#include <string>

class Command{
public:
    Command() = default;
    virtual ~Command() = default;

    virtual void run() = 0;
    virtual std::string getName() = 0;
};