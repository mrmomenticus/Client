cmake_minimum_required(VERSION 3.15)
project(Client_ServerDaemon)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

SET(CMAKE_CXX_FLAGS -pthread)
add_executable(Client_ServerDaemon
        main.cpp Client.cpp Client.h)
