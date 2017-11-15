cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g ")

file( GLOB SRCS *.cpp)

add_executable( sim01 ${SRCS})
