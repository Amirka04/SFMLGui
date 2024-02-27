cmake_minimum_required(VERSION 3.5)

project(GUI)


add_subdirectory(Window)
add_subdirectory(Label)


add_executable(GUI main.cpp)

# link lib Window
target_link_libraries(GUI Window)

# link lib Label
target_link_libraries(GUI Label)
