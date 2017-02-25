cmake_minimum_required(VERSION 3.4)

project(Grubov)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")
include_directories(include)

# Load all *.cpp files from SRC_ROOT and push them to SOURCES var
file(GLOB SOURCES ${SRC_ROOT}/*.cpp)
# Load all *.h files from `include` and push them to HEADERS var
file(GLOB HEADERS include/*.h)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
add_library(grutask src/task.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
target_compile_features(grutask PRIVATE cxx_range_for)

#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
