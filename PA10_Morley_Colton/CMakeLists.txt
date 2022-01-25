#CMAKELISTS Colton Morley for Project X cs202.1103
cmake_minimum_required(VERSION 2.8.11)
project(proj10)
include_directories(include)

add_executable(proj10 src/proj10.cpp)


install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
    FILES_MATCHING PATTERN "*h" PATTERN "*.hpp")