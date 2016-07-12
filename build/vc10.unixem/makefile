############################################################################
# File:     makefile
#
# Purpose:  Makefile for the shwild project, for the Visual C++ 10.0 (x86 UNIXem)
#           compiler, on UNIX
#
# Created:  15th February 2005
# Updated:  11th July 2006
#
############################################################################


############################################################################
# environment check

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT
!ifndef PTHREADS_WIN32
!error PTHREADS_WIN32 must be defined
!endif # !PTHREADS_WIN32
!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM


############################################################################
# symbols

########################################
# project & compiler version

COMP_TAG            =   vc10
ARCH_TAG            =   
OS_TAG              =   .unix
PROJ_TAG            =   shwild
PROJ_VER_MAJOR      =   0
PROJ_MOD_TAG        =   core
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR).$(PROJ_MOD_TAG)
COMP_ARCH_OS_TAG    =   $(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

########################################
# dependencies

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

UNIXEM_VER_MAJOR    =   1
UNIXEM_TAG_VER      =   unixem.$(UNIXEM_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# testing verbosity

TEST_VERBOSITY      =   2


############################################################################
# directories

########################################
# project directories

PROJ_BASE_DIR           =   ..\..
PROJ_BIN_DIR            =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR        =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR            =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR            =   .
PROJ_SRC_DIR            =   $(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR       =   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR        =   $(PROJ_BASE_DIR)\samples
PROJ_TEST_ROOT_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR =   $(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_SCRATCH_DIR   =   $(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR      =   $(PROJ_TEST_ROOT_DIR)\unit

########################################
# 3rd-party directories

XTESTS_PROJ_INCLUDE		=	
!ifdef SHWILD_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR		=   $(SHWILD_XTESTS_BASE_DIR)\include
XTESTS_SRC_DIR			=   $(SHWILD_XTESTS_BASE_DIR)\src
XTESTS_PROJ_INCLUDE		=	-I$(XTESTS_INCLUDE_DIR)
!else
XTESTS_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR			=   $(PROJ_SRC_DIR)\xtests
!endif # !SHWILD_XTESTS_BASE_DIR

############################################################################
# tools

CC                      =   cl
CPPC                    =   cl
AR                      =   lib
LD                      =   link
RM                      =   del /f
CP                      =   copy
RC                      =   rc

############################################################
# compiler

########################################
# includes

INCLUDES_LEADER         =   

PROJ_INCLUDE            =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES         =   -I$(SYNESIS_DEV)/include -I$(SYNESIS_DEV)/libraries/include

STLSOFT_INCLUDES		=\
 -I"$(STLSOFT)\include"\
 \

THIRDPARTY_INCLUDES		=\
 $(XTESTS_PROJ_INCLUDE)\
 -I"$(PTHREADS_WIN32)\include"\
 -I"$(UNIXEM)\include"\
 \

# CC

CC_INCLUDES_BASE =\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 $(THIRDPARTY_INCLUDES)\
 \

CC_INCLUDES_MT_UX =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_UX_DEBUG =\
 $(CC_INCLUDES_BASE)\
 \


CC_SHWILD_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_UX =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_UX_DEBUG =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_XTESTS_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_UX =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_UX_DEBUG =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \


CC_INCLUDES_TEST=\
 $(CC_INCLUDES_BASE)\
 -I"$(OPENRJ_ROOT)\include"\
 \

# CPPC

CPPC_INCLUDES_BASE =\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 $(THIRDPARTY_INCLUDES)\
 \

CPPC_INCLUDES_MT_UX =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_MT_UX_DEBUG =\
 $(CPPC_INCLUDES_BASE)\
 \


CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_UX =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_UX_DEBUG =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_UX =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_UX_DEBUG =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \


CPPC_INCLUDES_TEST=\
 $(CPPC_INCLUDES_BASE)\
 -I"$(OPENRJ_ROOT)\include"\
 \

########################################
# defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DSHWILD_NO_IMPLICIT_LINK\
 \

COMMON_DEFS             =   -DUNIX

CUSTOM_DEFS             =

# CC

CC_CUSTOM_DEFS          =   $(CUSTOM_DEFS)

CC_DEFS_BASE =\
 $(CC_CUSTOM_DEFS)\
 $(COMMON_DEFS)\
 \

CC_DEFS_MT_UX =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_UX_DEBUG =\
 $(CC_DEFS_BASE)\
 \


# CPPC

CPPC_CUSTOM_DEFS        =   $(CUSTOM_DEFS)

CPPC_DEFS_BASE =\
 $(CPPC_CUSTOM_DEFS)\
 $(COMMON_DEFS)\
 \

CPPC_DEFS_MT_UX =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_MT_UX_DEBUG =\
 $(CPPC_DEFS_BASE)\
 \


########################################
# flags

# CC

CC_F_NOLOGO             =   -nologo
CC_F_COMPILE_ONLY       =   -c
CC_F_FORCE_INCLUDE      =   
CC_F_WARNING_MAX        =   -W4
CC_F_WARNING_ERR        =   -WX
CC_F_MINIMUM_SIZE       =   -O1
CC_F_MAXIMUM_SPEED      =   -O2

CC_TOOL_FLAGS       =   

CC_FLAGS_BASE =\
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_FORCE_INCLUDE)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_MT_UX =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_UX_DEBUG =\
 $(CC_FLAGS_BASE)\
 \


# CPPC

CPPC_F_NOLOGO           =   -nologo
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_FORCE_INCLUDE    =   
CPPC_F_WARNING_MAX      =   -W4
CPPC_F_WARNING_ERR      =   -WX
CPPC_F_EXCEPTIONS_ON    =   -EHsc
CPPC_F_EXCEPTIONS_OFF   =   -wd4530
CPPC_F_EXCEPTIONS       =   
CPPC_F_RTTI_ON          =   -GR
CPPC_F_RTTI_OFF         =   -GR-
CPPC_F_RTTI             =   
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED    =   -O2

CPPC_TOOL_FLAGS     =   

CPPC_FLAGS_BASE =\
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_FORCE_INCLUDE)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_UX =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_UX_DEBUG =\
 $(CPPC_FLAGS_BASE)\
 \


########################################
# arguments

# CC args (= flags + defines + includes)

CC_ARGS_MT_UX=\
 $(CC_FLAGS_MT_UX)\
 $(CPPC_F_WITH_EXCEPTIONS) -MT -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER\
 $(CC_DEFS_MT_UX)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_MT_UX)
CC_ARGS_MT_UX_TEST=\
 $(CC_FLAGS_MT_UX)\
 $(CPPC_F_WITH_EXCEPTIONS) -MT -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER\
 $(CC_DEFS_MT_UX)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_TEST)
CC_ARGS_MT_UX_DEBUG=\
 $(CC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_F_WITH_EXCEPTIONS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb\
 $(CC_DEFS_MT_UX_DEBUG)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_MT_UX_DEBUG)
CC_ARGS_MT_UX_DEBUG_TEST=\
 $(CC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_F_WITH_EXCEPTIONS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb\
 $(CC_DEFS_MT_UX_DEBUG)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_TEST)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_UX=\
 $(CPPC_FLAGS_MT_UX)\
 $(CPPC_F_WITH_EXCEPTIONS) -MT -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER\
 $(CPPC_DEFS_MT_UX)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_MT_UX)
