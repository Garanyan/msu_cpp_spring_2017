cmake_minimum_required(VERSION 3.4)

project(war)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(SHARED_SOURCES
    ${SRC_ROOT}/armor.cpp
    ${SRC_ROOT}/arsenal.cpp
    ${SRC_ROOT}/unit.cpp
    ${SRC_ROOT}/weapon.cpp
    )

set(SOURCES
    ${SRC_ROOT}/game.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
