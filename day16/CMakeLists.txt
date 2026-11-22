cmake_minimum_required(VERSION 3.16)
project(day16 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ライブラリ:vec2.cpp をまとめた部品
add_library(geometry vec2.cpp)
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(geometry PRIVATE -Wall -Wextra)

# 実行ファイル1
add_executable(app main.cpp)
target_link_libraries(app PRIVATE geometry)
target_compile_options(app PRIVATE -Wall -Wextra)

# 実行ファイル2
add_executable(tool tool.cpp)
target_link_libraries(tool PRIVATE geometry)
target_compile_options(tool PRIVATE -Wall -Wextra)

add_executable(tmpl_test tmpl_test.cpp)

add_library(mathutil mathutil.cpp)
target_include_directories(mathutil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(mathutil PRIVATE -Wall -Wextra)

add_executable(practice practice.cpp)
target_link_libraries(practice PRIVATE geometry mathutil)
target_compile_options(practice PRIVATE -Wall -Wextra)