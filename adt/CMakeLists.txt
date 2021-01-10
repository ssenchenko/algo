include (GoogleTest)
include (CMakePrintHelpers)

set (LIBRARY_NAME "adt")
set (TEST_EXECUTABLE_NAME "${LIBRARY_NAME}_tests")
set (NAME_BASES "UnionFind" "LinkedList")

# create list of sources and headers
set (HEADER_FILES "")
set (TEST_FILES "")
foreach (BASE ${NAME_BASES})
    list (APPEND HEADER_FILES "include/${LIBRARY_NAME}/${BASE}.hpp")
    list (APPEND TEST_FILES "test/${BASE}.cpp")
endforeach()

add_library (${LIBRARY_NAME} INTERFACE)
target_include_directories (${LIBRARY_NAME}
                            INTERFACE 
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:include>)
target_sources(${LIBRARY_NAME} INTERFACE ${HEADER_FILES}) # to show library files in an IDE

# executable for tests
add_executable (${TEST_EXECUTABLE_NAME} ${TEST_FILES})
target_link_libraries (${TEST_EXECUTABLE_NAME} gtest_main ${LIBRARY_NAME})

gtest_discover_tests (${TEST_EXECUTABLE_NAME})
