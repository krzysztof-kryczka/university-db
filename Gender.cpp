#include "Gender.hpp"

namespace {
constexpr std::array genderIdx = {
    Gender::Male, Gender::Female, Gender::Undefined};

constexpr std::array genderText = {
    "Male", "Female", "Undefined"};    
}

Gender textToGender(const std::string& text) {
    size_t idx = 0;
    for (const auto& gender : genderText) {
        if (text == gender) {
            return genderIdx[idx];
        }
        ++idx;
    }
    return Gender::Undefined;
}

std::string translateGender(const Gender& gender) {
    auto idx = static_cast<char>(gender);
    if (idx >= genderText.size()) {
        return {};
    }
    return genderText[idx];
}

std::string translateGender(int genderId) {
    if (genderId >= genderText.size()) {
        return {};
    }
    return genderText[genderId];
}
