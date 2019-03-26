cmake_minimum_required(VERSION 2.6)
project(sdl-rendering)
file(GLOB SRCS *.cpp)
add_executable(sdl-rendering ${SRCS})