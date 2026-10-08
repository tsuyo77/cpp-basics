cmake_minimum_required(VERSION 3.16)
project(day03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

foreach(t overload namespace_demo practice)
  add_executable(${t} ${t}.cpp)
  target_compile_options(${t} PRIVATE -Wall -Wextra)
endforeach()