cmake_minimum_required(VERSION 3.4)

project(WarGame)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")
set(HEADER_ROOT "${PROJECT_SOURCE_DIR}/include")

#-----------  variables  -----------
set(DEPENDENCIES_DIR "${PROJECT_SOURCE_DIR}/dependencies")

#----------- Google Test -----------
set(GTEST_ROOT ${DEPENDENCIES_DIR}/gtest-1.8.0)
set(BUILD_GTEST ON CACHE BOOL "Builds the googletest subproject")
set(BUILD_GMOCK OFF CACHE BOOL "Builds the googlemock subproject")
add_subdirectory(${GTEST_ROOT} gtest)
include_directories(${GTEST_ROOT}/googletest/include)

#----------- precompiled -----------
list(APPEND CMAKE_MODULE_PATH "${DEPENDENCIES_DIR}/cotire-1.7.9/CMake")
include(cotire)

set(STDAFX_DIR "${PROJECT_SOURCE_DIR}/include")
set(STDAFX_H "${STDAFX_DIR}/stdafx.h")
include_directories(${STDAFX_DIR})

#------ fix compiler settings ------
if(MSVC)
    foreach(flags CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
        string(REPLACE "/MD" "-MT" ${flags} "${${flags}}")
    endforeach()
endif()

include_directories(include)

set(SOURCES
${SRC_ROOT}/main.cpp)

set(SHARED_SOURCES
${SRC_ROOT}/Armor.cpp ${SRC_ROOT}/Human.cpp ${SRC_ROOT}/Location.cpp ${SRC_ROOT}/Weapon.cpp)

set(HEADERS
${HEADER_ROOT}/Armor.h ${HEADER_ROOT}/Human.h ${HEADER_ROOT}/Location.h ${HEADER_ROOT}/Weapon.h)

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
