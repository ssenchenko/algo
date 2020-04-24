cmake_minimum_required (VERSION 3.10)

include (GoogleTest)
include(CMakePrintHelpers)

set (LIBRARY_NAME "adt")
set (TEST_EXECUTABLE_NAME "${LIBRARY_NAME}_tests")
set (NAME_BASES "UnionFind")

cmake_print_variables(NAME_BASES)

# create list of sources and headers
set (SOURCE_FILES "")
set (HEADER_FILES "")
set (TEST_FILES "")
foreach (BASE ${NAME_BASES})
    cmake_print_variables(BASE)
    list (APPEND HEADER_FILES "${BASE}.h")
    cmake_print_variables(HEADER_FILES)
    list (APPEND SOURCE_FILES "${BASE}.cpp")
    cmake_print_variables(SOURCE_FILES)
    list (APPEND TEST_FILES "test_${BASE}.cpp")
endforeach()

add_library (${LIBRARY_NAME} ${HEADER_FILES} ${SOURCE_FILES})

add_executable (${TEST_EXECUTABLE_NAME} ${TEST_FILES})

target_link_libraries (${TEST_EXECUTABLE_NAME} gtest_main ${LIBRARY_NAME})

enable_testing ()

gtest_discover_tests (${TEST_EXECUTABLE_NAME})
