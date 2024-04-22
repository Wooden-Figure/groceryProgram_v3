cmake_minimum_required(VERSION 3.27)
project(groceryProgram_v3)

set(CMAKE_CXX_STANDARD 17)

add_executable(groceryProgram_v3 main.cpp
        FileHandler.cpp
        FileHandler.h
        UserInterface.cpp
        UserInterface.h)
