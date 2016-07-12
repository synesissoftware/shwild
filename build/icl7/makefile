################################################################################
# File:     makefile
#
# Purpose:  Makefile for the shwild project, for the Intel C/C++ 7.0
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  10th August 2015
#
################################################################################


################################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # STLSOFT

################################################################################
# Symbols

# Identification

COMP_TAG          =   icl7
PROJ_TAG          =   shwild
PROJ_VER_MAJOR    =   0
PROJ_MOD_TAG      =   core
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR).$(PROJ_MOD_TAG)

CC                  =   icl
CPPC                =   icl
AR                  =   xilib
LD                  =   xilink
RM                  =   del /f
CP                  =   copy
RC                  =   rc

# Directories

PROJ_BASE_DIR       =   ..\..
PROJ_BIN_DIR        =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR    =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR        =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR        =   .
PROJ_SRC_DIR        =   $(PROJ_BASE_DIR)\src
PROJ_MAPPINGS_DIR   =   $(PROJ_BASE_DIR)\mappings
PROJ_TESTS_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_EXAMPLES_DIR   =   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR    =   $(PROJ_BASE_DIR)\samples

# Includes

INCLUDES_LEADER     =   

PROJ_INCLUDE        =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES     =   

CC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(STLSOFT)\include"\
 \

CC_INCLUDES_TEST=\
 $(CC_INCLUDES)\
 -I"$(OPENRJ_ROOT)\include"


CPPC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(STLSOFT)\include"\
 \

CPPC_INCLUDES_TEST=\
 $(CPPC_INCLUDES)\
 -I"$(OPENRJ_ROOT)\include"


3PTY_LIBS__MT_D = \
 \

3PTY_LIBS__MT_D_TEST = \
 $(3PTY_LIBS__MT_D)\
 openrj.1.$(COMP_TAG).mt.debug.lib\
 \

3PTY_LIBS__DLL_D = \
 \

3PTY_LIBS__DLL_D_TEST = \
 $(3PTY_LIBS__DLL_D)\
 openrj.1.$(COMP_TAG).dll.debug.lib\
 \

3PTY_LIBS__DLL_R = \
 \

3PTY_LIBS__DLL_R_TEST = \
 $(3PTY_LIBS__DLL_R)\
 openrj.1.$(COMP_TAG).dll.lib\
 \

3PTY_LIBS__MT_R = \
 \

3PTY_LIBS__MT_R_TEST = \
 $(3PTY_LIBS__MT_R)\
 openrj.1.$(COMP_TAG).mt.lib\
 \

3PTY_LIBS__ST_D = \
 \

3PTY_LIBS__ST_D_TEST = \
 $(3PTY_LIBS__ST_D)\
 openrj.1.$(COMP_TAG).debug.lib\
 \

3PTY_LIBS__ST_R = \
 \

3PTY_LIBS__ST_R_TEST = \
 $(3PTY_LIBS__ST_R)\
 openrj.1.$(COMP_TAG).lib\
 \


LIB_PATHS =\
 \

LIB_PATHS_TEST =\
 $(LIB_PATHS)\
 -libpath:$(OPENRJ_ROOT)\lib\
 \

LIBS_LEADER         =   

COMMON_LIB          =   

# #defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DSHWILD_NO_IMPLICIT_LINK\
 \

COMMON_DEFS         =   -DWIN32 $(CMN_DEF_NO_IMPLICIT_LINK)

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)

CC_DEFS 			=	$(COMMON_DEFS) $(CC_CUSTOM_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS) $(CPPC_CUSTOM_DEFS)

# Flags

CC_F_NOLOGO             =   -nologo
CC_F_COMPILE_ONLY       =   -c
CC_F_WARNING_MAX        =   -W4
CC_F_WARNING_ERR        =   -WX

CPPC_F_NOLOGO       =   -nologo
CPPC_F_COMPILE_ONLY =   -c
CPPC_F_WARNING_MAX  =   -W4
CPPC_F_WARNING_ERR  =   -WX
CPPC_F_EXCEPTIONS   =   -GX
CPPC_F_RTTI         =   -GR

CC_TOOL_FLAGS       =   

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CPPC_TOOL_FLAGS     =   

CPPC_FLAGS = \
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

# Arguments (= flags + defines + includes)

CC_ARGS_MT_D = -MTd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_D_TEST = -MTd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)
CC_ARGS_DLL_D = -MDd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_D_TEST = -MDd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)
CC_ARGS_DLL_R = -MD -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_R_TEST = -MD -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)
CC_ARGS_MT_R = -MT -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_R_TEST = -MT -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)
CC_ARGS_ST_D = -MLd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_D_TEST = -MLd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)
CC_ARGS_ST_R = -ML -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_R_TEST = -ML -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)

CPPC_ARGS_MT_D = -MTd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_MT_D_TEST = -MTd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)
CPPC_ARGS_DLL_D = -MDd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_DLL_D_TEST = -MDd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)
CPPC_ARGS_DLL_R = -MD -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_DLL_R_TEST = -MD -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)
CPPC_ARGS_MT_R = -MT -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_MT_R_TEST = -MT -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)
CPPC_ARGS_ST_D = -MLd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_D_TEST = -MLd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)
CPPC_ARGS_ST_R = -ML -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_R_TEST = -ML -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)

# archiver flags and arguments

AR_ARGS = -nologo

# linker flags and arguments

LD_F_NOLOGO = -nologo

LD_ARGS_MT_D = -nologo $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_MT_D_TEST = -nologo $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)
LD_ARGS_DLL_D = -nologo $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_DLL_D_TEST = -nologo $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)
LD_ARGS_DLL_R = -nologo $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_DLL_R_TEST = -nologo $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)
LD_ARGS_MT_R = -nologo $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_MT_R_TEST = -nologo $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)
LD_ARGS_ST_D = -nologo $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_D_TEST = -nologo $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)
LD_ARGS_ST_R = -nologo $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_R_TEST = -nologo $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_MT_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).mt.debug.lib
TARGET_LIB_UN_MT_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.debug.lib
TARGET_LIB_DLL_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).dll.debug.lib
TARGET_LIB_UN_DLL_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).dll.debug.lib
TARGET_LIB_DLL_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).dll.lib
TARGET_LIB_UN_DLL_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).dll.lib
TARGET_LIB_MT_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).mt.lib
TARGET_LIB_UN_MT_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.lib
TARGET_LIB_ST_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_ST_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).lib
TARGET_LIB_UN_ST_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGETS_LIBS =\
 $(TARGET_LIB_MT_D)\
 $(TARGET_LIB_UN_MT_D)\
 $(TARGET_LIB_DLL_D)\
 $(TARGET_LIB_UN_DLL_D)\
 $(TARGET_LIB_DLL_R)\
 $(TARGET_LIB_UN_DLL_R)\
 $(TARGET_LIB_MT_R)\
 $(TARGET_LIB_UN_MT_R)\
 $(TARGET_LIB_ST_D)\
 $(TARGET_LIB_UN_ST_D)\
 $(TARGET_LIB_ST_R)\
 $(TARGET_LIB_UN_ST_R)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).mt.debug.exe
