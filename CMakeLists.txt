# CMakeList.txt : CMake project for algo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project ("algo")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# use the line below to print include directories for debug time
set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES)

# Download and unpack googletest at configure time
configure_file(cmake/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# set warnings after compiling googletest
if(MSVC)
  set(WARNINGS "/W4 /permissive-")
else()
  set(WARNINGS "-Wall -Wextra -Wpedantic -Werror")
endif()

enable_testing ()

# Include sub-projects.
add_subdirectory (adt)
add_subdirectory (challenges)
