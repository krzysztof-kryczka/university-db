#pragma once

#include <array>
#include <string>

enum class Gender : char {
    Male,
    Female,
    Undefined
};

constexpr std::array genderIdx = {
    Gender::Male, Gender::Female, Gender::Undefined};

constexpr std::array genderText = {
    "Male", "Female", "Undefined"};

Gender textToGender(const std::string& text);
std::string translateGender(const Gender& gender);
std::string translateGender(int genderId);
