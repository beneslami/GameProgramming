cmake_minimum_required(VERSION 3.17)
project(GameProgramming)

set(CMAKE_CXX_STANDARD 14)

include_directories("Header Files")

add_executable(GameProgramming
        "src/game.h"
        "src/game.cpp"
        "src/main.cpp")
