#include "Gender.hpp"

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