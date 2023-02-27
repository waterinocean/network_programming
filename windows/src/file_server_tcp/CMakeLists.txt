add_executable(file_server_tcp main.cpp file_server_tcp.cpp)

set_target_properties(file_server_tcp
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(file_server_tcp
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(file_server_tcp
                      PRIVATE
                        file_worker
                        tcp_server)

target_link_libraries(file_server_tcp PUBLIC
                      compile_config)
