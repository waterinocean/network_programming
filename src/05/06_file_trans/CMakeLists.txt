cmake_minimum_required(VERSION 3.0.0)
project(network VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

add_subdirectory(client)
add_subdirectory(server)
