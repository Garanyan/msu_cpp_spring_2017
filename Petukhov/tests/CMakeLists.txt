cmake_minimum_required(VERSION 3.4)

project(${TEST_PROJECT})

set(HEADERS
    ${HDR_ROOT}/t9translator.h)
set(SOURCES
    ${SRC_ROOT}/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
