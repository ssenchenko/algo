include (GoogleTest)
include(CMakePrintHelpers)

set (LIBRARY_NAME "adt")
set (TEST_EXECUTABLE_NAME "${LIBRARY_NAME}_tests")
set (NAME_BASES "UnionFind" "LinkedList")

# create list of sources and headers
set (SOURCE_FILES "")
set (HEADER_FILES "")
set (TEST_FILES "")
foreach (BASE ${NAME_BASES})
    list (APPEND HEADER_FILES "${BASE}.hpp")
    if (EXISTS "${BASE}.cpp")
        list (APPEND SOURCE_FILES "${BASE}.cpp")
    endif ()
    list (APPEND TEST_FILES "${BASE}_tests.cpp")
endforeach()

if (SOURSE_FILES)
    add_library (${LIBRARY_NAME} ${HEADER_FILES} ${SOURCE_FILES})
else ()
    add_library (${LIBRARY_NAME} INTERFACE)
    target_include_directories(${LIBRARY_NAME} INTERFACE CMAKE_CURRENT_SOURCE_DIR)
endif ()

add_executable (${TEST_EXECUTABLE_NAME} ${TEST_FILES})

target_link_libraries (${TEST_EXECUTABLE_NAME} gtest_main ${LIBRARY_NAME})

enable_testing ()

gtest_discover_tests (${TEST_EXECUTABLE_NAME})
