cmake_minimum_required(VERSION 3.0.0)
project(network_programming VERSION 0.1.0)

if (WIN32)
    add_subdirectory(windows)
elseif(LINUX)
    add_subdirectory(linux)
endif()
