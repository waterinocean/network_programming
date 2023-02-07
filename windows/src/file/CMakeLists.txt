set(file_worker_src
file_worker.cpp
file_worker_c.cpp
file_worker_cplus.cpp
file_worker_os.cpp
file_worker_factory.cpp)

add_library(file_worker ${file_worker_src})

target_include_directories(file_worker
PUBLIC
${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(file_worker PUBLIC
                      compile_config)
