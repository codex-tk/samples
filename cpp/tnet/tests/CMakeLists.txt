project(tests)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../tnet/include)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )

add_executable(tests ${SRCS})


target_link_libraries(tests tnet)
if(WIN32)
    target_link_libraries(tests ws2_32)
else()
    target_link_libraries(tests dl)
endif()

enable_testing()
add_test(tests tests)
add_custom_command(TARGET tests POST_BUILD COMMAND ctest -C $<CONFIGURATION> --verbose --output-on-failure )