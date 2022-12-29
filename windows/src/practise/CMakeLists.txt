
add_executable(op_server op_server.cpp)
add_executable(op_client op_client.cpp)
add_executable(hello_server hello_server.cpp)
add_executable(hello_client hello_client.cpp)
add_executable(echo_server echo_server.cpp)
add_executable(echo_client echo_client.cpp)

target_link_libraries(op_server 
PUBLIC
ws2_32)
target_link_libraries(op_client
PUBLIC
ws2_32)
target_link_libraries(hello_server
PUBLIC
ws2_32)
target_link_libraries(hello_client
PUBLIC
ws2_32)
target_link_libraries(echo_server 
PUBLIC
ws2_32)
target_link_libraries(echo_client
PUBLIC
ws2_32)
set_target_properties(op_server op_client hello_server hello_client
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/
)