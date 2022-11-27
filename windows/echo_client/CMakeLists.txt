cmake_minimum_required(VERSION 3.0.0)
project(echo_client VERSION 0.1.0)

add_executable(echo_client echo_client.cpp)
target_link_libraries(echo_client ws2_32)
set_target_properties(echo_client
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/
)
