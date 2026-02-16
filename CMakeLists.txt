cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp candle.cpp test_candle.cpp
        test_candle.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})