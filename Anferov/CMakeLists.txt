cmake_minimum_required(VERSION 3.4)

project(Anferov)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(HEADERS
    ${SRC_ROOT}/armor_enum.h
    ${SRC_ROOT}/armor_light.hpp
    ${SRC_ROOT}/armor.hpp
    ${SRC_ROOT}/arsenal.hpp
    ${SRC_ROOT}/character.hpp
    ${SRC_ROOT}/storage.hpp
    ${SRC_ROOT}/weapon_enum.h
    ${SRC_ROOT}/weapon_light.hpp
    ${SRC_ROOT}/weapon.hpp
)

set(SOURCES
    ${SRC_ROOT}/armor.cpp
    ${SRC_ROOT}/arsenal.cpp
    ${SRC_ROOT}/character.cpp
    ${SRC_ROOT}/storage.cpp
    ${SRC_ROOT}/weapon.cpp

    ${SRC_ROOT}/main.cpp
)

#set(SHARED_SOURCES
#    ${SRC_ROOT}/T9_translator.cpp
#)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

#add_subdirectory(tests)
add_subdirectory(Task1_T9)

#enable_testing()
