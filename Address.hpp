#pragma once

#include <string>

constexpr auto defaultName = "UNDEFINED";
struct Address {
    std::string city_ = defaultName;
    std::string street_ = defaultName;
    std::string numberOfStreet_ = defaultName;

    std::string getAddress() const {
        return city_ + " " + street_ + " " + numberOfStreet_;
    }
};
