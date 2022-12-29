find_package(Catch2 REQUIRED)


set(src_test
test_catch2_example.cpp
)

add_executable(test_app ${src_test})

target_link_libraries(test_app
PRIVATE
Catch2::Catch2WithMain)

set_target_properties(test_app
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/
)