####################################################################################################
#  Copyright (c) 2024 Prashant Gandhi - All rights reserved
####################################################################################################

cmake_minimum_required(VERSION 3.20)

project(dsalib
   DESCRIPTION "Data Structure APIs"
   LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
   ${CMAKE_CURRENT_SOURCE_DIR}/include/milkyway/binary_search_tree/binary_search_tree.h
   ${CMAKE_CURRENT_SOURCE_DIR}/include/milkyway/binary_search_tree/binary_tree_node.h
   ${CMAKE_CURRENT_SOURCE_DIR}/include/milkyway/types.h
)

set(SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/src/binary_search_tree/binary_search_tree.cpp
)

add_library(${PROJECT_NAME}
   ${HEADERS}
   ${SOURCES}
)

target_include_directories(${PROJECT_NAME}
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
   PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(${PROJECT_NAME}
   PUBLIC
      cxx_std_14
)

enable_testing()

add_subdirectory(tests)