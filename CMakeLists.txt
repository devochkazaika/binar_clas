cmake_minimum_required(VERSION 2.8)
project(reg)

add_subdirectory(src)
add_executable(main src/main.cpp)

target_link_libraries(main sfml-system sfml-window sfml-graphics sfml-audio)