TARGET_TEST_CPP_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).mt.debug.exe
TARGET_TEST_CPP_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).mt.debug.exe
TARGET_TEST_C_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).dll.debug.exe
TARGET_TEST_CPP_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).dll.debug.exe
TARGET_TEST_CPP_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).dll.debug.exe
TARGET_TEST_C_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).dll.exe
TARGET_TEST_CPP_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).dll.exe
TARGET_TEST_CPP_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).dll.exe
TARGET_TEST_C_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).mt.exe
TARGET_TEST_CPP_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).mt.exe
TARGET_TEST_CPP_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).mt.exe
TARGET_TEST_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).exe
TARGET_TEST_CPP_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).exe
TARGET_TEST_CPP_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_MT_D)\
 $(TARGET_TEST_C_1_DLL_D)\
 $(TARGET_TEST_C_1_DLL_R)\
 $(TARGET_TEST_C_1_MT_R)\
 $(TARGET_TEST_C_1_ST_D)\
 $(TARGET_TEST_C_1_ST_R)\
 $(TARGET_TEST_CPP_1_MT_D)\
 $(TARGET_TEST_CPP_2_MT_D)\
 $(TARGET_TEST_CPP_1_DLL_D)\
 $(TARGET_TEST_CPP_2_DLL_D)\
 $(TARGET_TEST_CPP_1_DLL_R)\
 $(TARGET_TEST_CPP_2_DLL_R)\
 $(TARGET_TEST_CPP_1_MT_R)\
 $(TARGET_TEST_CPP_2_MT_R)\
 $(TARGET_TEST_CPP_1_ST_D)\
 $(TARGET_TEST_CPP_2_ST_D)\
 $(TARGET_TEST_CPP_1_ST_R)\
 $(TARGET_TEST_CPP_2_ST_R)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_C_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_CPP_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_CPP_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_C_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_C_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_CPP_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_CPP_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_C_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_C_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_CPP_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_CPP_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_C_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_C_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_CPP_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_CPP_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).exe
TARGET_EXAMPLE_C_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_MT_D)\
 $(TARGET_EXAMPLE_C_2_MT_D)\
 $(TARGET_EXAMPLE_C_1_DLL_D)\
 $(TARGET_EXAMPLE_C_2_DLL_D)\
 $(TARGET_EXAMPLE_C_1_DLL_R)\
 $(TARGET_EXAMPLE_C_2_DLL_R)\
 $(TARGET_EXAMPLE_C_1_MT_R)\
 $(TARGET_EXAMPLE_C_2_MT_R)\
 $(TARGET_EXAMPLE_C_1_ST_D)\
 $(TARGET_EXAMPLE_C_2_ST_D)\
 $(TARGET_EXAMPLE_C_1_ST_R)\
 $(TARGET_EXAMPLE_C_2_ST_R)\
 $(TARGET_EXAMPLE_CPP_1_MT_D)\
 $(TARGET_EXAMPLE_CPP_2_MT_D)\
 $(TARGET_EXAMPLE_CPP_1_DLL_D)\
 $(TARGET_EXAMPLE_CPP_2_DLL_D)\
 $(TARGET_EXAMPLE_CPP_1_DLL_R)\
 $(TARGET_EXAMPLE_CPP_2_DLL_R)\
 $(TARGET_EXAMPLE_CPP_1_MT_R)\
 $(TARGET_EXAMPLE_CPP_2_MT_R)\
 $(TARGET_EXAMPLE_CPP_1_ST_D)\
 $(TARGET_EXAMPLE_CPP_2_ST_D)\
 $(TARGET_EXAMPLE_CPP_1_ST_R)\
 $(TARGET_EXAMPLE_CPP_2_ST_R)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).mt.debug.exe
TARGET_SAMPLE_C_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).mt.debug.exe
TARGET_SAMPLE_CPP_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).mt.debug.exe
TARGET_SAMPLE_CPP_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).mt.debug.exe
TARGET_SAMPLE_C_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).dll.debug.exe
TARGET_SAMPLE_C_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).dll.debug.exe
TARGET_SAMPLE_CPP_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).dll.debug.exe
TARGET_SAMPLE_CPP_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).dll.debug.exe
TARGET_SAMPLE_C_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).dll.exe
TARGET_SAMPLE_C_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).dll.exe
TARGET_SAMPLE_CPP_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).dll.exe
TARGET_SAMPLE_CPP_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).dll.exe
TARGET_SAMPLE_C_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).mt.exe
TARGET_SAMPLE_C_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).mt.exe
TARGET_SAMPLE_CPP_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).mt.exe
TARGET_SAMPLE_CPP_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).mt.exe
TARGET_SAMPLE_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).exe
TARGET_SAMPLE_C_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).exe
TARGET_SAMPLE_CPP_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).exe
TARGET_SAMPLE_CPP_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_MT_D)\
 $(TARGET_SAMPLE_C_2_MT_D)\
 $(TARGET_SAMPLE_C_1_DLL_D)\
 $(TARGET_SAMPLE_C_2_DLL_D)\
 $(TARGET_SAMPLE_C_1_DLL_R)\
 $(TARGET_SAMPLE_C_2_DLL_R)\
 $(TARGET_SAMPLE_C_1_MT_R)\
 $(TARGET_SAMPLE_C_2_MT_R)\
 $(TARGET_SAMPLE_C_1_ST_D)\
 $(TARGET_SAMPLE_C_2_ST_D)\
 $(TARGET_SAMPLE_C_1_ST_R)\
 $(TARGET_SAMPLE_C_2_ST_R)\
 $(TARGET_SAMPLE_CPP_1_MT_D)\
 $(TARGET_SAMPLE_CPP_2_MT_D)\
 $(TARGET_SAMPLE_CPP_1_DLL_D)\
 $(TARGET_SAMPLE_CPP_2_DLL_D)\
 $(TARGET_SAMPLE_CPP_1_DLL_R)\
 $(TARGET_SAMPLE_CPP_2_DLL_R)\
 $(TARGET_SAMPLE_CPP_1_MT_R)\
 $(TARGET_SAMPLE_CPP_2_MT_R)\
 $(TARGET_SAMPLE_CPP_1_ST_D)\
 $(TARGET_SAMPLE_CPP_2_ST_D)\
 $(TARGET_SAMPLE_CPP_1_ST_R)\
 $(TARGET_SAMPLE_CPP_2_ST_R)\
 \

