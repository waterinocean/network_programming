cmake_minimum_required(VERSION 3.0.0)
project(op_client VERSION 0.1.0)

add_executable(op_client op_client.cpp)
target_link_libraries(op_client ws2_32)
