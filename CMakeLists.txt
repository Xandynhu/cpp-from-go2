cmake_minimum_required(VERSION 3.20...3.26)
project(cpp-from-go2)

# C++20
set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_BUILD_TYPE Release)

# Set current working directory
set(CWD ${CMAKE_CURRENT_SOURCE_DIR})

# Include header files
include_directories(${CWD}/src)

# Set source files
set(SRC_FILES
    ${CWD}/src/string_collector_impl.cpp
    ${CWD}/src/string_collector.cpp
)

# Build static library
add_library(string_collector_static STATIC ${SRC_FILES})
target_include_directories(string_collector_static PUBLIC src)
