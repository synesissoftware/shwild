
add_executable(example.cpp.2
	example.cpp.2.cpp
)

target_link_libraries(example.cpp.2
	shwild.core
)

target_compile_options(example.cpp.2 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
	>
	$<$<CXX_COMPILER_ID:GNU>:
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