########################################
# TARGETS

TARGETS = \
 $(TARGETS_LIBS)\
 $(TARGETS_TESTS)\
 $(TARGETS_EXAMPLES)\
 $(TARGETS_SAMPLES)\
 \

########################################
# OBJS_CORE

OBJ_CORE_matches__MT_D = $(PROJ_OBJ_DIR)\matches.mt.debug.obj
OBJ_CORE_pattern__MT_D = $(PROJ_OBJ_DIR)\pattern.mt.debug.obj
OBJ_CORE_api__MT_D = $(PROJ_OBJ_DIR)\api.mt.debug.obj

OBJS_CORE_MT_D = \
 $(OBJ_CORE_matches__MT_D)\
 $(OBJ_CORE_pattern__MT_D)\
 $(OBJ_CORE_api__MT_D)\
 \


OBJ_CORE_matches__DLL_D = $(PROJ_OBJ_DIR)\matches.dll.debug.obj
OBJ_CORE_pattern__DLL_D = $(PROJ_OBJ_DIR)\pattern.dll.debug.obj
OBJ_CORE_api__DLL_D = $(PROJ_OBJ_DIR)\api.dll.debug.obj

OBJS_CORE_DLL_D = \
 $(OBJ_CORE_matches__DLL_D)\
 $(OBJ_CORE_pattern__DLL_D)\
 $(OBJ_CORE_api__DLL_D)\
 \


OBJ_CORE_matches__DLL_R = $(PROJ_OBJ_DIR)\matches.dll.obj
OBJ_CORE_pattern__DLL_R = $(PROJ_OBJ_DIR)\pattern.dll.obj
OBJ_CORE_api__DLL_R = $(PROJ_OBJ_DIR)\api.dll.obj

OBJS_CORE_DLL_R = \
 $(OBJ_CORE_matches__DLL_R)\
 $(OBJ_CORE_pattern__DLL_R)\
 $(OBJ_CORE_api__DLL_R)\
 \


OBJ_CORE_matches__MT_R = $(PROJ_OBJ_DIR)\matches.mt.obj
OBJ_CORE_pattern__MT_R = $(PROJ_OBJ_DIR)\pattern.mt.obj
OBJ_CORE_api__MT_R = $(PROJ_OBJ_DIR)\api.mt.obj

OBJS_CORE_MT_R = \
 $(OBJ_CORE_matches__MT_R)\
 $(OBJ_CORE_pattern__MT_R)\
 $(OBJ_CORE_api__MT_R)\
 \


OBJ_CORE_matches__ST_D = $(PROJ_OBJ_DIR)\matches.debug.obj
OBJ_CORE_pattern__ST_D = $(PROJ_OBJ_DIR)\pattern.debug.obj
OBJ_CORE_api__ST_D = $(PROJ_OBJ_DIR)\api.debug.obj

OBJS_CORE_ST_D = \
 $(OBJ_CORE_matches__ST_D)\
 $(OBJ_CORE_pattern__ST_D)\
 $(OBJ_CORE_api__ST_D)\
 \


OBJ_CORE_matches__ST_R = $(PROJ_OBJ_DIR)\matches.obj
OBJ_CORE_pattern__ST_R = $(PROJ_OBJ_DIR)\pattern.obj
OBJ_CORE_api__ST_R = $(PROJ_OBJ_DIR)\api.obj

OBJS_CORE_ST_R = \
 $(OBJ_CORE_matches__ST_R)\
 $(OBJ_CORE_pattern__ST_R)\
 $(OBJ_CORE_api__ST_R)\
 \


OBJS_CORE =\
 $(OBJS_CORE_MT_D)\
 $(OBJS_CORE_DLL_D)\
 $(OBJS_CORE_DLL_R)\
 $(OBJS_CORE_MT_R)\
 $(OBJS_CORE_ST_D)\
 $(OBJS_CORE_ST_R)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_MT_D = $(PROJ_OBJ_DIR)\test_c_1.mt.debug.obj
OBJ_TEST_CPP_1_MT_D = $(PROJ_OBJ_DIR)\test_cpp_1.mt.debug.obj
OBJ_TEST_CPP_2_MT_D = $(PROJ_OBJ_DIR)\test_cpp_2.mt.debug.obj
OBJ_TEST_C_1_DLL_D = $(PROJ_OBJ_DIR)\test_c_1.dll.debug.obj
OBJ_TEST_CPP_1_DLL_D = $(PROJ_OBJ_DIR)\test_cpp_1.dll.debug.obj
OBJ_TEST_CPP_2_DLL_D = $(PROJ_OBJ_DIR)\test_cpp_2.dll.debug.obj
OBJ_TEST_C_1_DLL_R = $(PROJ_OBJ_DIR)\test_c_1.dll.obj
OBJ_TEST_CPP_1_DLL_R = $(PROJ_OBJ_DIR)\test_cpp_1.dll.obj
OBJ_TEST_CPP_2_DLL_R = $(PROJ_OBJ_DIR)\test_cpp_2.dll.obj
OBJ_TEST_C_1_MT_R = $(PROJ_OBJ_DIR)\test_c_1.mt.obj
OBJ_TEST_CPP_1_MT_R = $(PROJ_OBJ_DIR)\test_cpp_1.mt.obj
OBJ_TEST_CPP_2_MT_R = $(PROJ_OBJ_DIR)\test_cpp_2.mt.obj
OBJ_TEST_C_1_ST_D = $(PROJ_OBJ_DIR)\test_c_1.debug.obj
OBJ_TEST_CPP_1_ST_D = $(PROJ_OBJ_DIR)\test_cpp_1.debug.obj
OBJ_TEST_CPP_2_ST_D = $(PROJ_OBJ_DIR)\test_cpp_2.debug.obj
OBJ_TEST_C_1_ST_R = $(PROJ_OBJ_DIR)\test_c_1.obj
OBJ_TEST_CPP_1_ST_R = $(PROJ_OBJ_DIR)\test_cpp_1.obj
OBJ_TEST_CPP_2_ST_R = $(PROJ_OBJ_DIR)\test_cpp_2.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_MT_D)\
 $(OBJ_TEST_C_1_DLL_D)\
 $(OBJ_TEST_C_1_DLL_R)\
 $(OBJ_TEST_C_1_MT_R)\
 $(OBJ_TEST_C_1_ST_D)\
 $(OBJ_TEST_C_1_ST_R)\
 $(OBJ_TEST_CPP_1_MT_D)\
 $(OBJ_TEST_CPP_2_MT_D)\
 $(OBJ_TEST_CPP_1_DLL_D)\
 $(OBJ_TEST_CPP_2_DLL_D)\
 $(OBJ_TEST_CPP_1_DLL_R)\
 $(OBJ_TEST_CPP_2_DLL_R)\
 $(OBJ_TEST_CPP_1_MT_R)\
 $(OBJ_TEST_CPP_2_MT_R)\
 $(OBJ_TEST_CPP_1_ST_D)\
 $(OBJ_TEST_CPP_2_ST_D)\
 $(OBJ_TEST_CPP_1_ST_R)\
 $(OBJ_TEST_CPP_2_ST_R)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_MT_D = $(PROJ_OBJ_DIR)\example_c_1.mt.debug.obj
