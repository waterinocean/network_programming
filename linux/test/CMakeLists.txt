project(test)
cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(fork_process fork_process.cpp)