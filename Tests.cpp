#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "Database.hpp"
#include <vector>

const std::vector students = {
    Student("A", "A", "A", "A", "A", 0, "01234567890", Gender::Undefined),
    Student("B", "A", "A", "A", "A", 1, "00000000000", Gender::Undefined),
    Student("C", "A", "A", "A", "A", 2, "11111111111", Gender::Undefined),
    Student("D", "A", "A", "A", "A", 3, "11111111111", Gender::Undefined)};

TEST_CASE("Search PESEL in empty database", "[Database][Search][PESEL]") {
    //given
    Database db{};
    //when
    auto result = db.searchByPesel("00000000000");
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search PESEL what not exist", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel("90000000000");
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search PESEL what exist once", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel("00000000000");
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 1);
    REQUIRE(result[0].getFirstName() == "B");
}

TEST_CASE("Search PESEL what exist twice", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel("11111111111");
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 2);
    REQUIRE(result[0].getFirstName() == "C");
    REQUIRE(result[1].getFirstName() == "D");
}