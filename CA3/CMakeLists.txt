cmake_minimum_required(VERSION 3.8)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

project(FBL)
add_subdirectory(src bin)
