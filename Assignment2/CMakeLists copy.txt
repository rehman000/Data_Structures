cmake_minimum_required(VERSION 3.12)
project(Assignment2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment2
                main.cpp
                sequence1.cpp
                sequence1.h)

add_executable(exam
        sequence_exam.cpp
        sequence1.cpp
        sequence1.h)