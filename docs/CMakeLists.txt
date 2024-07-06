################################################################################
# Generate Docs
################################################################################
cmake_minimum_required(VERSION 3.20)

project(dsalib
   DESCRIPTION "Data Structure APIs"
)

OPTION(BUILD_WITH_DOCS "Generate Docs" ON)

FIND_PACKAGE( Doxygen )

IF(DOXYGEN_FOUND)
    MESSAGE(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE} -- ${DOXYGEN_VERSION}")

	# Set Doxygen input and output files.
	set(DOXYGEN_DIRS
		${CMAKE_CURRENT_SOURCE_DIR}/../include
		${CMAKE_CURRENT_SOURCE_DIR}/../docs
	)
	string(REPLACE ";" " " DOXYGEN_DIRS_STR "${DOXYGEN_DIRS}")
	set(DOXYGEN_INPUT_DIR ${DOXYGEN_DIRS_STR})
	SET(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
	SET(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/Doxyfile.in)
	SET(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	# Generate DoxyFile from the input file.
	CONFIGURE_FILE(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

	# Create Output directory.
	FILE(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

	# Create CMake Target for generating doc.
	ADD_CUSTOM_TARGET(docs ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Generating Doxygen documentation"
      VERBATIM
   )

ENDIF()