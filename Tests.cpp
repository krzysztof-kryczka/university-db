#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include <array>
#include <vector>
#include "Database.hpp"

constexpr auto nonExistPesel = "90000000000";
constexpr auto anotherExistPesel = "01234567890";
constexpr auto onceExistPesel = "00000000000";
constexpr auto secondExistPesel = "11111111111";

constexpr std::array studentName = {
    "A", "B", "CCCCCCCCCCCCCCCCCCCCCCCCCCCCC"};

constexpr auto otherStudentName = "Edward";

constexpr auto nonExistSurName = "Kazmierczak";
constexpr auto onceExistSurName = "Nowak";
constexpr auto twiceExistSurName = "Kowalski";
constexpr auto otherStudentSurName = "Bono";

constexpr std::array studentSurName = {
    onceExistSurName, twiceExistSurName, twiceExistSurName};

Student otherStudent(otherStudentName, otherStudentSurName, "A", "A", "A", 0, nonExistPesel, Gender::Undefined);

const std::vector students = {
    Student(studentName[0], studentSurName[0], "A", "A", "A", 0, anotherExistPesel, Gender::Undefined),
    Student(studentName[1], studentSurName[1], "A", "A", "A", 1, onceExistPesel, Gender::Undefined),
    Student(studentName[2], studentSurName[2], "A", "A", "A", 2, secondExistPesel, Gender::Undefined)};

constexpr auto baseStudentsSize = 3;

void fillDatabase(Database& db){
    for (const auto& student : students) {
        db.addStudent(student);
    }
}

TEST_CASE("Validate wrong PESEL", "[PESEL]") {
    //given
    auto wrongPesel = "12345678901";
    //when
    auto result = checkPesel(wrongPesel);
    //then
    REQUIRE(result == false);
}

TEST_CASE("Validate good PESEL", "[PESEL]") {
    //given
    auto goodPesel = "24090833676";
    //when
    auto result = checkPesel(goodPesel);
    //then
    REQUIRE(result == true);
}

TEST_CASE("Add Student to empty database", "[Database][Add]") {
    //given
    Database db{};
    //when
    auto isSuccess = db.addStudent(students[0]);
    //then
    REQUIRE(isSuccess);
    REQUIRE(db.getNumberOfStudents() == 1);
}

TEST_CASE("Add new Student to existing database", "[Database][Add]") {
    //given
    Database db{};
    fillDatabase(db);
    auto sizeBefore = db.getNumberOfStudents();
    //when
    auto isSuccess = db.addStudent(otherStudent);
    //then
    REQUIRE(isSuccess);
    REQUIRE(db.getNumberOfStudents() == sizeBefore + 1);
}

TEST_CASE("Skipp adding existing student in database", "[Database][Add]") {
    //given
    Database db{};
    fillDatabase(db);
    auto sizeBefore = db.getNumberOfStudents();
    //when
    auto isSuccess = db.addStudent(students[0]);
    //then
    REQUIRE(!isSuccess);
    REQUIRE(db.getNumberOfStudents() == sizeBefore);
}

TEST_CASE("Sort database by surname in ascending order","[Database][Sort][SurName]"){
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortBySurName();
    //then
    const auto& students = db.getStudents();
    REQUIRE(students[0].getSurName() == "Kowalski");
    REQUIRE(students[1].getSurName() == "Kowalski");
    REQUIRE(students[2].getSurName() == "Nowak");
}

TEST_CASE("Sort database by surname in descending order","[Database][Sort][SurName]"){
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortBySurName(std::greater{});
    //then
    const auto& students = db.getStudents();
    REQUIRE(students[0].getSurName() == "Nowak");
    REQUIRE(students[1].getSurName() == "Kowalski");
    REQUIRE(students[2].getSurName() == "Kowalski");
}

TEST_CASE("Sort database by PESEL in ascending order","[Database][Sort][PESEL]"){
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortByPesel();
    //then
    const auto& students = db.getStudents();
    REQUIRE(students[0].getPesel() == "00000000000");
    REQUIRE(students[1].getPesel() == "01234567890");
    REQUIRE(students[2].getPesel() == "11111111111");
}

TEST_CASE("Sort database by PESEL in descending order","[Database][Sort][PESEL]"){
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortByPesel(std::greater{});
    //then
    const auto& students = db.getStudents();
    REQUIRE(students[0].getPesel() == "11111111111");
    REQUIRE(students[1].getPesel() == "01234567890");
    REQUIRE(students[2].getPesel() == "00000000000");
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
    fillDatabase(db);
    //when
    auto result = db.searchBySurName(nonExistSurName);
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search by SurName that exist once", "[Database][Search][SurName]") {
    //given
    Database db{};
    fillDatabase(db);
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
    fillDatabase(db);
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
    fillDatabase(db);
    //when
    auto result = db.searchByPesel(nonExistPesel);
    //then
    REQUIRE(result.empty());
}

TEST_CASE("Search by PESEL what exist once", "[Database][Search][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
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
    fillDatabase(db);
    fillDatabase(db);
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
    fillDatabase(db);
    //when
    db.deleteByPesel(nonExistPesel);
    //then
    REQUIRE(db.getNumberOfStudents() == students.size());
}

TEST_CASE("Delete by PESEL exist once in database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.deleteByPesel(onceExistPesel);
    //then
    REQUIRE(db.getNumberOfStudents() == students.size() - 1);
}
