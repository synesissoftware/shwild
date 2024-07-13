
add_executable(test_unit_shwild_match
	test.unit.shwild_match.c
)

link_directories(${CMAKE_SOURCE_DIR}/projects/core)

target_link_libraries(test_unit_shwild_match
	PRIVATE
		core
)


# ############################## end of file ############################# #

