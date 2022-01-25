#CMAKELISTS Colton Morley for Project 1 cs302.1001
cmake_minimum_required(VERSION 2.8.11)
project(proj1)
include_directories(include)

set (CMAKE_CXX_STANDARD 11)

add_executable(stackTest test6.cpp)

add_executable(postfix postfix.cpp)

add_executable(delimiters delimiters.cpp)


install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
    FILES_MATCHING PATTERN "*h" PATTERN "*.hpp")