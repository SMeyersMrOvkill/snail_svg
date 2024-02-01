cmake_minimum_required(VERSION 3.10)
project(snail_svg)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(ssvg)

add_subdirectory(viewer)