cmake_minimum_required(VERSION 3.0.0)
project(university-db)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp Student.cpp Database.cpp Menu.cpp Gender.cpp)
add_executable(${PROJECT_NAME}-ut Tests.cpp Student.cpp Database.cpp Menu.cpp Gender.cpp)