OBJ_EXAMPLE_C_2_MT_D = $(PROJ_OBJ_DIR)\example_c_2.mt.debug.obj
OBJ_EXAMPLE_CPP_1_MT_D = $(PROJ_OBJ_DIR)\example_cpp_1.mt.debug.obj
OBJ_EXAMPLE_CPP_2_MT_D = $(PROJ_OBJ_DIR)\example_cpp_2.mt.debug.obj
OBJ_EXAMPLE_C_1_DLL_D = $(PROJ_OBJ_DIR)\example_c_1.dll.debug.obj
OBJ_EXAMPLE_C_2_DLL_D = $(PROJ_OBJ_DIR)\example_c_2.dll.debug.obj
OBJ_EXAMPLE_CPP_1_DLL_D = $(PROJ_OBJ_DIR)\example_cpp_1.dll.debug.obj
OBJ_EXAMPLE_CPP_2_DLL_D = $(PROJ_OBJ_DIR)\example_cpp_2.dll.debug.obj
OBJ_EXAMPLE_C_1_DLL_R = $(PROJ_OBJ_DIR)\example_c_1.dll.obj
OBJ_EXAMPLE_C_2_DLL_R = $(PROJ_OBJ_DIR)\example_c_2.dll.obj
OBJ_EXAMPLE_CPP_1_DLL_R = $(PROJ_OBJ_DIR)\example_cpp_1.dll.obj
OBJ_EXAMPLE_CPP_2_DLL_R = $(PROJ_OBJ_DIR)\example_cpp_2.dll.obj
OBJ_EXAMPLE_C_1_MT_R = $(PROJ_OBJ_DIR)\example_c_1.mt.obj
OBJ_EXAMPLE_C_2_MT_R = $(PROJ_OBJ_DIR)\example_c_2.mt.obj
OBJ_EXAMPLE_CPP_1_MT_R = $(PROJ_OBJ_DIR)\example_cpp_1.mt.obj
OBJ_EXAMPLE_CPP_2_MT_R = $(PROJ_OBJ_DIR)\example_cpp_2.mt.obj
OBJ_EXAMPLE_C_1_ST_D = $(PROJ_OBJ_DIR)\example_c_1.debug.obj
OBJ_EXAMPLE_C_2_ST_D = $(PROJ_OBJ_DIR)\example_c_2.debug.obj
OBJ_EXAMPLE_CPP_1_ST_D = $(PROJ_OBJ_DIR)\example_cpp_1.debug.obj
OBJ_EXAMPLE_CPP_2_ST_D = $(PROJ_OBJ_DIR)\example_cpp_2.debug.obj
OBJ_EXAMPLE_C_1_ST_R = $(PROJ_OBJ_DIR)\example_c_1.obj
OBJ_EXAMPLE_C_2_ST_R = $(PROJ_OBJ_DIR)\example_c_2.obj
OBJ_EXAMPLE_CPP_1_ST_R = $(PROJ_OBJ_DIR)\example_cpp_1.obj
OBJ_EXAMPLE_CPP_2_ST_R = $(PROJ_OBJ_DIR)\example_cpp_2.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_MT_D)\
 $(OBJ_EXAMPLE_C_2_MT_D)\
 $(OBJ_EXAMPLE_C_1_DLL_D)\
 $(OBJ_EXAMPLE_C_2_DLL_D)\
 $(OBJ_EXAMPLE_C_1_DLL_R)\
 $(OBJ_EXAMPLE_C_2_DLL_R)\
 $(OBJ_EXAMPLE_C_1_MT_R)\
 $(OBJ_EXAMPLE_C_2_MT_R)\
 $(OBJ_EXAMPLE_C_1_ST_D)\
 $(OBJ_EXAMPLE_C_2_ST_D)\
 $(OBJ_EXAMPLE_C_1_ST_R)\
 $(OBJ_EXAMPLE_C_2_ST_R)\
 $(OBJ_EXAMPLE_CPP_1_MT_D)\
 $(OBJ_EXAMPLE_CPP_2_MT_D)\
 $(OBJ_EXAMPLE_CPP_1_DLL_D)\
 $(OBJ_EXAMPLE_CPP_2_DLL_D)\
 $(OBJ_EXAMPLE_CPP_1_DLL_R)\
 $(OBJ_EXAMPLE_CPP_2_DLL_R)\
 $(OBJ_EXAMPLE_CPP_1_MT_R)\
 $(OBJ_EXAMPLE_CPP_2_MT_R)\
 $(OBJ_EXAMPLE_CPP_1_ST_D)\
 $(OBJ_EXAMPLE_CPP_2_ST_D)\
 $(OBJ_EXAMPLE_CPP_1_ST_R)\
 $(OBJ_EXAMPLE_CPP_2_ST_R)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_MT_D = $(PROJ_OBJ_DIR)\sample_c_1.mt.debug.obj
