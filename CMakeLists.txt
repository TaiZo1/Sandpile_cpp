cmake_minimum_required(VERSION 3.15)
project(Sandpile_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sandpile_test
    src/sandpile.cpp
    test/test_sandpile.cpp
)
target_include_directories(sandpile_test PRIVATE include)
