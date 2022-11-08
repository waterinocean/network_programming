cmake_minimum_required(VERSION 3.0.0)
project(op_server VERSION 0.1.0)

add_executable(op_server op_server.cpp)
target_link_libraries(op_server ws2_32)
