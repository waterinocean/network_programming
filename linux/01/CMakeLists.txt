project(01)
cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(hello_server hello_server.cpp)
add_executable(hello_client hello_client.cpp)
add_executable(os_copy os_copy.cpp)
add_executable(c_copy c_copy.cpp)
add_executable(cplus_copy cplus_copy.cpp)