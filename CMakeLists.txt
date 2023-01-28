cmake_minimum_required(VERSION 3.0.0)
project(Continuity
    VERSION 1.0
    DESCRIPTION "A Simple C++ Chess Engine"
    LANGUAGES CXX)
add_executable(Continuity
    src/Board.cpp
    src/Board.h
    src/Continuity.cpp
    src/Continuity.h)
target_compile_features(Continuity PRIVATE cxx_std_20)
target_compile_options(Continuity PRIVATE -Wall)
