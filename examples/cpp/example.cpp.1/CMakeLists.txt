
add_executable(example.cpp.1
	example.cpp.1.cpp
)

target_link_libraries(example.cpp.1
	PRIVATE
		core
		$<$<BOOL:${STLSoft_FOUND}>:STLSoft::STLSoft>
)

target_compile_options(example.cpp.1 PRIVATE
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

