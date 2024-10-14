cmake_minimum_required(VERSION 3.29)
project(Personal)

set(CMAKE_CXX_STANDARD 20)

add_executable(Personal Quad.cpp
        kinismatic.cpp)
add_executable(Personal_word word.cpp)
add_executable(kinesmatic
        kinismatic.cpp
        combine.h
        kinsmatic_match.cpp)