CPPC_ARGS_MT_UX_TEST=\
 $(CPPC_FLAGS_MT_UX)\
 $(CPPC_F_WITH_EXCEPTIONS) -MT -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER\
 $(CPPC_DEFS_MT_UX)\
 $(CPPC_INCLUDES_TEST)
CPPC_ARGS_MT_UX_DEBUG=\
 $(CPPC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_F_WITH_EXCEPTIONS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb\
 $(CPPC_DEFS_MT_UX_DEBUG)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_MT_UX_DEBUG)
CPPC_ARGS_MT_UX_DEBUG_TEST=\
 $(CPPC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_F_WITH_EXCEPTIONS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb\
 $(CPPC_DEFS_MT_UX_DEBUG)\
 $(CPPC_INCLUDES_TEST)

############################################################
# archiver

AR_F_NOLOGO             =   -nologo

AR_ARGS                 =   -nologo

############################################################
# linker

########################################
# flags

LD_F_NOLOGO             =   -nologo

LD_FLAGS_BASE           =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_UX =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_UX_DEBUG =\
 $(LD_FLAGS_BASE)\
 \


########################################
# paths

LIBPATHS_ENV            =

LIBPATHS_COMMON         =   -libpath:$(SYNESIS_DEV)/lib 

LIBPATHS_3PTY           =\
 -libpath:"$(PTHREADS_WIN32)\lib"\
 -libpath:"$(UNIXEM)\lib"\
 \

LIBPATHS=\
 $(LIBPATHS_COMMON)\
 $(LIBPATHS_3PTY)\
 $(LIBPATHS_ENV)\
 \

LIBPATHS_TEST =\
 $(LIBPATHS)\
 -libpath:$(OPENRJ_ROOT)\lib\
 \

########################################
# arguments

LD_ARGS_MT_UX      =   libWinSysLog.$(COMP_TAG).mt.lib unixem.1.$(COMP_TAG).mt.lib -release $(LD_F_NOLOGO) $(LIBPATHS)
LD_ARGS_MT_UX_TEST =   libWinSysLog.$(COMP_TAG).mt.lib unixem.1.$(COMP_TAG).mt.lib -release $(LD_F_NOLOGO) $(LIBPATHS_TEST)
LD_ARGS_MT_UX_DEBUG      =   libWinSysLog.$(COMP_TAG).mt.debug.lib unixem.1.$(COMP_TAG).mt.debug.lib -debug $(LD_F_NOLOGO) $(LIBPATHS)
LD_ARGS_MT_UX_DEBUG_TEST =   libWinSysLog.$(COMP_TAG).mt.debug.lib unixem.1.$(COMP_TAG).mt.debug.lib -debug $(LD_F_NOLOGO) $(LIBPATHS_TEST)

############################################################################
# names

############################################################
# source

SRCS_HDR_CORE=\
 $(PROJ_INCLUDE_DIR)\shwild\shwild.h\
 $(PROJ_INCLUDE_DIR)\shwild\implicit_link.h\
 \

SRCS_HDR_MAPPING=\
 $(PROJ_INCLUDE_DIR)\shwild\shwild.hpp\
 \

############################################################
# objects / program-databases

########################################
# libraries

# core

OBJ_CORE_matches__MT_UX    =   $(PROJ_OBJ_DIR)\core.matches.mt.obj
OBJ_CORE_pattern__MT_UX    =   $(PROJ_OBJ_DIR)\core.pattern.mt.obj
OBJ_CORE_api__MT_UX        =   $(PROJ_OBJ_DIR)\core.api.mt.obj

OBJS_CORE_MT_UX =\
 $(OBJ_CORE_matches__MT_UX)\
 $(OBJ_CORE_pattern__MT_UX)\
 $(OBJ_CORE_api__MT_UX)\
 \

OBJ_CORE_matches__MT_UX_DEBUG    =   $(PROJ_OBJ_DIR)\core.matches.mt.debug.obj
OBJ_CORE_pattern__MT_UX_DEBUG    =   $(PROJ_OBJ_DIR)\core.pattern.mt.debug.obj
OBJ_CORE_api__MT_UX_DEBUG        =   $(PROJ_OBJ_DIR)\core.api.mt.debug.obj

OBJS_CORE_MT_UX_DEBUG =\
 $(OBJ_CORE_matches__MT_UX_DEBUG)\
 $(OBJ_CORE_pattern__MT_UX_DEBUG)\
 $(OBJ_CORE_api__MT_UX_DEBUG)\
 \

OBJS_CORE =\
 $(OBJS_CORE_MT_UX)\
 $(OBJS_CORE_MT_UX_DEBUG)\
 \

# xTests - testing only

OBJ_xt_core_MT_UX         =   $(PROJ_OBJ_DIR)\xtests.core.mt.obj

OBJS_XTESTS_MT_UX=\
 $(OBJ_xt_core_MT_UX)\
 \

OBJ_xt_core_MT_UX_DEBUG         =   $(PROJ_OBJ_DIR)\xtests.core.mt.debug.obj
PDB_xt_core_MT_UX_DEBUG         =   $(PROJ_OBJ_DIR)\xtests.core.mt.debug.pdb

OBJS_XTESTS_MT_UX_DEBUG=\
 $(OBJ_xt_core_MT_UX_DEBUG)\
 \

PDBS_XTESTS_MT_UX_DEBUG=\
 $(PDB_xt_core_MT_UX_DEBUG)\
 \


OBJS_XTESTS=\
 $(OBJS_XTESTS_MT_UX)\
 $(OBJS_XTESTS_MT_UX_DEBUG)\
 \

# *

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# examples

OBJ_EXAMPLE_C_1_MT_UX = $(PROJ_OBJ_DIR)\example_c_1.mt.obj
OBJ_EXAMPLE_C_2_MT_UX = $(PROJ_OBJ_DIR)\example_c_2.mt.obj
OBJ_EXAMPLE_CPP_1_MT_UX = $(PROJ_OBJ_DIR)\example_cpp_1.mt.obj
OBJ_EXAMPLE_CPP_2_MT_UX = $(PROJ_OBJ_DIR)\example_cpp_2.mt.obj
OBJ_EXAMPLE_C_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\example_c_1.mt.debug.obj
OBJ_EXAMPLE_C_2_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\example_c_2.mt.debug.obj
OBJ_EXAMPLE_CPP_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\example_cpp_1.mt.debug.obj
OBJ_EXAMPLE_CPP_2_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\example_cpp_2.mt.debug.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_MT_UX)\
 $(OBJ_EXAMPLE_C_2_MT_UX)\
 $(OBJ_EXAMPLE_C_1_MT_UX_DEBUG)\
 $(OBJ_EXAMPLE_C_2_MT_UX_DEBUG)\
 $(OBJ_EXAMPLE_CPP_1_MT_UX)\
 $(OBJ_EXAMPLE_CPP_2_MT_UX)\
 $(OBJ_EXAMPLE_CPP_1_MT_UX_DEBUG)\
 $(OBJ_EXAMPLE_CPP_2_MT_UX_DEBUG)\
 \

