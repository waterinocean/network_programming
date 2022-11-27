cmake_minimum_required(VERSION 3.0.0)
project(echo_server VERSION 0.1.0)

add_executable(echo_server echo_server.cpp)
target_link_libraries(echo_server ws2_32)
set_target_properties(echo_server
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/
)