cmake_minimum_required(VERSION 3.0.0)
project(university-db)

set(CMAKE_CXX_STANDARD 17)

set (SRC
    Student.cpp
    Database.cpp
    Menu.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SRC})
add_executable(${PROJECT_NAME}-ut Tests.cpp ${SRC})
