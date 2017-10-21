cmake_minimum_required(VERSION 3.8)
project(Salty)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)

set(CMAKE_CXX_FLAGS "-lSDL2")

add_executable(Salty ${SOURCE_FILES})
target_link_libraries(Salty ${SDL2_LIBRARY})