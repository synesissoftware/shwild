
file(GLOB CORE_SRCS
    *.cpp
)

add_library(shwild.core
    ${CORE_SRCS}
)

if (APPLE)

    message("-- -- adding '/usr/local/include' to include-directories for 'src'")

    include_directories("/usr/local/include")
endif()

if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)


# include_directories(${CMAKE_SOURCE_DIR}/include)

#[====[
]====]

set(SHWILD_PUBLIC_HEADERS
    "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h"
    "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.hpp"
)

set_target_properties(shwild.core PROPERTIES
    OUTPUT_NAME "shwild.core"
    PUBLIC_HEADER "${SHWILD_PUBLIC_HEADERS}"
)

target_include_directories(shwild.core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_options(shwild.core PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        # -Wno-deprecated-copy-with-user-provided-copy
        # -Wno-missing-braces
        # -Wno-missing-field-initializers
        # -Wno-unused-parameter
        # -Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ##########################################################
# install

install(TARGETS shwild.core
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/shwild
)

# ############################## end of file ############################# #

