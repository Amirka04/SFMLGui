cmake_minimum_required(VERSION 3.5)

add_library(Window Window.cpp Window.h)

target_link_libraries(Window PUBLIC sfml-system sfml-window sfml-graphics)