OBJ_SAMPLE_C_2_MT_D = $(PROJ_OBJ_DIR)\sample_c_2.mt.debug.obj
OBJ_SAMPLE_CPP_1_MT_D = $(PROJ_OBJ_DIR)\sample_cpp_1.mt.debug.obj
OBJ_SAMPLE_CPP_2_MT_D = $(PROJ_OBJ_DIR)\sample_cpp_2.mt.debug.obj
OBJ_SAMPLE_C_1_DLL_D = $(PROJ_OBJ_DIR)\sample_c_1.dll.debug.obj
OBJ_SAMPLE_C_2_DLL_D = $(PROJ_OBJ_DIR)\sample_c_2.dll.debug.obj
OBJ_SAMPLE_CPP_1_DLL_D = $(PROJ_OBJ_DIR)\sample_cpp_1.dll.debug.obj
OBJ_SAMPLE_CPP_2_DLL_D = $(PROJ_OBJ_DIR)\sample_cpp_2.dll.debug.obj
OBJ_SAMPLE_C_1_DLL_R = $(PROJ_OBJ_DIR)\sample_c_1.dll.obj
OBJ_SAMPLE_C_2_DLL_R = $(PROJ_OBJ_DIR)\sample_c_2.dll.obj
OBJ_SAMPLE_CPP_1_DLL_R = $(PROJ_OBJ_DIR)\sample_cpp_1.dll.obj
OBJ_SAMPLE_CPP_2_DLL_R = $(PROJ_OBJ_DIR)\sample_cpp_2.dll.obj
OBJ_SAMPLE_C_1_MT_R = $(PROJ_OBJ_DIR)\sample_c_1.mt.obj
OBJ_SAMPLE_C_2_MT_R = $(PROJ_OBJ_DIR)\sample_c_2.mt.obj
OBJ_SAMPLE_CPP_1_MT_R = $(PROJ_OBJ_DIR)\sample_cpp_1.mt.obj
OBJ_SAMPLE_CPP_2_MT_R = $(PROJ_OBJ_DIR)\sample_cpp_2.mt.obj
OBJ_SAMPLE_C_1_ST_D = $(PROJ_OBJ_DIR)\sample_c_1.debug.obj
OBJ_SAMPLE_C_2_ST_D = $(PROJ_OBJ_DIR)\sample_c_2.debug.obj
OBJ_SAMPLE_CPP_1_ST_D = $(PROJ_OBJ_DIR)\sample_cpp_1.debug.obj
OBJ_SAMPLE_CPP_2_ST_D = $(PROJ_OBJ_DIR)\sample_cpp_2.debug.obj
OBJ_SAMPLE_C_1_ST_R = $(PROJ_OBJ_DIR)\sample_c_1.obj
OBJ_SAMPLE_C_2_ST_R = $(PROJ_OBJ_DIR)\sample_c_2.obj
OBJ_SAMPLE_CPP_1_ST_R = $(PROJ_OBJ_DIR)\sample_cpp_1.obj
OBJ_SAMPLE_CPP_2_ST_R = $(PROJ_OBJ_DIR)\sample_cpp_2.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_MT_D)\
 $(OBJ_SAMPLE_C_2_MT_D)\
 $(OBJ_SAMPLE_C_1_DLL_D)\
 $(OBJ_SAMPLE_C_2_DLL_D)\
 $(OBJ_SAMPLE_C_1_DLL_R)\
 $(OBJ_SAMPLE_C_2_DLL_R)\
 $(OBJ_SAMPLE_C_1_MT_R)\
 $(OBJ_SAMPLE_C_2_MT_R)\
 $(OBJ_SAMPLE_C_1_ST_D)\
 $(OBJ_SAMPLE_C_2_ST_D)\
 $(OBJ_SAMPLE_C_1_ST_R)\
 $(OBJ_SAMPLE_C_2_ST_R)\
 $(OBJ_SAMPLE_CPP_1_MT_D)\
 $(OBJ_SAMPLE_CPP_2_MT_D)\
 $(OBJ_SAMPLE_CPP_1_DLL_D)\
 $(OBJ_SAMPLE_CPP_2_DLL_D)\
 $(OBJ_SAMPLE_CPP_1_DLL_R)\
 $(OBJ_SAMPLE_CPP_2_DLL_R)\
 $(OBJ_SAMPLE_CPP_1_MT_R)\
 $(OBJ_SAMPLE_CPP_2_MT_R)\
 $(OBJ_SAMPLE_CPP_1_ST_D)\
 $(OBJ_SAMPLE_CPP_2_ST_D)\
 $(OBJ_SAMPLE_CPP_1_ST_R)\
 $(OBJ_SAMPLE_CPP_2_ST_R)\
 \


########################################
# OBJS

OBJS = \
 $(OBJS_LIBS)\
 $(OBJS_TESTS)\
 $(OBJS_EXAMPLES)\
 $(OBJS_SAMPLES)\
 \

########################################
# SRC_CORE

LIB_CORE_shwild_H = $(PROJ_INCLUDE_DIR)\shwild\shwild.h
LIB_CORE_implicit_link_H = $(PROJ_INCLUDE_DIR)\shwild\implicit_link.h

LIB_CORE_matches_CPP = $(PROJ_SRC_DIR)\matches.cpp
LIB_CORE_pattern_CPP = $(PROJ_SRC_DIR)\pattern.cpp
LIB_CORE_api_CPP = $(PROJ_SRC_DIR)\api.cpp

########################################
# SRC_HEADERS

HEADERS_LIB	= \
 $(LIB_CORE_shwild_H)\
 $(LIB_CORE_implicit_link_H)\
 \

HEADERS_MAPPING_CPP =\
 $(PROJ_INCLUDE_DIR)\shwild\shwild.hpp\
 \

########################################
# SRC_TESTS

