#CMAKELISTS Colton Morley for Project 3 cs302.1001
cmake_minimum_required(VERSION 2.8.11)
project(proj3)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MY_SOURCES src/LeftLeaningRedBlack.cpp)

add_library(My_Sources ${MY_SOURCES})
add_executable(proj4 src/proj4.cpp)
target_link_libraries(proj4 My_Sources)
install(TARGETS proj4 My_Sources
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}build/devel/bin
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib
    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib/static)


install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
    FILES_MATCHING PATTERN "*h" PATTERN "*.hpp")