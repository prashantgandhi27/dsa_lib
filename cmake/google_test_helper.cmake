####################################################################################################
#  Copyright (c) 2024 Prashant Gandhi - All rights reserved
####################################################################################################
function(add_lib_tests test_name)
   set(options)
   set(one_value_args)
   set(multi_value_args SRCS)

   cmake_parse_arguments(arg "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

   if (NOT arg_SRCS)
        message(FATAL_ERROR "[add_lib_tests]: SRCS is a required argument")
    endif()
    if (SRCS IN_LIST arg_KEYWORDS_MISSING_VALUES)
        message(FATAL_ERROR "[add_lib_tests]: SRCS requires at least one value")
    endif()

   add_executable(${test_name} ${arg_SRCS})

   add_test(
      NAME ${test_name}
      COMMAND ${test_name}
   )
endfunction()