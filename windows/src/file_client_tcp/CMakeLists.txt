add_executable(file_client_tcp main.cpp)

set_target_properties(file_client_tcp
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(file_client_tcp
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(file_client_tcp
                      PRIVATE
                        file_worker
                        tcp_client)

target_link_libraries(file_client_tcp PUBLIC
                      compile_config)
