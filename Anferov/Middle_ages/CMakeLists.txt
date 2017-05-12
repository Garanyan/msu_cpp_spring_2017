cmake_minimum_required(VERSION 3.4)

project(Anferov_Middle_ages)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include")

set(HEADERS
    ${INCLUDE_ROOT}/armor.hpp
    ${INCLUDE_ROOT}/armor_enum.h
    ${INCLUDE_ROOT}/armor_light.hpp
    ${INCLUDE_ROOT}/arsenal.hpp
    ${INCLUDE_ROOT}/character.hpp
    ${INCLUDE_ROOT}/storage.hpp
    ${INCLUDE_ROOT}/weapon.hpp
    ${INCLUDE_ROOT}/weapon_enum.h
    ${INCLUDE_ROOT}/weapon_light.hpp
    ${INCLUDE_ROOT}/army_factory.hpp
    ${INCLUDE_ROOT}/unit_factory.hpp
)

set(SHARED_SOURCES
    ${SRC_ROOT}/armor.cpp
    ${SRC_ROOT}/arsenal.cpp
    ${SRC_ROOT}/character.cpp
    ${SRC_ROOT}/storage.cpp
    ${SRC_ROOT}/weapon.cpp
    ${SRC_ROOT}/army_factory.cpp
    ${SRC_ROOT}/unit_factory.cpp
)

include_directories(
    ${INCLUDE_ROOT}
)

add_executable(${PROJECT_NAME}_multithread_game ${HEADERS} ${SRC_ROOT}/main.cpp
${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME}_multithread_game PRIVATE cxx_range_for)

add_executable(${PROJECT_NAME}_pattern_army ${HEADERS} ${SRC_ROOT}/pattern_army_main.cpp
${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME}_pattern_army PRIVATE cxx_range_for)

#----------- precompiled -----------
#set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
#cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
