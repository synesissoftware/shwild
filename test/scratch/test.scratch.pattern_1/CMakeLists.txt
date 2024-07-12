
add_executable(test.scratch.pattern_1
	test.scratch.pattern_1.cpp
)

target_link_libraries(test.scratch.pattern_1
	shwild.core
)

target_compile_options(test.scratch.pattern_1 PRIVATE
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

