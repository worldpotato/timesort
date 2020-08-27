cmake_minimum_required (VERSION 3.5)

project(timesort-example)

add_compile_options(-lpthread -Wall -Werror)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(lib/timesort)

add_executable (timesort-example main.cpp)

target_link_libraries(timesort-example timesort)

add_custom_command(TARGET timesort-example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${PROJECT_SOURCE_DIR}/compile_commands.json
 )

 add_custom_command(TARGET timesort-example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/timesort-example
    ${PROJECT_SOURCE_DIR}/bin/timesort-example
 )