SRC_TEST_C_1 = $(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c
SRC_TEST_CPP_1 = $(PROJ_TESTS_DIR)\cpp\test_cpp_1\test_cpp_1.cpp
SRC_TEST_CPP_2 = $(PROJ_TESTS_DIR)\cpp\test_cpp_2\test_cpp_2.cpp

########################################
# SRC_EXAMPLES

SRC_EXAMPLE_C_1 = $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c
SRC_EXAMPLE_C_2 = $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c
SRC_EXAMPLE_CPP_1 = $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp
SRC_EXAMPLE_CPP_2 = $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

########################################
# SRC_SAMPLES

SRC_SAMPLE_C_1 = $(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c
SRC_SAMPLE_C_2 = $(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c
SRC_SAMPLE_CPP_1 = $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_1\sample_cpp_1.cpp
SRC_SAMPLE_CPP_2 = $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_2\sample_cpp_2.cpp

################################################################################
# External Targets (invokable by make)

target:             build

check.lib.dir:
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)

build.libs.core:    check.lib.dir $(TARGETS_LIBS)

build.libs.com:     makefile

build.libs.dotnet:  makefile

build.libs:         build.libs.core build.libs.com build.libs.dotnet

build.examples:     check.bin.dir $(TARGETS_EXAMPLES)

build.samples:      check.bin.dir $(TARGETS_SAMPLES)

build.test:         check.bin.dir $(TARGETS_TESTS)

build.all:          build.libs build.examples build.samples build.test

build:              build.libs build.examples build.samples

all:                build.all

compile:            $(OBJS)


test_:              makefile
	$(TARGET_TEST_C_1_MT_D) --unittest
	$(TARGET_TEST_C_1_DLL_D) --unittest
	$(TARGET_TEST_C_1_DLL_R) --unittest
	$(TARGET_TEST_C_1_MT_R) --unittest
	$(TARGET_TEST_C_1_ST_D) --unittest
	$(TARGET_TEST_C_1_ST_R) --unittest
	$(TARGET_TEST_CPP_1_MT_D) --unittest
	$(TARGET_TEST_CPP_2_MT_D) --unittest
	$(TARGET_TEST_CPP_1_DLL_D) --unittest
	$(TARGET_TEST_CPP_2_DLL_D) --unittest
	$(TARGET_TEST_CPP_1_DLL_R) --unittest
	$(TARGET_TEST_CPP_2_DLL_R) --unittest
	$(TARGET_TEST_CPP_1_MT_R) --unittest
	$(TARGET_TEST_CPP_2_MT_R) --unittest
	$(TARGET_TEST_CPP_1_ST_D) --unittest
	$(TARGET_TEST_CPP_2_ST_D) --unittest
	$(TARGET_TEST_CPP_1_ST_R) --unittest
	$(TARGET_TEST_CPP_2_ST_R) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_MT_D)
	@-$(RM) $(TARGET_LIB_UN_MT_D)
	@-$(RM) $(TARGET_LIB_DLL_D)
	@-$(RM) $(TARGET_LIB_UN_DLL_D)
	@-$(RM) $(TARGET_LIB_DLL_R)
	@-$(RM) $(TARGET_LIB_UN_DLL_R)
	@-$(RM) $(TARGET_LIB_MT_R)
	@-$(RM) $(TARGET_LIB_UN_MT_R)
	@-$(RM) $(TARGET_LIB_ST_D)
	@-$(RM) $(TARGET_LIB_UN_ST_D)
	@-$(RM) $(TARGET_LIB_ST_R)
	@-$(RM) $(TARGET_LIB_UN_ST_R)
	@-$(RM) $(OBJ_CORE_matches__MT_D)
	@-$(RM) $(OBJ_CORE_pattern__MT_D)
	@-$(RM) $(OBJ_CORE_api__MT_D)
	@-$(RM) $(OBJ_CORE_matches__DLL_D)
	@-$(RM) $(OBJ_CORE_pattern__DLL_D)
	@-$(RM) $(OBJ_CORE_api__DLL_D)
	@-$(RM) $(OBJ_CORE_matches__DLL_R)
	@-$(RM) $(OBJ_CORE_pattern__DLL_R)
	@-$(RM) $(OBJ_CORE_api__DLL_R)
	@-$(RM) $(OBJ_CORE_matches__MT_R)
	@-$(RM) $(OBJ_CORE_pattern__MT_R)
	@-$(RM) $(OBJ_CORE_api__MT_R)
	@-$(RM) $(OBJ_CORE_matches__ST_D)
	@-$(RM) $(OBJ_CORE_pattern__ST_D)
	@-$(RM) $(OBJ_CORE_api__ST_D)
	@-$(RM) $(OBJ_CORE_matches__ST_R)
	@-$(RM) $(OBJ_CORE_pattern__ST_R)
	@-$(RM) $(OBJ_CORE_api__ST_R)

clean.libs.com:	makefile

clean.libs.dotnet:	makefile

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_MT_D)
	@-$(RM) $(TARGET_TEST_C_1_DLL_D)
	@-$(RM) $(TARGET_TEST_C_1_DLL_R)
	@-$(RM) $(TARGET_TEST_C_1_MT_R)
	@-$(RM) $(TARGET_TEST_C_1_ST_D)
	@-$(RM) $(TARGET_TEST_C_1_ST_R)
	@-$(RM) $(TARGET_TEST_CPP_1_MT_D)
	@-$(RM) $(TARGET_TEST_CPP_2_MT_D)
	@-$(RM) $(TARGET_TEST_CPP_1_DLL_D)
	@-$(RM) $(TARGET_TEST_CPP_2_DLL_D)
	@-$(RM) $(TARGET_TEST_CPP_1_DLL_R)
	@-$(RM) $(TARGET_TEST_CPP_2_DLL_R)
	@-$(RM) $(TARGET_TEST_CPP_1_MT_R)
	@-$(RM) $(TARGET_TEST_CPP_2_MT_R)
	@-$(RM) $(TARGET_TEST_CPP_1_ST_D)
	@-$(RM) $(TARGET_TEST_CPP_2_ST_D)
	@-$(RM) $(TARGET_TEST_CPP_1_ST_R)
	@-$(RM) $(TARGET_TEST_CPP_2_ST_R)
	@-$(RM) $(OBJ_TEST_C_1_MT_D)
	@-$(RM) $(OBJ_TEST_C_1_DLL_D)
	@-$(RM) $(OBJ_TEST_C_1_DLL_R)
	@-$(RM) $(OBJ_TEST_C_1_MT_R)
	@-$(RM) $(OBJ_TEST_C_1_ST_D)
	@-$(RM) $(OBJ_TEST_C_1_ST_R)
	@-$(RM) $(OBJ_TEST_CPP_1_MT_D)
	@-$(RM) $(OBJ_TEST_CPP_2_MT_D)
	@-$(RM) $(OBJ_TEST_CPP_1_DLL_D)
	@-$(RM) $(OBJ_TEST_CPP_2_DLL_D)
	@-$(RM) $(OBJ_TEST_CPP_1_DLL_R)
	@-$(RM) $(OBJ_TEST_CPP_2_DLL_R)
	@-$(RM) $(OBJ_TEST_CPP_1_MT_R)
	@-$(RM) $(OBJ_TEST_CPP_2_MT_R)
	@-$(RM) $(OBJ_TEST_CPP_1_ST_D)
	@-$(RM) $(OBJ_TEST_CPP_2_ST_D)
	@-$(RM) $(OBJ_TEST_CPP_1_ST_R)
	@-$(RM) $(OBJ_TEST_CPP_2_ST_R)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_ST_R)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_MT_D)
	@-$(RM) $(TARGET_SAMPLE_C_2_MT_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_DLL_D)
	@-$(RM) $(TARGET_SAMPLE_C_2_DLL_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_DLL_R)
	@-$(RM) $(TARGET_SAMPLE_C_2_DLL_R)
	@-$(RM) $(TARGET_SAMPLE_C_1_MT_R)
	@-$(RM) $(TARGET_SAMPLE_C_2_MT_R)
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_MT_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_MT_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_DLL_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_DLL_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_DLL_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_DLL_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_MT_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_MT_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_ST_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_ST_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_ST_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_MT_D)
	@-$(RM) $(OBJ_SAMPLE_C_2_MT_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_DLL_D)
	@-$(RM) $(OBJ_SAMPLE_C_2_DLL_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_DLL_R)
	@-$(RM) $(OBJ_SAMPLE_C_2_DLL_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_MT_R)
	@-$(RM) $(OBJ_SAMPLE_C_2_MT_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_MT_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_MT_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_DLL_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_DLL_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_DLL_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_DLL_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_MT_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_MT_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_ST_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_ST_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_ST_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_ST_R)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_MT_D): $(TARGET_LIB_MT_D)
	@$(CP) $(TARGET_LIB_MT_D) $@

