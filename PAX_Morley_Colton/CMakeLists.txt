#CMAKELISTS Colton Morley for Project X cs202.1103
cmake_minimum_required(VERSION 2.8.11)
project(projX)
include_directories(include)
set(MY_SOURCES src/DataType.cpp
        src/SmartPtr.cpp)
add_library(My_Sources ${MY_SOURCES})
add_executable(projX src/projX.cpp)
target_link_libraries(projX My_Sources)
install(TARGETS projX My_Sources
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}build/devel/bin
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib
    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}build/devel/lib/static)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
    FILES_MATCHING PATTERN "*h" PATTERN "*.hpp")