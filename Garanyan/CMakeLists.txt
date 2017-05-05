cmake_minimum_required(VERSION 3.4)

project(Garanyan)

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/TheMedievalPeriodFights/src")

set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/TheMedievalPeriodFights/include")

set(HEADERS
    ${INCLUDE_ROOT}/armor.h
	${INCLUDE_ROOT}/weapon.h
	${INCLUDE_ROOT}/person.h
	${INCLUDE_ROOT}/arena.h
	${INCLUDE_ROOT}/stock.h
    )

set(SOURCES
    ${SRC_ROOT}/main.cpp
    )

set(SHARED_SOURCES
    ${SRC_ROOT}/armor.cpp
	${SRC_ROOT}/weapon.cpp
	${SRC_ROOT}/person.cpp
	${SRC_ROOT}/arena.cpp
	${SRC_ROOT}/stock.cpp
    )
	
include_directories(
    ${INCLUDE_ROOT}
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHARED_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

#----------- precompiled -----------
#set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${STDAFX_H}")
#cotire(${PROJECT_NAME})

#-------------- tests --------------
set(TEST_PROJECT test_${PROJECT_NAME})
add_test(NAME ${TEST_PROJECT} COMMAND ${TEST_PROJECT})

add_subdirectory(tests)

enable_testing()