########################################
# samples

OBJ_SAMPLE_C_1_MT_UX = $(PROJ_OBJ_DIR)\sample_c_1.mt.obj
OBJ_SAMPLE_C_2_MT_UX = $(PROJ_OBJ_DIR)\sample_c_2.mt.obj
OBJ_SAMPLE_CPP_1_MT_UX = $(PROJ_OBJ_DIR)\sample_cpp_1.mt.obj
OBJ_SAMPLE_CPP_2_MT_UX = $(PROJ_OBJ_DIR)\sample_cpp_2.mt.obj
OBJ_SAMPLE_C_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\sample_c_1.mt.debug.obj
OBJ_SAMPLE_C_2_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\sample_c_2.mt.debug.obj
OBJ_SAMPLE_CPP_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\sample_cpp_1.mt.debug.obj
OBJ_SAMPLE_CPP_2_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\sample_cpp_2.mt.debug.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_MT_UX)\
 $(OBJ_SAMPLE_C_2_MT_UX)\
 $(OBJ_SAMPLE_C_1_MT_UX_DEBUG)\
 $(OBJ_SAMPLE_C_2_MT_UX_DEBUG)\
 $(OBJ_SAMPLE_CPP_1_MT_UX)\
 $(OBJ_SAMPLE_CPP_2_MT_UX)\
 $(OBJ_SAMPLE_CPP_1_MT_UX_DEBUG)\
 $(OBJ_SAMPLE_CPP_2_MT_UX_DEBUG)\
 \

