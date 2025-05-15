
# ######################################################################## #
# File:     /CMakeLists.txt
#
# Purpose:  Top-level CMake lists file for shwild
#
# Created:  21st December 2023
# Updated:  15th May 2025
#
# ######################################################################## #


# ##########################################################
# CMake

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# require out-of-source builds
file(TO_CMAKE_PATH "${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")

	message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# directory for CMake specific extensions and source files.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


# ##########################################################
# project

project(shwild
	DESCRIPTION "shwild is a small, standalone library, implemented in C++ with a C and a C++ API, that provides shell-compatible wildcard matching."
	HOMEPAGE_URL "https://github.com/synesissoftware/shwild"
	LANGUAGES C CXX
)

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

# handle version number
set(RX_PROJ_TAG "${PROJECT_NAME_UPPER}")
set(RX_WS "[ \t]")
file(READ "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h" _header_file)
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MAJOR${RX_WS}+([0-9]+)" MAJOR_DUMMY ${_header_file})
set(_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MINOR${RX_WS}+([0-9]+)" MINOR_DUMMY ${_header_file})
set(_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_(PATCH|REVISION)${RX_WS}+([0-9]+)" PATCH_DUMMY ${_header_file})
set(_VERSION_PATCH ${CMAKE_MATCH_2})

# set project version number here
set(PROJECT_VERSION_MAJOR ${_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${_VERSION_PATCH})
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# adhere strictly to C and C++ standards plus extensions. These are actually
# useless since we do not compile anything; they merely state our intention.
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # GNU extensions and POSIX standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(MSVC)

	if(MSVC_VERSION LESS 1930)

		set(CMAKE_C_STANDARD 90)
		set(CMAKE_CXX_STANDARD 98)
	endif()

	if(MSVC_USE_MT)

		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	endif(MSVC_USE_MT)
else(MSVC)

	if(MSVC_USE_MT)

		# this here just to absorb warning about not using `MSVC_USE_MT` (to
		# enable **prepare_cmake.sh** to be simple)
	endif(MSVC_USE_MT)
endif(MSVC)


# ##########################################################
# dependencies, includes, options

# ################################################
# includes - 1

include(BuildType)
include(LanguageFullVersion)
include(TargetMacros)


# ################################################
# dependencies, features, and options

# ######################################
# options

option(BUILD_EXAMPLES "Build examples" ON)

option(USE_STLSOFT_PKG "Depend on STLSoft CMake package" OFF)


# ######################################
# features


# ######################################
# dependencies
#
# required:
#
# optional:
# - BDUT - used if BDUT_ROOT CMake/environment variable specified, or if
#    CMake project found;
# - STLSoft - used if STLSOFT CMake/environment variable specified;

# ############################
# BDUT
#
# By default, shwild relies on the bundled version of BDUT. Alternatively,
# BDUT can used in the following ways:
#
# * if the environment variable BDUT_ROOT is defined, then it is assumed to
#   specify a directory within which a viable BDUT project resides. In
#   this case, the CMake variable BDUT_INCLUDE_DIR is defined;
# * if the CMake variable BDUT_ROOT is defined, then it is assumed to
#   specify a directory within which a viable BDUT project resides. In this
#   case, the CMake variable BDUT_INCLUDE_DIR is defined;
# * if CMake can detect an installation of BDUT, then it will be used;
#   otherwise
# * the bundled version of BDUT is used.

if(DEFINED BDUT_ROOT OR DEFINED ENV{BDUT_ROOT})

	if(DEFINED BDUT_ROOT)

		message("-- BDUT_ROOT provided as CMake variable with value ${BDUT_ROOT}")

		set(BDUT_INCLUDE_DIR ${BDUT_ROOT}/include)
	else()

		message("-- BDUT_ROOT provided as environment variable with value $ENV{BDUT_ROOT}")

		set(BDUT_INCLUDE_DIR $ENV{BDUT_ROOT}/include)
	endif()

	message("(before) INCLUDE_DIRECTORIES=${INCLUDE_DIRECTORIES}")

	include_directories(BEFORE ${BDUT_INCLUDE_DIR})

	message("(after) INCLUDE_DIRECTORIES=${INCLUDE_DIRECTORIES}")
else()

	find_package(BDUT QUIET)

	if(BDUT_FOUND)

		message("-- CMake package BDUT found (version ${BDUT_VERSION})")
	else(BDUT_FOUND)

		message("-- CMake package BDUT found so using bundled version")

		include_directories(BEFORE include/bundled-software)
	endif(BDUT_FOUND)
endif()


# ############################
# STLSoft
#
# By default, shwild does not use STLSoft at all and, in that circumstance,
# the symbol SHWILD_NO_STLSOFT is defined. Alternately, STLSoft can be used
# in the following ways:
#
# * if the environment variable STLSOFT is defined, then it is assumed to
#   specify a directory within which a viable STLSoft project resides. In
#   this case, the CMake variable STLSOFT_INCLUDE_DIR is defined;
# * if the CMake variable STLSOFT is defined, then it is assumed to specify
#   a directory within which a viable STLSoft project resides. In this
#   case, the CMake variable STLSOFT_INCLUDE_DIR is defined;
# * if the CMake variable USE_STLSOFT_PKG is set to ON and neither the
#   STLSoft environment nor CMake variable is defined, then STLSoft will be
#   required as a CMake package; otherwise
# * STLSoft is not used, so specify preprocessor object-like macro
#   `SHWILD_NO_STLSOFT` to elide all dependencies on STLSoft

if(DEFINED STLSOFT)

	message("-- STLSOFT provided as CMake variable with value '${STLSOFT}'")

	set(STLSOFT_INCLUDE_DIR ${STLSOFT}/include)
elseif(DEFINED ENV{STLSOFT})

	message("-- STLSOFT provided as environment variable with value '$ENV{STLSOFT}'")

	set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)
elseif(USE_STLSOFT_PKG)

	# NOTE: if you wish to use STLSoft 1.9, then you will need to:
	#
	# - limit CMAKE_C_STANDARD to 17;
	# - limit CMAKE_CXX_STANDARD to 14;
	#
	# set(STLSoft_REQUIRED_VERSION_ 1.9.136)

	set(STLSoft_REQUIRED_VERSION_ 1.11)

	find_package(STLSoft ${STLSoft_REQUIRED_VERSION_} REQUIRED)

	message("-- CMake package STLSoft found (version ${STLSoft_VERSION}; ${STLSoft_REQUIRED_VERSION_} requested)")
else()

	add_definitions(-DSHWILD_NO_STLSOFT)
endif()

if(DEFINED STLSOFT_INCLUDE_DIR)

	include_directories(${STLSOFT_INCLUDE_DIR})
endif()


# ################################################
# includes - 2

include(CMakePackageConfigHelpers)
if(BUILD_TESTING)

	include(CTest)
endif(BUILD_TESTING)
include(GNUInstallDirs)


# ##########################################################
# targets

# ################################################
# main libraries

add_subdirectory(src)


# ################################################
# examples

if(BUILD_EXAMPLES)

	message("-- enabled building of examples ...")

	add_subdirectory(examples)
else(BUILD_EXAMPLES)

	message("-- disabled building of examples - define BUILD_EXAMPLES to enable")
endif(BUILD_EXAMPLES)


# ################################################
# tests


if(BUILD_TESTING)

	message("-- enabled building of tests ...")

	add_subdirectory(test)
else(BUILD_TESTING)

	message("-- disabled building of tests - define BUILD_TESTING to enable")
endif(BUILD_TESTING)


# ##########################################################
# install


install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/shwild/internal
	DESTINATION include/shwild/
	FILES_MATCHING
	PATTERN "*.h*"
)


# ##########################################################
# export

include(CMakePackageConfigHelpers)

set(EXPORT_NAME ${PROJECT_NAME_LOWER})

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/${EXPORT_NAME}-config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake
	INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${EXPORT_NAME}/cmake
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

export(EXPORT project-targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-targets.cmake"
	NAMESPACE "${PROJECT_NAME}::"
)

install(EXPORT project-targets
	NAMESPACE "${PROJECT_NAME}::"
	FILE "${EXPORT_NAME}-targets.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)

install( FILES
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)


# ##########################################################
# completion

message(NOTICE "Generating CMake build scripts for ${PROJECT_NAME} ${PROJECT_VERSION}, for C${CMAKE_C_STANDARD} C++${CMAKE_CXX_STANDARD}, with build type ${CMAKE_BUILD_TYPE}")


# ############################## end of file ############################# #

