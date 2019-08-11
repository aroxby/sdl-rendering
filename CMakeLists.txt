cmake_minimum_required(VERSION 2.6)
project(sdl-rendering)

set(SDL2_DIR $ENV{SDL2_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}/..)
add_definitions(-DSDL_MAIN_HANDLED)

file(GLOB SRCS *.cpp)

add_executable(sdl-rendering ${SRCS})
target_link_libraries(sdl-rendering ${SDL2_LIBRARIES})