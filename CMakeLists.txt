cmake_minimum_required(VERSION 3.27)
project(FactoryTask)

set(CMAKE_CXX_STANDARD 17)

add_executable(FactoryTask main.cpp
        Transport.cpp
        Transport.h)
