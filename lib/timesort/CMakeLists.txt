######################################################################
# @author      : worldpotato
# @file        : CMakeLists
# @created     : Tuesday Aug 25, 2020 08:23:38 CEST
######################################################################

cmake_minimum_required(VERSION 3.18)
project(timesort)

set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -Wall -Werror -std=c++17")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(timesort SHARED
    src/timesort.cpp
)

# add_executable(timesort2 src/timesort.cpp)

target_include_directories(timesort PUBLIC include)

