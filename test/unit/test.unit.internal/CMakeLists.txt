
add_executable(test_unit_internal_cxx
    test.unit.internal.cpp
)

link_directories(${CMAKE_SOURCE_DIR}/projects/core)

target_link_libraries(test_unit_internal_cxx
    shwild_core
)


# ############################## end of file ############################# #

