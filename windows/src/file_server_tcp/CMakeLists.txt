add_executable(file_server_tcp main.cpp ${file_worker_src})

set_target_properties(file_server_tcp
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(file_server_tcp
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(file_server_tcp
PRIVATE
file_worker)