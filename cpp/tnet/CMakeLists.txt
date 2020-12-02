cmake_minimum_required(VERSION 3.0.0)

project(tnet VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(MSVC)
  add_definitions( /std:c++latest )
elseif(APPLE)
  add_definitions( -Wall -o2 -g -ggdb -DSOCKLEN_T=socklen_t -Wc++17-extensions -stdlib=libc++ )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
else()
  add_definitions( -Wall -std=c++17 -o2 -g -ggdb -fconcepts -DSOCKLEN_T=socklen_t )
endif()

add_subdirectory(tnet)
add_subdirectory(tests)