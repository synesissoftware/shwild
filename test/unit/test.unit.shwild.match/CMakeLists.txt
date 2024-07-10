
add_executable(test_unit_shwild_match_cxx
	test.unit.shwild.match.cpp
)

link_directories(${CMAKE_SOURCE_DIR}/projects/core)

target_link_libraries(test_unit_shwild_match_cxx
	shwild.core
)


# ############################## end of file ############################# #

