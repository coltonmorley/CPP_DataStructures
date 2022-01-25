#CMAKELISTS Colton Morley for Project 5 cs202.1103
cmake_minimum_required(VERSION 2.8.11)
project(proj7)
include_directories(include)
set(MY_SOURCES src/MyString.cpp)
add_library(My_Sources ${MY_SOURCES})
add_executable(proj7 src/proj7.cpp)
target_link_libraries(proj7 My_Sources)
install(TARGETS proj7 My_Sources
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}build/devel/bin
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib
    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib/static)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
    FILES_MATCHING PATTERN "*h" PATTERN "*.hpp")