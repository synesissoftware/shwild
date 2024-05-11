
include_directories(${CMAKE_SOURCE_DIR}/include)

if(APPLE)

    message("-- -- adding '/usr/local/include' to include-directories for 'test'")

    include_directories("/usr/local/include")
endif(APPLE)


# include_directories(${OPENBSD_LOCALBASE}/include)

# include(CheckIncludeFiles)
# CHECK_INCLUDE_FILES("<shwild/shwild.h>" HAVE_shwild_h LANGUAGE CXX)
# if (not HAVE_shwild_h)
#     message(FATAL_ERROR "cannot locate header 'shwild/shwild.h'")
# endif()

# CHECK_INCLUDE_FILES("<stlsoft/stlsoft.h>" HAVE_stlsoft_h LANGUAGE CXX)
# if (not HAVE_stlsoft_h)
#     message(FATAL_ERROR "cannot locate header 'stlsoft/stlsoft.h'")
# endif()


if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	if (CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()

	add_definitions(-DNOMINMAX)
endif(WIN32)

if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))

	add_compile_options("/Zc:__cplusplus")
endif()

add_subdirectory(scratch)
add_subdirectory(unit)


# ############################## end of file ############################# #

