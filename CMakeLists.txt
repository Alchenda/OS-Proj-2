cmake_minimum_required(VERSION 3.21)
project (OS-Proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(OS-Proj-2 main.cpp)
target_link_libraries(OS-Proj-2 -pthread)