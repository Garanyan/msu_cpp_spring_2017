cmake_minimum_required(VERSION 2.8)

project(monakov)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(HEADERS
    ${SRC_ROOT}/t9.h
    )

set(SOURCES
    ${SRC_ROOT}/main.cpp
    )

set(SHARED_SOURCES
    ${SRC_ROOT}/t9.cpp
    )
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})
include(cotire)
################################
# GTest
################################
ADD_SUBDIRECTORY (dependencies/gtest-1.8.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})
#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
enable_testing()
