#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include <vector>
#include <array>
#include "Database.hpp"

constexpr auto nonExistPesel = "90000000000";
constexpr auto anotherExistPesel = "01234567890";
constexpr auto onceExistPesel = "00000000000";
constexpr auto secondExistPesel = "11111111111";

constexpr std::array studentName = {
    "A", "B", "C", "D", "E"};

constexpr auto nonExistSurName = "Kazmierczak";
constexpr auto onceExistSurName = "Nowak";
constexpr auto twiceExistSurName = "Kowalski";

constexpr std::array studentSurName = {
    "Nowak", "Kowalski", "Kowalski", "Prono", "Bono"};

Student otherStudent(studentName[4], studentSurName[4], "A", "A", "A", 0, nonExistPesel, Gender::Undefined);

const std::vector students = {
    Student(studentName[0], studentSurName[0], "A", "A", "A", 0, anotherExistPesel, Gender::Undefined), 
    Student(studentName[1], studentSurName[1], "A", "A", "A", 1, onceExistPesel, Gender::Undefined), 
    Student(studentName[2], studentSurName[2], "A", "A", "A", 2, secondExistPesel, Gender::Undefined)
};

constexpr auto baseStudentsSize = 3;

TEST_CASE("Add Student to empty database", "[Database][Add]") {
    //given
    Database db{};
    //when
    db.addStudent(students[0]);
    //then
    REQUIRE(db.getNumberOfStudents() == 1);
}

TEST_CASE("Add new Student to existing database", "[Database][Add]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    auto sizeBefore = db.getNumberOfStudents();
    //when
    db.addStudent(otherStudent);
    //then
    REQUIRE(db.getNumberOfStudents() == sizeBefore + 1);
}

//should not add existing student
TEST_CASE("Add existing in database student", "[Database][Add]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    auto sizeBefore = db.getNumberOfStudents();
    //when
    db.addStudent(students[0]);
    //then
    REQUIRE(db.getNumberOfStudents() == sizeBefore);
}

TEST_CASE("Search by SurName in empty database", "[Database][Search][SurName]") {
    //given
    Database db{};
    //when
    auto result = db.searchBySurName(nonExistSurName);
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search by SurName that not exist", "[Database][Search][SurName]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchBySurName(nonExistSurName);
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search by SurName that exist once", "[Database][Search][SurName]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchBySurName(onceExistSurName);
    //then
    REQUIRE(!result.empty());
    //REQUIRE(result.size() == 1);
    //REQUIRE(result[0].getSurName() == studentSurName[0]);
}

TEST_CASE("Search by SurName that exist twice", "[Database][Search][SurName]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
    }
    //when
    auto result = db.searchBySurName(twiceExistSurName);
    //then
    REQUIRE(!result.empty());
    //REQUIRE(result.size() == 2);
    //REQUIRE(result[0].getSurName() == result[1].getSurName());
}

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

TEST_CASE("Search by PESEL student added exist twice", "[Database][Search][PESEL]") {
    //given
    Database db{};
    for (const auto& student : students) {
        db.addStudent(student);
        db.addStudent(student);
    }
    //when
    auto result = db.searchByPesel(secondExistPesel);
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 1);
    REQUIRE(result[0].getFirstName() == studentName[2]);
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