$(TARGET_LIB_MT_D): $(OBJS_CORE_MT_D) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_D)

$(OBJ_CORE_matches__MT_D): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__MT_D): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__MT_D): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


$(TARGET_LIB_UN_DLL_D): $(TARGET_LIB_DLL_D)
	@$(CP) $(TARGET_LIB_DLL_D) $@

$(TARGET_LIB_DLL_D): $(OBJS_CORE_DLL_D) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_DLL_D)

$(OBJ_CORE_matches__DLL_D): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__DLL_D): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__DLL_D): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


$(TARGET_LIB_UN_DLL_R): $(TARGET_LIB_DLL_R)
	@$(CP) $(TARGET_LIB_DLL_R) $@

$(TARGET_LIB_DLL_R): $(OBJS_CORE_DLL_R) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_DLL_R)

$(OBJ_CORE_matches__DLL_R): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__DLL_R): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__DLL_R): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


$(TARGET_LIB_UN_MT_R): $(TARGET_LIB_MT_R)
	@$(CP) $(TARGET_LIB_MT_R) $@

$(TARGET_LIB_MT_R): $(OBJS_CORE_MT_R) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_R)

$(OBJ_CORE_matches__MT_R): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__MT_R): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__MT_R): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


$(TARGET_LIB_UN_ST_D): $(TARGET_LIB_ST_D)
	@$(CP) $(TARGET_LIB_ST_D) $@

$(TARGET_LIB_ST_D): $(OBJS_CORE_ST_D) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_ST_D)

$(OBJ_CORE_matches__ST_D): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__ST_D): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__ST_D): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


$(TARGET_LIB_UN_ST_R): $(TARGET_LIB_ST_R)
	@$(CP) $(TARGET_LIB_ST_R) $@

$(TARGET_LIB_ST_R): $(OBJS_CORE_ST_R) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_ST_R)

$(OBJ_CORE_matches__ST_R): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__ST_R): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__ST_R): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


########################################
# test

# C test client

$(TARGET_TEST_C_1_MT_D):	$(OBJ_TEST_C_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D_TEST) -out:$@ $(OBJ_TEST_C_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D_TEST)

$(OBJ_TEST_C_1_MT_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D_TEST) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_DLL_D):	$(OBJ_TEST_C_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D_TEST) -out:$@ $(OBJ_TEST_C_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D_TEST)

$(OBJ_TEST_C_1_DLL_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D_TEST) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_DLL_R):	$(OBJ_TEST_C_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R_TEST) -out:$@ $(OBJ_TEST_C_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R_TEST)

$(OBJ_TEST_C_1_DLL_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R_TEST) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_MT_R):	$(OBJ_TEST_C_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R_TEST) -out:$@ $(OBJ_TEST_C_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R_TEST)

$(OBJ_TEST_C_1_MT_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R_TEST) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_ST_D):	$(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D_TEST) -out:$@ $(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D_TEST)

$(OBJ_TEST_C_1_ST_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D_TEST) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_ST_R):	$(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R_TEST) -out:$@ $(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R_TEST)

$(OBJ_TEST_C_1_ST_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R_TEST) -Fo$@ $(SRC_TEST_C_1)

# C++ test client

$(TARGET_TEST_CPP_1_MT_D):	$(OBJ_TEST_CPP_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D_TEST) -out:$@ $(OBJ_TEST_CPP_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D_TEST)

$(OBJ_TEST_CPP_1_MT_D):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D_TEST) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_MT_D):	$(OBJ_TEST_CPP_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D_TEST) -out:$@ $(OBJ_TEST_CPP_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D_TEST)

$(OBJ_TEST_CPP_2_MT_D):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D_TEST) -Fo$@ $(SRC_TEST_CPP_2)

$(TARGET_TEST_CPP_1_DLL_D):	$(OBJ_TEST_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D_TEST) -out:$@ $(OBJ_TEST_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D_TEST)

$(OBJ_TEST_CPP_1_DLL_D):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D_TEST) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_DLL_D):	$(OBJ_TEST_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D_TEST) -out:$@ $(OBJ_TEST_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D_TEST)

$(OBJ_TEST_CPP_2_DLL_D):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D_TEST) -Fo$@ $(SRC_TEST_CPP_2)

$(TARGET_TEST_CPP_1_DLL_R):	$(OBJ_TEST_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R_TEST) -out:$@ $(OBJ_TEST_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R_TEST)

$(OBJ_TEST_CPP_1_DLL_R):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R_TEST) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_DLL_R):	$(OBJ_TEST_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R_TEST) -out:$@ $(OBJ_TEST_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R_TEST)

$(OBJ_TEST_CPP_2_DLL_R):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R_TEST) -Fo$@ $(SRC_TEST_CPP_2)

$(TARGET_TEST_CPP_1_MT_R):	$(OBJ_TEST_CPP_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R_TEST) -out:$@ $(OBJ_TEST_CPP_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R_TEST)

$(OBJ_TEST_CPP_1_MT_R):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R_TEST) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_MT_R):	$(OBJ_TEST_CPP_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R_TEST) -out:$@ $(OBJ_TEST_CPP_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R_TEST)

