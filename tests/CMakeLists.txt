####################################################################################################
#  Copyright (c) 2024 Prashant Gandhi - All rights reserved
####################################################################################################

cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(BinarySearchTreeTests
   ${CMAKE_CURRENT_SOURCE_DIR}/unit/binary_search_tree/binary_search_tree_tests.cpp
)

target_link_libraries(BinarySearchTreeTests
   PRIVATE
      gtest_main
)

add_test(
   NAME BinarySearchTreeTests
   COMMAND BinarySearchTreeTests
)

target_include_directories(BinarySearchTreeTests
   PRIVATE
      ${PROJECT_SOURCE_DIR}/include
)
