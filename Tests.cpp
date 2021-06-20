#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include <vector>
#include <array>
#include "Database.hpp"

constexpr auto nonExistPesel = "90000000000";
constexpr auto anotherExistPesel = "01234567890";
constexpr auto onceExistPesel = "00000000000";
constexpr auto twiceExistPesel = "11111111111";

constexpr std::array studentName = {
    "A", "B", "C", "D"};

const std::vector students = {
    Student(studentName[0], "A", "A", "A", "A", 0, anotherExistPesel, Gender::Undefined), 
    Student(studentName[1], "A", "A", "A", "A", 1, onceExistPesel, Gender::Undefined), 
    Student(studentName[2], "A", "A", "A", "A", 2, twiceExistPesel, Gender::Undefined), 
    Student(studentName[3], "A", "A", "A", "A", 3, twiceExistPesel, Gender::Undefined)
};

TEST_CASE("Search by PESEL in empty database", "[Database][Search][PESEL]") {
    //given
    Database db{};
    //when
    auto result = db.searchByPesel(nonExistPesel);
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search by PESEL what not exist", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel(nonExistPesel);
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search by PESEL what exist once", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel(onceExistPesel);
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 1);
    REQUIRE(result[0].getFirstName() == studentName[1]);
}

TEST_CASE("Search by PESEL what exist twice", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel(twiceExistPesel);
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 2);
    REQUIRE(result[0].getFirstName() == studentName[2]);
    REQUIRE(result[1].getFirstName() == studentName[3]);
}

TEST_CASE("Delete by PESEL in empty database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    //when
    db.deleteByPesel(nonExistPesel);
    //then
    REQUIRE(db.getNumberOfStudents() == 0);
}

TEST_CASE("Delete by nonexist PESEL in database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    db.deleteByPesel(nonExistPesel);
    //then
    REQUIRE(db.getNumberOfStudents() == students.size());
}

TEST_CASE("Delete by PESEL exist once in database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    db.deleteByPesel(onceExistPesel);
    //then
    REQUIRE(db.getNumberOfStudents() == students.size()-1);
}

TEST_CASE("Delete by PESEL exist twice in database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    db.deleteByPesel(twiceExistPesel);
    //then
    REQUIRE(db.getNumberOfStudents() == students.size()-2);
}