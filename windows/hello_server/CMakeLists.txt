cmake_minimum_required(VERSION 3.0.0)
project(hello_server VERSION 0.1.0)

add_executable(hello_server hello_server.cpp)
target_link_libraries(hello_server ws2_32)