########################################
# tests

OBJ_TEST_C_1_MT_UX = $(PROJ_OBJ_DIR)\test_c_1.mt.obj
OBJ_TEST_CPP_1_MT_UX = $(PROJ_OBJ_DIR)\test_cpp_1.mt.obj
OBJ_TEST_CPP_2_MT_UX = $(PROJ_OBJ_DIR)\test_cpp_2.mt.obj
OBJ_TEST_C_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\test_c_1.mt.debug.obj
OBJ_TEST_CPP_1_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\test_cpp_1.mt.debug.obj
OBJ_TEST_CPP_2_MT_UX_DEBUG = $(PROJ_OBJ_DIR)\test_cpp_2.mt.debug.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_MT_UX)\
 $(OBJ_TEST_C_1_MT_UX_DEBUG)\
 $(OBJ_TEST_CPP_1_MT_UX)\
 $(OBJ_TEST_CPP_2_MT_UX)\
 $(OBJ_TEST_CPP_1_MT_UX_DEBUG)\
 $(OBJ_TEST_CPP_2_MT_UX_DEBUG)\
 \

########################################
# OBJS

OBJS =\
 $(OBJS_LIBS)\
 \
 $(OBJS_EXAMPLES)\
 $(OBJS_SAMPLES)\
 $(OBJS_TESTS)\
 \

############################################################################
# targets

########################################
# libraries

# core

LIB_CORE_MT_UX                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_UN_MT_UX              =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_MT_UX_DEBUG                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_CORE_UN_MT_UX_DEBUG              =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_ARCH_OS_TAG).mt.debug.lib
TARGET_PDB_MT_UX_DEBUG               =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.pdb

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_UX)\
 $(LIB_CORE_UN_MT_UX)\
 $(LIB_CORE_MT_UX_DEBUG)\
 $(LIB_CORE_UN_MT_UX_DEBUG)\
 \

# xCover

LIB_XCOVER_MT_UX               =
LIB_XCOVER_MT_UX_DEBUG               =
TARGETS_LIB_XCOVER                          =
# xTests - testing only

LIB_XTESTS_MT_UX               =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).shw.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_MT_UX_DEBUG               =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).shw.$(COMP_ARCH_OS_TAG).mt.debug.lib

TARGETS_LIB_XTESTS=\
 $(LIB_XTESTS_MT_UX)\
 $(LIB_XTESTS_MT_UX_DEBUG)\
 \

# *

TARGETS_LIB_ALL=\
 $(TARGETS_LIB_CORE)\
 \

TARGETS_LIBS=\
 $(TARGETS_LIB_CORE)\
 $(TARGETS_LIB_XCOVER)\
 $(TARGETS_LIB_XTESTS)\
 \

########################################
# examples

TARGET_EXAMPLE_C_1_MT_UX   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_EXAMPLE_C_2_MT_UX   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_EXAMPLE_CPP_1_MT_UX =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_EXAMPLE_CPP_2_MT_UX =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_EXAMPLE_C_1_MT_UX_DEBUG   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_EXAMPLE_C_2_MT_UX_DEBUG   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_EXAMPLE_CPP_1_MT_UX_DEBUG =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_EXAMPLE_CPP_2_MT_UX_DEBUG =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_ARCH_OS_TAG).mt.debug.exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_MT_UX)\
 $(TARGET_EXAMPLE_C_2_MT_UX)\
 $(TARGET_EXAMPLE_CPP_1_MT_UX)\
 $(TARGET_EXAMPLE_CPP_2_MT_UX)\
 $(TARGET_EXAMPLE_C_1_MT_UX_DEBUG)\
 $(TARGET_EXAMPLE_C_2_MT_UX_DEBUG)\
 $(TARGET_EXAMPLE_CPP_1_MT_UX_DEBUG)\
 $(TARGET_EXAMPLE_CPP_2_MT_UX_DEBUG)\
 \

########################################
# samples

