cmake_minimum_required(VERSION 3.4)

project(War)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")
set(HEADER_ROOT "${PROJECT_SOURCE_DIR}/include")


include_directories(include)

set(HEADERS
    ${HEADER_ROOT}/weapon.h
    ${HEADER_ROOT}/armor.h
    ${HEADER_ROOT}/human.h
    ${HEADER_ROOT}/arsenal.h
    ${HEADER_ROOT}/building.h
    )

set(SOURCES
    ${SRC_ROOT}/main.cpp)

set(SHARED_SOURCES
    ${SRC_ROOT}/weapon.cpp
    ${SRC_ROOT}/armor.cpp
    ${SRC_ROOT}/human.cpp
    ${SRC_ROOT}/arsenal.cpp
    ${SRC_ROOT}/building.cpp

    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})

#-------------- tests --------------
#set(TEST_PROJECT test_${PROJECT_NAME})
#add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

#add_subdirectory(tests)

enable_testing()
