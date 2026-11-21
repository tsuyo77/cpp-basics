cmake_minimum_required(VERSION 3.16)

project(cpp_basics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Day 12 教材
add_executable(lesson lesson.cpp)

# Day 12 練習問題
add_executable(practice practice.cpp)