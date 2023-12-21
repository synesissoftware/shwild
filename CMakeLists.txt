
cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

project(shwild)

if(NOT DEFINED ENV{STLSOFT})

	message(FATAL_ERROR "This build requires the environment variable STLSOFT be defined")
else()

	set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)

	#message(FATAL_ERROR "STLSOFT_INCLUDE_DIR=${STLSOFT_INCLUDE_DIR}")

	message("including \$STLSOFT/include - '${STLSOFT_INCLUDE_DIR}'")
endif()

include_directories(${STLSOFT_INCLUDE_DIR})


if(UNIX)

    add_definitions(-DUNIX)
endif()

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif()


add_subdirectory(./projects/core)

add_subdirectory(./test/unit/test.unit.internal)
add_subdirectory(./test/unit/test.unit.shwild.match)
add_subdirectory(./test/unit/test.unit.shwild.pattern)
add_subdirectory(./test/unit/test.unit.shwild_match)



install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
	)

