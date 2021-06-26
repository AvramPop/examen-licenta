cmake_minimum_required(VERSION 3.19)
project(try)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(try
        Person.cpp Person.h main.cpp)
