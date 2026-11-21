cmake_minimum_required(VERSION 3.16)
project(day13 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

foreach(t raii_basic smart_ptr shared_demo practice)
  add_executable(${t} ${t}.cpp)
  target_compile_options(${t} PRIVATE -Wall -Wextra)
endforeach()