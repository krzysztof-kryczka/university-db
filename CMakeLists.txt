cmake_minimum_required(VERSION 3.0.0)
project(university-db)

set(CMAKE_CXX_STANDARD 20)

add_executable(university-db main.cpp Student.cpp Database.cpp)