TARGET_SAMPLE_C_1_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_SAMPLE_C_2_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_SAMPLE_CPP_1_MT_UX  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_SAMPLE_CPP_2_MT_UX  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_SAMPLE_C_1_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_SAMPLE_C_2_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_SAMPLE_CPP_1_MT_UX_DEBUG  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_SAMPLE_CPP_2_MT_UX_DEBUG  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_ARCH_OS_TAG).mt.debug.exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_MT_UX)\
 $(TARGET_SAMPLE_C_2_MT_UX)\
 $(TARGET_SAMPLE_CPP_1_MT_UX)\
 $(TARGET_SAMPLE_CPP_2_MT_UX)\
 $(TARGET_SAMPLE_C_1_MT_UX_DEBUG)\
 $(TARGET_SAMPLE_C_2_MT_UX_DEBUG)\
 $(TARGET_SAMPLE_CPP_1_MT_UX_DEBUG)\
 $(TARGET_SAMPLE_CPP_2_MT_UX_DEBUG)\
 \

########################################
# tests

TARGET_TEST_C_1_MT_UX      =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_TEST_CPP_1_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_TEST_CPP_2_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_ARCH_OS_TAG).mt.exe
TARGET_TEST_C_1_MT_UX_DEBUG      =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_TEST_CPP_1_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARGET_TEST_CPP_2_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_ARCH_OS_TAG).mt.debug.exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_MT_UX)\
 $(TARGET_TEST_CPP_1_MT_UX)\
 $(TARGET_TEST_CPP_2_MT_UX)\
 $(TARGET_TEST_C_1_MT_UX_DEBUG)\
 $(TARGET_TEST_CPP_1_MT_UX_DEBUG)\
 $(TARGET_TEST_CPP_2_MT_UX_DEBUG)\
 \

########################################
# TARGETS

TARGETS =\
 $(TARGETS_LIBS)\
 \
 $(TARGETS_TESTS)\
 $(TARGETS_EXAMPLES)\
 $(TARGETS_SAMPLES)\
 \

############################################################
# libs

LIBS_EXPLICIT_MT_UX =\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib pthreadVC.lib \
 \

LIBS_EXPLICIT_MT_UX_DEBUG =\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib pthreadVC.lib \
 \


LIBS_3PTY_MT_UX =\
 \

LIBS_3PTY_MT_UX_TEST =\
 $(LIBS_3PTY_MT_UX)\
 openrj.1.$(COMP_ARCH_OS_TAG).mt.lib\
 \

LIBS_3PTY_MT_UX_DEBUG =\
 \

LIBS_3PTY_MT_UX_DEBUG_TEST =\
 $(LIBS_3PTY_MT_UX_DEBUG)\
 openrj.1.$(COMP_ARCH_OS_TAG).mt.debug.lib\
 \


LIBS_EXAMPLES_MT_UX=\
 $(LIB_CORE_MT_UX)\
 \


LIBS_EXAMPLES_MT_UX_DEBUG=\
 $(LIB_CORE_MT_UX_DEBUG)\
 \


LIBS_SAMPLES_MT_UX=\
 $(LIB_CORE_MT_UX)\
 \


LIBS_SAMPLES_MT_UX_DEBUG=\
 $(LIB_CORE_MT_UX_DEBUG)\
 \


LIBS_TESTS_MT_UX=\
 $(LIB_CORE_MT_UX)\
 $(LIB_XTESTS_MT_UX)\
 \


LIBS_TESTS_MT_UX_DEBUG=\
 $(LIB_CORE_MT_UX_DEBUG)\
 $(LIB_XTESTS_MT_UX_DEBUG)\
 \



############################################################################
# External Targets (invokable by make)

# primary

_default:					build

usage:
	@echo "make [usage | compile | build | test | clean] - default is 'build'"

# infrastructure

check.lib.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)


# compile targets

compile.libs.core:			$(PROJ_MAKEFILE_NAME)	$(OBJS_CORE)

compile.libs.shwild:								compile.libs.core

compile.libs:										compile.libs.core

compile.libs.xtests:		$(PROJ_MAKEFILE_NAME)	$(OBJS_XTESTS)

compile.libs.3pty:									compile.libs.xtests

compile.libs.all:                                   compile.libs compile.libs.3pty

compile.examples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_EXAMPLES)

compile.samples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_SAMPLES)

compile.test.component:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_COMPONENT)

compile.test.scratch:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_SCRATCH)

compile.test.unit:			$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_UNIT)

compile.test:										compile.test.unit compile.test.component compile.test.scratch

compile:											compile.libs compile.libs.3pty compile.test compile.examples compile.samples

compile.all:										compile




# build targets

build.libs.core:			check.lib.dir			$(TARGETS_LIB_CORE)

build.libs.shwild:									build.libs.core

build.libs:											build.libs.core

build.libs.xtests:			check.lib.dir			$(TARGETS_LIB_XTESTS)

build.libs.3pty:									build.libs.xtests

build.libs.all:										build.libs build.libs.3pty

build.examples:				check.bin.dir			$(TARGETS_EXAMPLES)

build.samples:				check.bin.dir			$(TARGETS_SAMPLES)

build.test.component:		check.bin.dir			$(TARGETS_TEST_COMPONENT)

build.test.scratch:			check.bin.dir			$(TARGETS_TEST_SCRATCH)

build.test.unit:			check.bin.dir			$(TARGETS_TEST_UNIT)

