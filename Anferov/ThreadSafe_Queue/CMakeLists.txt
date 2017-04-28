cmake_minimum_required(VERSION 3.4)

project(Anferov_ThreadSafe_Queue)

set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include")

set(HEADERS
    ${INCLUDE_ROOT}/tsqueue.hpp
)

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
