cmake_minimum_required(VERSION 2.8)

project(${TEST_PROJECT})

set(TEST_SOURCES
    main.cpp
    t9_test.cpp)

add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${SHARED_SOURCES})


target_link_libraries(${PROJECT_NAME} gtest)


#----------- precompiled -----------
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")

