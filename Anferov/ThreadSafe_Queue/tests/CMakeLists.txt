cmake_minimum_required(VERSION 3.4)

project(${TEST_PROJECT})

set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/QueueTests.cpp
    ${PROJECT_SOURCE_DIR}/test_main.cpp
    ${PROJECT_SOURCE_DIR}/tests.cpp
)

set(TEST_HEADERS
    ${PROJECT_SOURCE_DIR}/QueueTests.hpp
)

include_directories(
    ${INCLUDE_ROOT}
    ${PROJECT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} ${HEADERS} ${TEST_HEADERS} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} gtest)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
