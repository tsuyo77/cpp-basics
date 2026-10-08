cmake_minimum_required(VERSION 3.16)
project(day02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ref_ptr ref_ptr.cpp)
add_executable(const_auto const_auto.cpp)
add_executable(practice practice.cpp)

foreach(t ref_ptr const_auto practice)
  target_compile_options(${t} PRIVATE -Wall -Wextra)
endforeach()