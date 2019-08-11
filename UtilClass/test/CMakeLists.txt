cmake_minimum_required(VERSION 3.14)

set(This UtilTests)

set(Sources
    UtilTests.cpp
)

message("Check test binary path" ${CMAKE_BINARY_DIR}/test)

add_executable(${This} ${Sources})
target_include_directories(${This} PRIVATE ..)

target_link_libraries(${This} PUBLIC
    gtest_main
    Util
)

add_test(
    NAME ${This}
    COMMAND ${This}
)