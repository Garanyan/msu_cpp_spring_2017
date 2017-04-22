cmake_minimum_required(VERSION 3.4)

project(task2)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include")

set(HEADERS
        ${INCLUDE_ROOT}/Armor.h
        ${INCLUDE_ROOT}/Weapon.h
        ${INCLUDE_ROOT}/Person.h

        ${INCLUDE_ROOT}/Arsenal.h
        ${INCLUDE_ROOT}/Barack.h
        ${INCLUDE_ROOT}/Arena.h

        ${INCLUDE_ROOT}/Semaphore.h
        ${INCLUDE_ROOT}/utils.h
        )

set(SOURCES
        ${SRC_ROOT}/parallel.cpp
        #${SRC_ROOT}/main.cpp
        )

set(SHARED_SOURCES
        ${SRC_ROOT}/Armor.cpp
        ${SRC_ROOT}/Weapon.cpp
        ${SRC_ROOT}/Person.cpp

        ${SRC_ROOT}/Arsenal.cpp
        ${SRC_ROOT}/Barack.cpp
        ${SRC_ROOT}/Arena.cpp
        )
        
include_directories(
    ${INCLUDE_ROOT}
)

set (CMAKE_CXX_FLAGS "-pthread")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
