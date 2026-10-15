cmake_minimum_required(VERSION 3.16)
project(day06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(week_task week_task.cpp)
target_compile_options(week_task PRIVATE -Wall -Wextra)