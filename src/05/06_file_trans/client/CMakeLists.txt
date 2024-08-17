set(client_src  ./client.cpp
)
add_executable(client ${client_src})
target_include_directories(client PRIVATE ./../../../../include/05/06_file_trans)
target_link_libraries(client PRIVATE ws2_32)
