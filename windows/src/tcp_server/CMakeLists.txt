
set(tcp_server_src
tcp_server.cpp
)

add_library(tcp_server ${tcp_server_src})

target_include_directories(tcp_server
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(tcp_server PUBLIC
                      compile_config ws2_32)
