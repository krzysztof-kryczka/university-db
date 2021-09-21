cmake_minimum_required(VERSION 3.0.0)
project(university-db)

set(CMAKE_CXX_STANDARD 17)

set(COMMAND
    Commands/AddStudent.cpp
    Commands/DeleteByIndexNumber.cpp
    Commands/DeleteByPesel.cpp
    Commands/EndGame.cpp
    Commands/GenerateStudent.cpp
    Commands/GenerateWorker.cpp
    Commands/LoadRecords.cpp
    Commands/PrintAllRecords.cpp
    Commands/PrintMenu.cpp
    Commands/SaveRecords.cpp
    Commands/SearchByPesel.cpp
    Commands/SearchOption.cpp
    Commands/SortByIncome.cpp
    Commands/SortByPesel.cpp
    Commands/SortBySurname.cpp
    Commands/ValidatePeselNumber.cpp
    Commands/ChangeIncome.cpp)

set(SRC
    Person.cpp
    Student.cpp
    Database.cpp
    Menu.cpp
    Gender.cpp
    Worker.cpp
    CheckPesel.cpp)

add_library(${PROJECT_NAME}-lib STATIC ${SRC} ${COMMAND})

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut Tests.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
