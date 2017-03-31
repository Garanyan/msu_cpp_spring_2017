cmake_minimum_required(VERSION 3.4)

project(trempoltsev)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")
set(HEADERS_ROOT "${PROJECT_SOURCE_DIR}/include")

set(HEADERS
    ${HEADERS_ROOT}/arena_types.h

    ${HEADERS_ROOT}/armors/armor_type.h

    ${HEADERS_ROOT}/armors/armor.h
    ${HEADERS_ROOT}/armors/traits.h

    ${HEADERS_ROOT}/armors/chain_armor.h
    ${HEADERS_ROOT}/armors/plate_armor.h
    ${HEADERS_ROOT}/armors/without_armor.h

    ${HEADERS_ROOT}/units/unit.h
    ${HEADERS_ROOT}/units/traits.h

    ${HEADERS_ROOT}/units/archer.h
    ${HEADERS_ROOT}/units/peasant.h
    ${HEADERS_ROOT}/units/knight.h

    ${HEADERS_ROOT}/weapons/damage_type.h
    ${HEADERS_ROOT}/weapons/weapon_type.h

    ${HEADERS_ROOT}/weapons/weapon.h
    ${HEADERS_ROOT}/weapons/traits.h

    ${HEADERS_ROOT}/weapons/bow.h
    ${HEADERS_ROOT}/weapons/fists.h
    ${HEADERS_ROOT}/weapons/hammer.h
    ${HEADERS_ROOT}/weapons/shovel.h
    ${HEADERS_ROOT}/weapons/sword.h
    )

set(SOURCES
    ${SRC_ROOT}/main.cpp
    )

set(SHARED_SOURCES
    ${SRC_ROOT}/armors/armor.cpp
    ${SRC_ROOT}/armors/chain_armor.cpp
    ${SRC_ROOT}/armors/plate_armor.cpp
    ${SRC_ROOT}/armors/without_armor.cpp

    ${SRC_ROOT}/units/unit.cpp
    ${SRC_ROOT}/units/archer.cpp
    ${SRC_ROOT}/units/peasant.cpp
    ${SRC_ROOT}/units/knight.cpp

    ${SRC_ROOT}/weapons/weapon.cpp
    ${SRC_ROOT}/weapons/bow.cpp
    ${SRC_ROOT}/weapons/fists.cpp
    ${SRC_ROOT}/weapons/hammer.cpp
    ${SRC_ROOT}/weapons/shovel.cpp
    ${SRC_ROOT}/weapons/sword.cpp

    ${SRC_ROOT}/t9.h
    ${SRC_ROOT}/t9.cpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

GroupSourcesWithBase(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})

#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
