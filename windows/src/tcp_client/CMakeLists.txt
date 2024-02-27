
set(tcp_client_src
tcp_client.cpp
)

add_library(tcp_client ${tcp_client_src})

target_include_directories(tcp_client
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(tcp_client PUBLIC
                      compile_config ws2_32)
