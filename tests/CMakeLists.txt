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

include(google_test_helper)

####################################################################################################
#  List test(s)
####################################################################################################
add_lib_tests(list_tests
   SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/unit/list/list_iterator_tests.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/unit/list/list_tests.cpp
)

target_include_directories(list_tests
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/../include
   PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(list_tests
   PRIVATE
      gtest_main
      gmock_main
)

####################################################################################################
#  Stack test(s)
####################################################################################################
add_lib_tests(stack_tests
   SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/unit/stack/stack_tests.cpp
)

target_include_directories(stack_tests
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/../include
   PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(stack_tests
   PRIVATE
      gtest_main
      gmock_main
)
