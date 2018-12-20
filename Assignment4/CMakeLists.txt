cmake_minimum_required(VERSION 3.12)
project(Assignment3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4
                node1.cpp
                sequence3.cpp
                sequence3_exam.cpp
                sequence3.h
                node1.h)


add_executable(Exam_3_part_1
                sequence3.cpp
                sequence3_test.cpp
                sequence3.h
                node1.h
                node1.cpp)

add_executable(Main.exe
                sequence3.cpp
                main.cpp
                node1.h
                node1.cpp
                sequence3.h)