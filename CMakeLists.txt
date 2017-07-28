cmake_minimum_required(VERSION 3.8)
project(cpp-tutorial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES demo.cpp demo.h demo.cpp demo.h)
add_executable(cpp-tutorial ${SOURCE_FILES} demo.cpp demo.h)