cmake_minimum_required(VERSION 3.16)
project(day01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello main.cpp)
target_compile_options(hello PRIVATE -Wall -Wextra)