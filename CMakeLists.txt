cmake_minimum_required(VERSION 2.6)
project(sdl-rendering)

set(SDL2_HOME C:/mingw-addons/SDL2-2.0.9/i686-w64-mingw32)
set(SDL2_INCLUDE_DIR ${SDL2_HOME}/include)
set(SDL2_LIBRARY ${SDL2_HOME}/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY})
add_definitions(-DSDL_MAIN_HANDLED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

file(GLOB SRCS *.cpp)
add_executable(sdl-rendering ${SRCS})
target_link_libraries(sdl-rendering SDL2)
