cmake_minimum_required(VERSION 3.4)

project(${TEST_PROJECT})

set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/game.cpp)


include_directories(
    ${INCLUDE_ROOT}
    ${PROJECT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${SHARED_SOURCES})

target_link_libraries(${PROJECT_NAME} gtest)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
