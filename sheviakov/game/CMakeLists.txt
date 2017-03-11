cmake_minimum_required(VERSION 3.4)

project(game)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(HEADERS
    ${SRC_ROOT}/game.h
    ${SRC_ROOT}/weapon.h
    ${SRC_ROOT}/weapons/hammer.h
    ${SRC_ROOT}/weapons/sword.h
    ${SRC_ROOT}/weapons/shovel.h
    ${SRC_ROOT}/weapons/bow.h
    ${SRC_ROOT}/armor.h
    ${SRC_ROOT}/armors/chainarmor.h
    ${SRC_ROOT}/armors/courselet.h
    ${SRC_ROOT}/character.h
    ${SRC_ROOT}/characters/peasant.h
    ${SRC_ROOT}/characters/archer.h
    ${SRC_ROOT}/characters/knight.h
    )

set(SOURCES
    ${SRC_ROOT}/main.cpp
    )

set(SHARED_SOURCES
    ${SRC_ROOT}/weapon.cpp
    ${SRC_ROOT}/weapons/hammer.cpp
    ${SRC_ROOT}/weapons/sword.cpp
    ${SRC_ROOT}/weapons/shovel.cpp
    ${SRC_ROOT}/weapons/bow.cpp
    ${SRC_ROOT}/armor.cpp
    ${SRC_ROOT}/armors/chainarmor.cpp
    ${SRC_ROOT}/armors/courselet.cpp
    ${SRC_ROOT}/character.cpp
    ${SRC_ROOT}/characters/peasant.cpp
    ${SRC_ROOT}/characters/archer.cpp
    ${SRC_ROOT}/characters/knight.cpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

#add_subdirectory(tests)

enable_testing()