$(OBJ_TEST_CPP_2_MT_R):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R_TEST) -Fo$@ $(SRC_TEST_CPP_2)

$(TARGET_TEST_CPP_1_ST_D):	$(OBJ_TEST_CPP_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D_TEST) -out:$@ $(OBJ_TEST_CPP_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D_TEST)

$(OBJ_TEST_CPP_1_ST_D):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D_TEST) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_ST_D):	$(OBJ_TEST_CPP_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D_TEST) -out:$@ $(OBJ_TEST_CPP_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D_TEST)

$(OBJ_TEST_CPP_2_ST_D):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D_TEST) -Fo$@ $(SRC_TEST_CPP_2)

$(TARGET_TEST_CPP_1_ST_R):	$(OBJ_TEST_CPP_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R_TEST) -out:$@ $(OBJ_TEST_CPP_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R_TEST)

$(OBJ_TEST_CPP_1_ST_R):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R_TEST) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_ST_R):	$(OBJ_TEST_CPP_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R_TEST) -out:$@ $(OBJ_TEST_CPP_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R_TEST)

$(OBJ_TEST_CPP_2_ST_R):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R_TEST) -Fo$@ $(SRC_TEST_CPP_2)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_MT_D):	$(OBJ_EXAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_C_1_MT_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_MT_D):	$(OBJ_EXAMPLE_C_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_C_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_C_2_MT_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_DLL_D):	$(OBJ_EXAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_C_1_DLL_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_DLL_D):	$(OBJ_EXAMPLE_C_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_C_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_C_2_DLL_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_DLL_R):	$(OBJ_EXAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_C_1_DLL_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_DLL_R):	$(OBJ_EXAMPLE_C_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_C_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_C_2_DLL_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_MT_R):	$(OBJ_EXAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_C_1_MT_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_MT_R):	$(OBJ_EXAMPLE_C_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_C_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_C_2_MT_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_ST_D):	$(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_1_ST_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_D):	$(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_2_ST_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_ST_R):	$(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_1_ST_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_R):	$(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_2_ST_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -Fo$@ $(SRC_EXAMPLE_C_2)

# C++ example client

$(TARGET_EXAMPLE_CPP_1_MT_D):	$(OBJ_EXAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_CPP_1_MT_D):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_MT_D):	$(OBJ_EXAMPLE_CPP_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_CPP_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_CPP_2_MT_D):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_DLL_D):	$(OBJ_EXAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_CPP_1_DLL_D):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_DLL_D):	$(OBJ_EXAMPLE_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_CPP_2_DLL_D):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_DLL_R):	$(OBJ_EXAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_CPP_1_DLL_R):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_DLL_R):	$(OBJ_EXAMPLE_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_CPP_2_DLL_R):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_MT_R):	$(OBJ_EXAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_CPP_1_MT_R):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_MT_R):	$(OBJ_EXAMPLE_CPP_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_CPP_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_CPP_2_MT_R):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_ST_D):	$(OBJ_EXAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_EXAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_CPP_1_ST_D):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_ST_D):	$(OBJ_EXAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_EXAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_CPP_2_ST_D):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_ST_R):	$(OBJ_EXAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_EXAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_CPP_1_ST_R):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_ST_R):	$(OBJ_EXAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_EXAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_CPP_2_ST_R):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(SRC_EXAMPLE_CPP_2)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_MT_D):	$(OBJ_SAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_SAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_SAMPLE_C_1_MT_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_MT_D):	$(OBJ_SAMPLE_C_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_SAMPLE_C_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_SAMPLE_C_2_MT_D):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_DLL_D):	$(OBJ_SAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_SAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_SAMPLE_C_1_DLL_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_DLL_D):	$(OBJ_SAMPLE_C_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_SAMPLE_C_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_SAMPLE_C_2_DLL_D):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_DLL_R):	$(OBJ_SAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_SAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_SAMPLE_C_1_DLL_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_DLL_R):	$(OBJ_SAMPLE_C_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_SAMPLE_C_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_SAMPLE_C_2_DLL_R):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_MT_R):	$(OBJ_SAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_SAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_SAMPLE_C_1_MT_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_MT_R):	$(OBJ_SAMPLE_C_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_SAMPLE_C_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_SAMPLE_C_2_MT_R):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_ST_D):	$(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_1_ST_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_D):	$(OBJ_SAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_SAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_2_ST_D):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -Fo$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_ST_R):	$(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_1_ST_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_R):	$(OBJ_SAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_SAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_2_ST_R):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -Fo$@ $(SRC_SAMPLE_C_2)

# C++ sample client

$(TARGET_SAMPLE_CPP_1_MT_D):	$(OBJ_SAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_SAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_SAMPLE_CPP_1_MT_D):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_MT_D):	$(OBJ_SAMPLE_CPP_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_SAMPLE_CPP_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_SAMPLE_CPP_2_MT_D):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_SAMPLE_CPP_2)

$(TARGET_SAMPLE_CPP_1_DLL_D):	$(OBJ_SAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_SAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_SAMPLE_CPP_1_DLL_D):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_DLL_D):	$(OBJ_SAMPLE_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_SAMPLE_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_SAMPLE_CPP_2_DLL_D):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_SAMPLE_CPP_2)

$(TARGET_SAMPLE_CPP_1_DLL_R):	$(OBJ_SAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_SAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_SAMPLE_CPP_1_DLL_R):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_DLL_R):	$(OBJ_SAMPLE_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_SAMPLE_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_SAMPLE_CPP_2_DLL_R):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_SAMPLE_CPP_2)

$(TARGET_SAMPLE_CPP_1_MT_R):	$(OBJ_SAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_SAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_SAMPLE_CPP_1_MT_R):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_MT_R):	$(OBJ_SAMPLE_CPP_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_SAMPLE_CPP_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_SAMPLE_CPP_2_MT_R):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_SAMPLE_CPP_2)

$(TARGET_SAMPLE_CPP_1_ST_D):	$(OBJ_SAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_SAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_CPP_1_ST_D):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_ST_D):	$(OBJ_SAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -out:$@ $(OBJ_SAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_CPP_2_ST_D):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -Fo$@ $(SRC_SAMPLE_CPP_2)

$(TARGET_SAMPLE_CPP_1_ST_R):	$(OBJ_SAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_SAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_CPP_1_ST_R):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_ST_R):	$(OBJ_SAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -out:$@ $(OBJ_SAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_CPP_2_ST_R):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -Fo$@ $(SRC_SAMPLE_CPP_2)

################################################################################
