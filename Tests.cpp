#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include <array>
#include <vector>
#include "Database.hpp"
#include "CheckPesel.hpp"

constexpr auto nonExistPesel = "90000000000";
constexpr auto ExistPesel_1 = "00000000000";
constexpr auto ExistPesel_2 = "01234567890";
constexpr auto ExistPesel_3 = "11111111111";

constexpr std::array peselOrder = {
    ExistPesel_1,
    ExistPesel_2,
    ExistPesel_3
};

constexpr auto otherStudentName = "otherStudentName";
constexpr auto nonExistSurName = "nonExistSurName";
constexpr auto onceExistSurName = "onceExistSurName";
constexpr auto twiceExistSurName = "twiceExistSurName";
constexpr auto otherStudentSurName = "otherStudentSurName";

constexpr auto notImportantText = "notImportant";
constexpr auto notImportantValue = 0;
constexpr auto notImportantGender = Gender::Undefined;

constexpr std::array studentName = {"Student A", 
                                    "Student A", 
                                    "Student CCCCCCCCCCCCCCCCCCCCCCCCCCCCC"};

constexpr std::array studentSurName = {onceExistSurName, 
                                    twiceExistSurName, 
                                    twiceExistSurName};
constexpr std::array studentIndex = {0, 
                                    1, 
                                    2};

PersonType otherStudent = std::make_shared<Student>(otherStudentName, 
                                            otherStudentSurName, 
                                            notImportantText, 
                                            notImportantText, 
                                            notImportantText, 
                                            notImportantValue, 
                                            nonExistPesel, 
                                            notImportantGender);

const auto studentsNumber = 3;
const std::array<PersonType, studentsNumber> students = {
    std::make_shared<Student>(studentName[0], 
                            studentSurName[0], 
                            notImportantText, 
                            notImportantText, 
                            notImportantText, 
                            studentIndex[0], 
                            ExistPesel_1, 
                            notImportantGender),
    std::make_shared<Student>(studentName[1], 
                            studentSurName[1], 
                            notImportantText,
                            notImportantText, 
                            notImportantText, 
                            studentIndex[1], 
                            ExistPesel_2, 
                            notImportantGender),
    std::make_shared<Student>(studentName[2], 
                            studentSurName[2], 
                            notImportantText, 
                            notImportantText, 
                            notImportantText, 
                            studentIndex[2], 
                            ExistPesel_3, 
                            notImportantGender)};

void fillDatabase(Database& db) {
    for (const auto& student : students) {
        auto result = db.addPerson(student);
        if (!result) {
            std::cout << "fillDatabase fail\n";
        }
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
    auto isSuccess = db.addPerson(students[0]);
    //then
    REQUIRE(isSuccess);
    REQUIRE(db.getNumberOfPersons() == 1);
}

TEST_CASE("Add new Student to existing database", "[Database][Add]") {
    //given
    Database db{};
    fillDatabase(db);
    auto sizeBefore = db.getNumberOfPersons();
    //when
    auto isSuccess = db.addPerson(otherStudent);
    //then
    REQUIRE(isSuccess);
    REQUIRE(db.getNumberOfPersons() == sizeBefore + 1);
}

TEST_CASE("Skipp adding existing student in database", "[Database][Add]") {
    //given
    Database db{};
    fillDatabase(db);
    auto sizeBefore = db.getNumberOfPersons();
    //when
    auto isSuccess = db.addPerson(students[0]);
    //then
    REQUIRE(!isSuccess);
    REQUIRE(db.getNumberOfPersons() == sizeBefore);
}

TEST_CASE("Sort database by surname in ascending order", "[Database][Sort][SurName]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortBySurName(std::less<>{});
    //then
    const auto& students = db.getPersons();
    REQUIRE(students[0]->getSurName() == onceExistSurName);
    REQUIRE(students[1]->getSurName() == twiceExistSurName);
    REQUIRE(students[2]->getSurName() == twiceExistSurName);
}

TEST_CASE("Sort database by surname in descending order", "[Database][Sort][SurName]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortBySurName(std::greater{});
    //then
    const auto& students = db.getPersons();
    REQUIRE(students[0]->getSurName() == twiceExistSurName);
    REQUIRE(students[1]->getSurName() == twiceExistSurName);
    REQUIRE(students[2]->getSurName() == onceExistSurName);
}

TEST_CASE("Sort database by PESEL in ascending order", "[Database][Sort][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortByPesel(std::less<>{});
    //then
    const auto& students = db.getPersons();
    REQUIRE(students[0]->getPesel() == peselOrder[0]);
    REQUIRE(students[1]->getPesel() == peselOrder[1]);
    REQUIRE(students[2]->getPesel() == peselOrder[2]);
}

TEST_CASE("Sort database by PESEL in descending order", "[Database][Sort][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.sortByPesel(std::greater{});
    //then
    const auto& students = db.getPersons();
    REQUIRE(students[0]->getPesel() == peselOrder[2]);
    REQUIRE(students[1]->getPesel() == peselOrder[1]);
    REQUIRE(students[2]->getPesel() == peselOrder[0]);
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
    auto result = db.searchByPesel(ExistPesel_1);
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 1);
    REQUIRE(result[0]->getFirstName() == studentName[1]);
}

TEST_CASE("Search by PESEL student added exist twice", "[Database][Search][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
    fillDatabase(db);
    //when
    auto result = db.searchByPesel(ExistPesel_3);
    //then
    REQUIRE(!result.empty());
    REQUIRE(result.size() == 1);
    REQUIRE(result[0]->getFirstName() == studentName[2]);
}

TEST_CASE("Delete by PESEL in empty database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    //when
    db.deleteByPesel(nonExistPesel);
    //then
    REQUIRE(db.getNumberOfPersons() == 0);
}

TEST_CASE("Delete by nonexist PESEL in database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.deleteByPesel(nonExistPesel);
    //then
    REQUIRE(db.getNumberOfPersons() == students.size());
}

TEST_CASE("Delete by PESEL exist once in database", "[Database][Delete][PESEL]") {
    //given
    Database db{};
    fillDatabase(db);
    //when
    db.deleteByPesel(ExistPesel_1);
    //then
    REQUIRE(db.getNumberOfPersons() == students.size() - 1);
}
