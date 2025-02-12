cmake_minimum_required(VERSION 3.11)
project(FibonacciTask CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)
include_directories(${gtest_SOURCE_DIR}/include)

add_executable(fibonacci_app
        src/main.cpp
        src/FibonacciGenerator.h
        src/FibonacciGenerator.tpp
)

enable_testing()

add_executable(runTests
        test/FibonacciGeneratorTest.cpp
        src/FibonacciGenerator.h
        src/FibonacciGenerator.tpp
)

target_link_libraries(runTests gtest gtest_main pthread)

target_include_directories(runTests PRIVATE ${googletest_SOURCE_DIR}/googletest/include)


add_test(NAME FibonacciTests COMMAND runTests)
add_custom_command(TARGET fibonacci_app
        POST_BUILD
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        COMMENT "Running tests after building the application..."
)