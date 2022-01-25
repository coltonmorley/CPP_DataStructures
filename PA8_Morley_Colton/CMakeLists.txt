#CMAKELISTS Colton Morley for Project X cs202.1103
cmake_minimum_required(VERSION 2.8.11)
project(proj8)
include_directories(include)
set(MY_SOURCES src/DataType.cpp
        src/NodeList.cpp
        src/ArrayList.cpp)
add_library(My_Sources ${MY_SOURCES})
add_executable(proj8 src/proj8.cpp)
target_link_libraries(proj8 My_Sources)
install(TARGETS proj8 My_Sources
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}build/devel/bin
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib
    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib/static)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
    FILES_MATCHING PATTERN "*h" PATTERN "*.hpp")