build.test:											build.test.unit build.test.component build.test.scratch

build:												build.libs build.test build.examples build.samples

build.all:											build build.libs.all



# test targets

test.component_:
	@echo Running Test:Component programs ...

test.scratch_:
	@echo Running Test:Scratch programs ...

test.unit_:
	@echo Running Test:Unit programs ...

test.component:			$(PROJ_MAKEFILE_NAME)	build.test.component test.component_

test.scratch:			$(PROJ_MAKEFILE_NAME)	build.test.scratch test.scratch_

test.unit:				$(PROJ_MAKEFILE_NAME)	build.test.unit test.unit_

test:											test.unit test.component

test.all:										test test.scratch
test-all:				test.all


# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-if exist $(LIB_CORE_MT_UX) $(RM) $(LIB_CORE_MT_UX)
	@-if exist $(LIB_CORE_UN_MT_UX) $(RM) $(LIB_CORE_UN_MT_UX)
	@-if exist $(LIB_CORE_MT_UX_DEBUG) $(RM) $(LIB_CORE_MT_UX_DEBUG)
	@-if exist $(LIB_CORE_UN_MT_UX_DEBUG) $(RM) $(LIB_CORE_UN_MT_UX_DEBUG)
	@-if exist $(OBJS_CORE_MT_UX) $(RM) $(OBJS_CORE_MT_UX)
	@-if exist $(OBJS_CORE_MT_UX_DEBUG) $(RM) $(OBJS_CORE_MT_UX_DEBUG)
	@-if exist $(PDBS_CORE_MT_UX_DEBUG) $(RM) $(PDBS_CORE_MT_UX_DEBUG)

clean.libs.shwild:	clean.libs.core

clean.libs.xtests:
	@echo Cleaning xTests libraries ...
	@-if exist $(LIB_XTESTS_MT_UX) $(RM) $(LIB_XTESTS_MT_UX)
	@-if exist $(LIB_XTESTS_MT_UX_DEBUG) $(RM) $(LIB_XTESTS_MT_UX_DEBUG)
	@-if exist $(OBJ_shw_api_MT_UX) $(RM) $(OBJ_shw_api_MT_UX)
	@-if exist $(OBJ_shw_matches_MT_UX) $(RM) $(OBJ_shw_matches_MT_UX)
	@-if exist $(OBJ_shw_pattern_MT_UX) $(RM) $(OBJ_shw_pattern_MT_UX)
	@-if exist $(OBJ_shw_api_MT_UX_DEBUG) $(RM) $(OBJ_shw_api_MT_UX_DEBUG)
	@-if exist $(OBJ_shw_matches_MT_UX_DEBUG) $(RM) $(OBJ_shw_matches_MT_UX_DEBUG)
	@-if exist $(OBJ_shw_pattern_MT_UX_DEBUG) $(RM) $(OBJ_shw_pattern_MT_UX_DEBUG)
	@-if exist $(PDB_shw_api_MT_UX_DEBUG) $(RM) $(PDB_shw_api_MT_UX_DEBUG)
	@-if exist $(PDB_shw_matches_MT_UX_DEBUG) $(RM) $(PDB_shw_matches_MT_UX_DEBUG)
	@-if exist $(PDB_shw_pattern_MT_UX_DEBUG) $(RM) $(PDB_shw_pattern_MT_UX_DEBUG)

clean.test.component:
	@echo cleaning Test:Component programs ...

clean.test.scratch:
	@echo cleaning Test:Scratch programs ...

clean.test.unit:
	@echo cleaning Test:Unit programs ...

clean.libs: 									clean.libs.core

clean.libs.3pty:								clean.libs.xtests

clean.libs.all: 								clean.libs clean.libs.3pty

clean.examples:
	@echo cleaning example programs ...
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_UX_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_UX_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_UX_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_UX_DEBUG)
	@-$(RM) example_.*.obj
	@-if exist example_*.pdb $(RM) example_*.pdb

clean.samples:
	@echo cleaning sample programs ...
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_UX)
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_UX_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_UX_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_UX_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_UX_DEBUG)
	@-$(RM) sample_.*.obj
	@-if exist sample_*.pdb $(RM) sample_*.pdb

clean.test:										clean.test.component clean.test.scratch clean.test.unit

clean:					$(PROJ_MAKEFILE_NAME)	clean.libs.all clean.test clean.examples clean.samples

clean.all:										clean

############################################################################
# build targets

##################################################
# libraries

########################################
# xTests library - 'xtests.X.core.a'

$(LIB_XTESTS_MT_UX): $(OBJS_XTESTS_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_XTESTS_MT_UX)

$(OBJ_xt_core_MT_UX): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_XTESTS_INCLUDES_MT_UX) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_UX_DEBUG): $(OBJS_XTESTS_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_XTESTS_MT_UX_DEBUG)

$(OBJ_xt_core_MT_UX_DEBUG): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_XTESTS_INCLUDES_MT_UX_DEBUG) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

########################################
# core


$(LIB_CORE_UN_MT_UX): $(LIB_CORE_MT_UX)
	@$(CP) $(LIB_CORE_MT_UX) $@

