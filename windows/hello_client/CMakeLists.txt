cmake_minimum_required(VERSION 3.0.0)
project(hello_client VERSION 0.1.0)

add_executable(hello_client hello_client.cpp)
target_link_libraries(hello_client ws2_32)
