cmake_minimum_required(VERSION 3.14)

set(This Util)
project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Util.h
)

set(Sources
   Util.cpp
)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/input.txt
    DESTINATION ${CMAKE_BINARY_DIR}/test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/osfile.txt
    DESTINATION ${CMAKE_BINARY_DIR}/test)



add_library(${This} ${Sources} ${Headers})
add_subdirectory(test)


