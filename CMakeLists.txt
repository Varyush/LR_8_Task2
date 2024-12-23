cmake_minimum_required(VERSION 3.27)
project(Task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task2 main.cpp
        func.h
        input.cpp
        read.cpp
        add.cpp
        delete.cpp
        change.cpp
        menu.cpp)