cmake_minimum_required(VERSION 3.4)

project(${TEST_PROJECT})

include_directories(../include/)

set(SOURCES
    main.cpp)

find_library( SOURCE_LIB
    NAMES grutask
    PATHS ../
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SOURCE_LIB})

target_link_libraries(${PROJECT_NAME} gtest)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
