cmake_minimum_required(VERSION 3.8)
project(cpp-tutorial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(cpp-tutorial ${SOURCE_FILES} main.cpp)