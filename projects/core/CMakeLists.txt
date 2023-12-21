
set(CORE_SRC_DIR ../../src)

file(GLOB CORE_SRCS
    ${CORE_SRC_DIR}/*.c
    ${CORE_SRC_DIR}/*.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(shwild_core
	${CORE_SRCS}
)

target_compile_options(shwild_core PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
		#-Wno-deprecated-copy-with-user-provided-copy
		#-Wno-missing-braces
		#-Wno-missing-field-initializers
		#-Wno-unused-parameter
		#-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS shwild_core)