$(LIB_CORE_MT_UX): $(OBJS_CORE_MT_UX) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_UX)

$(OBJ_CORE_matches__MT_UX): $(PROJ_SRC_DIR)\matches.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__MT_UX): $(PROJ_SRC_DIR)\pattern.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__MT_UX): $(PROJ_SRC_DIR)\api.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.cpp

$(TARGET_PDB_MT_UX_DEBUG):	$(LIB_CORE_MT_UX_DEBUG)

$(LIB_CORE_UN_MT_UX_DEBUG): $(LIB_CORE_MT_UX_DEBUG)
	@$(CP) $(LIB_CORE_MT_UX_DEBUG) $@

$(LIB_CORE_MT_UX_DEBUG): $(OBJS_CORE_MT_UX_DEBUG) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_UX_DEBUG)

$(OBJ_CORE_matches__MT_UX_DEBUG): $(PROJ_SRC_DIR)\matches.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__MT_UX_DEBUG): $(PROJ_SRC_DIR)\pattern.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.cpp


########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_MT_UX):	$(OBJ_EXAMPLE_C_1_MT_UX) $(LIBS_EXAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_EXAMPLE_C_1_MT_UX) $(LIBS_EXAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_EXAMPLE_C_1_MT_UX):	$(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARGET_EXAMPLE_C_2_MT_UX):	$(OBJ_EXAMPLE_C_2_MT_UX) $(LIBS_EXAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_EXAMPLE_C_2_MT_UX) $(LIBS_EXAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_EXAMPLE_C_2_MT_UX):	$(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARGET_EXAMPLE_C_1_MT_UX_DEBUG):	$(OBJ_EXAMPLE_C_1_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_EXAMPLE_C_1_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_EXAMPLE_C_1_MT_UX_DEBUG):	$(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARGET_EXAMPLE_C_2_MT_UX_DEBUG):	$(OBJ_EXAMPLE_C_2_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_EXAMPLE_C_2_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_EXAMPLE_C_2_MT_UX_DEBUG):	$(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

# C++ example client

