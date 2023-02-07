cmake_minimum_required(VERSION 3.0.0)
project(network_programming VERSION 0.1.0)

add_library(compile_config INTERFACE)
target_compile_features(compile_config INTERFACE
                        cxx_std_11)
target_compile_options(compile_config INTERFACE
                       -Wall -Wextra -Wunused)


if (WIN32)
    add_subdirectory(windows)
elseif(LINUX)
    add_subdirectory(linux)
endif()
