cmake_minimum_required(VERSION 3.0.0)
project(university-db)

set(CMAKE_CXX_STANDARD 17)

set (SRC
    Student.cpp
    Database.cpp
    Menu.cpp
    Gender.cpp
    Worker.cpp
    Commands/Commands.cpp)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut Tests.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
