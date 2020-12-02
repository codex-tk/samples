cmake_minimum_required(VERSION 3.0.0)

project(hello_cpp VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (UNIX AND NOT APPLE)
add_definitions( -Wall -std=c++17 -o2 -g -ggdb -fconcepts -DSOCKLEN_T=socklen_t )
elseif(MSVC)
add_definitions( /std:c++latest )
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
message( "${SRCS}" )
add_executable(hello_cpp ${SRCS})