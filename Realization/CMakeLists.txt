cmake_minimum_required(VERSION 3.5)

project(GUI)

add_subdirectory(Window)



add_executable(GUI main.cpp)

target_link_libraries(GUI Window)