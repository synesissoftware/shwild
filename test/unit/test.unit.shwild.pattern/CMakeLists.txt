
add_executable(test_unit_shwild_pattern_cxx
    test.unit.shwild.pattern.cpp
)

link_directories(${CMAKE_SOURCE_DIR}/projects/core)

target_link_libraries(test_unit_shwild_pattern_cxx
    shwild.core
)


# ############################## end of file ############################# #

