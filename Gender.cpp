#include "Gender.hpp"
#include <map>

namespace {
const std::map<Gender, const std::string> genderToString{
    {Gender::Male, "Male"},
    {Gender::Female, "Female"},
    {Gender::Undefined, "Undefined"}
};

const std::map<std::string, Gender> stringToGender{
    {"Male", Gender::Male},
    {"Female", Gender::Female},
    {"Undefined", Gender::Undefined}
};
}

Gender textToGender(const std::string& text) {
    if(auto it = stringToGender.find(text); it != stringToGender.end()){
        return it->second;
    }
    return Gender::Undefined;
}

std::string translateGender(Gender gender) {
    return genderToString.at(gender);
}
