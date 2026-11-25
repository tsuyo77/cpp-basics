cmake_minimum_required(VERSION 3.16)
project(day17 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

foreach(t file_io exceptions practice)
  add_executable(${t} ${t}.cpp)
  target_compile_options(${t} PRIVATE -Wall -Wextra)
endforeach()