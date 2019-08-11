cmake_minimum_required(VERSION 2.6)
project(sdl-rendering)

set(SDL2_DIR C:/mingw-addons/SDL2-2.0.9/i686-w64-mingw32)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}/..)
add_definitions(-DSDL_MAIN_HANDLED)

file(GLOB SRCS *.cpp)

add_executable(sdl-rendering ${SRCS})
target_link_libraries(sdl-rendering ${SDL2_LIBRARIES})