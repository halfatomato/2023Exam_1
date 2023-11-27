cmake_minimum_required(VERSION 3.26)
project(CppArrayList)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CppArrayList main.cpp
        int_array_list.h
        int_array_list.cpp)

add_subdirectory(Google_tests)