include (GoogleTest)
include (CMakePrintHelpers)

set (LIBRARY_NAME "challenges")
set (TEST_EXECUTABLE_NAME "${LIBRARY_NAME}_tests")
set (NAME_BASES "arrays" "dp" "lists")

# create list of sources and headers
set (SOURCE_FILES "")
set (TEST_FILES "")
foreach (BASE ${NAME_BASES})
    list (APPEND SOURCE_FILES src/${BASE}.cpp)
    list (APPEND TEST_FILES test/${BASE}.cpp)
endforeach()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

cmake_print_variables(SOURCE_FILES)
cmake_print_variables(TEST_FILES)
add_library (${LIBRARY_NAME} ${SOURCE_FILES} )
target_include_directories (${LIBRARY_NAME} 
                            PUBLIC 
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:include>)
set_target_properties(${LIBRARY_NAME} PROPERTIES COMPILE_FLAGS ${WARNINGS}) # WARNINGS from global CMakeLists

target_link_libraries(${LIBRARY_NAME} adt)

install(TARGETS ${LIBRARY_NAME} DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)

# executable for tests
add_executable (${TEST_EXECUTABLE_NAME} ${TEST_FILES} )
target_link_libraries (${TEST_EXECUTABLE_NAME} gtest_main ${LIBRARY_NAME})

gtest_discover_tests (${TEST_EXECUTABLE_NAME})
