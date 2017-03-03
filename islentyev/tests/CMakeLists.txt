cmake_minimum_required(VERSION 3.4)

project(${TEST_PROJECT})

set(SOURCES
    main.cpp t9test.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${SHARED_SOURCES})

target_link_libraries(${PROJECT_NAME} gtest)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
