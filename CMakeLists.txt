cmake_minimum_required (VERSION 3.22.1)
project(DSA)


add_executable(${CMAKE_PROJECT_NAME} main.cpp)

add_subdirectory(src)

include_directories(
    include 
    src 
)
target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
    src/Queue.cpp 
    include/List.h
    include/Stack.h
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)