#pragma once
#include <array>
#include "../Gender.hpp"

constexpr std::array genders{Gender::Male, Gender::Female};

constexpr std::array maleNames{
    "Adam", "Karol", "Tomasz", "Jan", "Zbigniew"};

constexpr std::array femaleNames{
    "Anna", "Karolina", "Maria", "Magda", "Olga"};

constexpr std::array lastNames{
    "Kowalski", "Nowak", "Boruc", "Piątek", "Wolsztyn"};

constexpr std::array cities{
    "Gdańsk", "Bydgoszcz", "Warszawa", "Wrocław", "Kraków", "Olsztyn"};

constexpr std::array streets{
    "Gdańska", "Bydgoska", "Warszawska", "Wrocławska", "Krakowska"};

constexpr std::array streetsNumber{
    "1", "3a", "34", "5/12", "7-1"};