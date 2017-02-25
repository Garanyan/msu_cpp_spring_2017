cmake_minimum_required(VERSION 3.4)

project(${TEST_PROJECT})

include_directories(../include/)

set(SOURCES
    main.cpp)

add_library(source_lib ../src/task.cpp)
target_compile_features(source_lib PRIVATE cxx_range_for)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} source_lib)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
