cmake_minimum_required(VERSION 3.5)

add_library(Button button.h button.cpp)

target_include_directories(Button PUBLIC "../Label")

target_link_libraries(Button PRIVATE Label)

