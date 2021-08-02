#pragma once

#include <string>

struct Address {
    std::string city_{};
    std::string street_{};
    std::string numberOfStreet_{};

    std::string getAddress() const {
        if(city_.empty() and street_.empty() and numberOfStreet_.empty()){
            return {};
        }
        return city_ + " " + street_ + " " + numberOfStreet_;
    }
};