$(TARGET_EXAMPLE_CPP_1_MT_UX):	$(OBJ_EXAMPLE_CPP_1_MT_UX) $(LIBS_EXAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_EXAMPLE_CPP_1_MT_UX) $(LIBS_EXAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_EXAMPLE_CPP_1_MT_UX):	$(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARGET_EXAMPLE_CPP_2_MT_UX):	$(OBJ_EXAMPLE_CPP_2_MT_UX) $(LIBS_EXAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_EXAMPLE_CPP_2_MT_UX) $(LIBS_EXAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_EXAMPLE_CPP_2_MT_UX):	$(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARGET_EXAMPLE_CPP_1_MT_UX_DEBUG):	$(OBJ_EXAMPLE_CPP_1_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_EXAMPLE_CPP_1_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_EXAMPLE_CPP_1_MT_UX_DEBUG):	$(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARGET_EXAMPLE_CPP_2_MT_UX_DEBUG):	$(OBJ_EXAMPLE_CPP_2_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_EXAMPLE_CPP_2_MT_UX_DEBUG) $(LIBS_EXAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_EXAMPLE_CPP_2_MT_UX_DEBUG):	$(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_MT_UX):	$(OBJ_SAMPLE_C_1_MT_UX) $(LIBS_SAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_SAMPLE_C_1_MT_UX) $(LIBS_SAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_SAMPLE_C_1_MT_UX):	$(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c

$(TARGET_SAMPLE_C_2_MT_UX):	$(OBJ_SAMPLE_C_2_MT_UX) $(LIBS_SAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_SAMPLE_C_2_MT_UX) $(LIBS_SAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_SAMPLE_C_2_MT_UX):	$(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c

$(TARGET_SAMPLE_C_1_MT_UX_DEBUG):	$(OBJ_SAMPLE_C_1_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_SAMPLE_C_1_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_SAMPLE_C_1_MT_UX_DEBUG):	$(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c

$(TARGET_SAMPLE_C_2_MT_UX_DEBUG):	$(OBJ_SAMPLE_C_2_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_SAMPLE_C_2_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_SAMPLE_C_2_MT_UX_DEBUG):	$(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c

# C++ sample client

$(TARGET_SAMPLE_CPP_1_MT_UX):	$(OBJ_SAMPLE_CPP_1_MT_UX) $(LIBS_SAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_SAMPLE_CPP_1_MT_UX) $(LIBS_SAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_SAMPLE_CPP_1_MT_UX):	$(PROJ_SAMPLES_DIR)\cpp\sample_cpp_1\sample_cpp_1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_1\sample_cpp_1.cpp

$(TARGET_SAMPLE_CPP_2_MT_UX):	$(OBJ_SAMPLE_CPP_2_MT_UX) $(LIBS_SAMPLES_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX) -out:$@ $(OBJ_SAMPLE_CPP_2_MT_UX) $(LIBS_SAMPLES_MT_UX) $(LIBS_3PTY_MT_UX) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_SAMPLE_CPP_2_MT_UX):	$(PROJ_SAMPLES_DIR)\cpp\sample_cpp_2\sample_cpp_2.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_2\sample_cpp_2.cpp

$(TARGET_SAMPLE_CPP_1_MT_UX_DEBUG):	$(OBJ_SAMPLE_CPP_1_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_SAMPLE_CPP_1_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_SAMPLE_CPP_1_MT_UX_DEBUG):	$(PROJ_SAMPLES_DIR)\cpp\sample_cpp_1\sample_cpp_1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_1\sample_cpp_1.cpp

$(TARGET_SAMPLE_CPP_2_MT_UX_DEBUG):	$(OBJ_SAMPLE_CPP_2_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ $(OBJ_SAMPLE_CPP_2_MT_UX_DEBUG) $(LIBS_SAMPLES_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_SAMPLE_CPP_2_MT_UX_DEBUG):	$(PROJ_SAMPLES_DIR)\cpp\sample_cpp_2\sample_cpp_2.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_2\sample_cpp_2.cpp


########################################
# test

# C test client

$(TARGET_TEST_C_1_MT_UX):	$(OBJ_TEST_C_1_MT_UX) $(LIBS_TEST_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX_TEST) -out:$@ $(OBJ_TEST_C_1_MT_UX) $(LIBS_TEST_MT_UX) $(LIBS_3PTY_MT_UX_TEST) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_TEST_C_1_MT_UX):	$(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX_TEST) -Fo$@ $(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c

$(TARGET_TEST_C_1_MT_UX_DEBUG):	$(OBJ_TEST_C_1_MT_UX_DEBUG) $(LIBS_TEST_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG_TEST) -out:$@ $(OBJ_TEST_C_1_MT_UX_DEBUG) $(LIBS_TEST_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG_TEST) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_TEST_C_1_MT_UX_DEBUG):	$(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_MT_UX_DEBUG_TEST) -Fo$@ $(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c

# C++ test client

$(TARGET_TEST_CPP_1_MT_UX):	$(OBJ_TEST_CPP_1_MT_UX) $(LIBS_TEST_MT_UX) $(LIB_XCOVER_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX_TEST) -out:$@ $(OBJ_TEST_CPP_1_MT_UX) $(LIBS_TEST_MT_UX) $(LIBS_3PTY_MT_UX_TEST) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_TEST_CPP_1_MT_UX):	$(PROJ_TESTS_DIR)\cpp\test_cpp_1\test_cpp_1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_TEST) -Fo$@ $(PROJ_TESTS_DIR)\cpp\test_cpp_1\test_cpp_1.cpp

$(TARGET_TEST_CPP_2_MT_UX):	$(OBJ_TEST_CPP_2_MT_UX) $(LIBS_TEST_MT_UX) $(LIB_XCOVER_MT_UX) makefile
	$(LD) $(LD_ARGS_MT_UX_TEST) -out:$@ $(OBJ_TEST_CPP_2_MT_UX) $(LIBS_TEST_MT_UX) $(LIBS_3PTY_MT_UX_TEST) $(LIBS_EXPLICIT_MT_UX)

$(OBJ_TEST_CPP_2_MT_UX):	$(PROJ_TESTS_DIR)\cpp\test_cpp_2\test_cpp_2.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_TEST) -Fo$@ $(PROJ_TESTS_DIR)\cpp\test_cpp_2\test_cpp_2.cpp

$(TARGET_TEST_CPP_1_MT_UX_DEBUG):	$(OBJ_TEST_CPP_1_MT_UX_DEBUG) $(LIBS_TEST_MT_UX_DEBUG) $(LIB_XCOVER_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG_TEST) -out:$@ $(OBJ_TEST_CPP_1_MT_UX_DEBUG) $(LIBS_TEST_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG_TEST) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_TEST_CPP_1_MT_UX_DEBUG):	$(PROJ_TESTS_DIR)\cpp\test_cpp_1\test_cpp_1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG_TEST) -Fo$@ $(PROJ_TESTS_DIR)\cpp\test_cpp_1\test_cpp_1.cpp

$(TARGET_TEST_CPP_2_MT_UX_DEBUG):	$(OBJ_TEST_CPP_2_MT_UX_DEBUG) $(LIBS_TEST_MT_UX_DEBUG) $(LIB_XCOVER_MT_UX_DEBUG) makefile
	$(LD) $(LD_ARGS_MT_UX_DEBUG_TEST) -out:$@ $(OBJ_TEST_CPP_2_MT_UX_DEBUG) $(LIBS_TEST_MT_UX_DEBUG) $(LIBS_3PTY_MT_UX_DEBUG_TEST) $(LIBS_EXPLICIT_MT_UX_DEBUG)

$(OBJ_TEST_CPP_2_MT_UX_DEBUG):	$(PROJ_TESTS_DIR)\cpp\test_cpp_2\test_cpp_2.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG_TEST) -Fo$@ $(PROJ_TESTS_DIR)\cpp\test_cpp_2\test_cpp_2.cpp

############################### end of file ################################
