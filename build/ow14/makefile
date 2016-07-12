################################################################################
# File:     makefile
#
# Purpose:  Makefile for the shwild project, for the Open Watcom C/C++ 1.4
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  5th August 2015
#
################################################################################


################################################################################
# Symbols

# Identification

COMP_TAG          =   ow14
PROJ_TAG          =   shwild
PROJ_VER_MAJOR    =   0
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   wcc386
CPPC                =   wpp386
AR                  =   wlib
LD                  =   wcl386
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
 $(OPENRJ_ROOT)\lib\
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

CC_F_NOLOGO             =   -zq
CC_F_COMPILE_ONLY       =   
CC_F_WARNING_MAX        =   -w=9
CC_F_WARNING_ERR        =   -we

CPPC_F_NOLOGO       =   -zq
CPPC_F_COMPILE_ONLY =   
CPPC_F_WARNING_MAX  =   -w=9 -wcd=656 -wcd=657
CPPC_F_WARNING_ERR  =   -we
CPPC_F_EXCEPTIONS   =   -xs
CPPC_F_RTTI         =   -xr

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

CC_ARGS_ST_D =  $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_D_TEST =  $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)
CC_ARGS_ST_R =  $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_R_TEST =  $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES_TEST)

CPPC_ARGS_ST_D = -D_DEBUG -UNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_D_TEST = -D_DEBUG -UNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)
CPPC_ARGS_ST_R = -U_DEBUG -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_R_TEST = -U_DEBUG -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES_TEST)

# archiver flags and arguments

AR_ARGS = -q -c

# linker flags and arguments

LD_F_NOLOGO = 

LD_ARGS_ST_D = -zq $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_D_TEST = -zq $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)
LD_ARGS_ST_R = -zq $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_R_TEST = -zq $(LD_F_NOLOGO) $(LIB_PATHS_TEST) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_ST_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_ST_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).lib
TARGET_LIB_UN_ST_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGETS_LIBS =\
 $(TARGET_LIB_ST_D)\
 $(TARGET_LIB_UN_ST_D)\
 $(TARGET_LIB_ST_R)\
 $(TARGET_LIB_UN_ST_R)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).exe
TARGET_TEST_CPP_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).exe
TARGET_TEST_CPP_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_2.$(COMP_TAG).exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_ST_D)\
 $(TARGET_TEST_C_1_ST_R)\
 $(TARGET_TEST_CPP_1_ST_D)\
 $(TARGET_TEST_CPP_2_ST_D)\
 $(TARGET_TEST_CPP_1_ST_R)\
 $(TARGET_TEST_CPP_2_ST_R)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).exe
TARGET_EXAMPLE_C_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_ST_D)\
 $(TARGET_EXAMPLE_C_2_ST_D)\
 $(TARGET_EXAMPLE_C_1_ST_R)\
 $(TARGET_EXAMPLE_C_2_ST_R)\
 $(TARGET_EXAMPLE_CPP_1_ST_D)\
 $(TARGET_EXAMPLE_CPP_2_ST_D)\
 $(TARGET_EXAMPLE_CPP_1_ST_R)\
 $(TARGET_EXAMPLE_CPP_2_ST_R)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).exe
TARGET_SAMPLE_C_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).exe
TARGET_SAMPLE_CPP_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).exe
TARGET_SAMPLE_CPP_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_2.$(COMP_TAG).exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_ST_D)\
 $(TARGET_SAMPLE_C_2_ST_D)\
 $(TARGET_SAMPLE_C_1_ST_R)\
 $(TARGET_SAMPLE_C_2_ST_R)\
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

OBJ_CORE_matches__ST_D = $(PROJ_OBJ_DIR)\matches.debug.obj
OBJ_CORE_pattern__ST_D = $(PROJ_OBJ_DIR)\pattern.debug.obj
OBJ_CORE_api__ST_D = $(PROJ_OBJ_DIR)\api.debug.obj

OBJS_CORE_ST_D_PM =\
 -+$(OBJ_CORE_matches__ST_D)\
 -+$(OBJ_CORE_pattern__ST_D)\
 -+$(OBJ_CORE_api__ST_D)\
 \

OBJS_CORE_ST_D = \
 $(OBJ_CORE_matches__ST_D)\
 $(OBJ_CORE_pattern__ST_D)\
 $(OBJ_CORE_api__ST_D)\
 \


OBJ_CORE_matches__ST_R = $(PROJ_OBJ_DIR)\matches.obj
OBJ_CORE_pattern__ST_R = $(PROJ_OBJ_DIR)\pattern.obj
OBJ_CORE_api__ST_R = $(PROJ_OBJ_DIR)\api.obj

OBJS_CORE_ST_R_PM =\
 -+$(OBJ_CORE_matches__ST_R)\
 -+$(OBJ_CORE_pattern__ST_R)\
 -+$(OBJ_CORE_api__ST_R)\
 \

OBJS_CORE_ST_R = \
 $(OBJ_CORE_matches__ST_R)\
 $(OBJ_CORE_pattern__ST_R)\
 $(OBJ_CORE_api__ST_R)\
 \


OBJS_CORE =\
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

OBJ_TEST_C_1_ST_D = $(PROJ_OBJ_DIR)\test_c_1.debug.obj
OBJ_TEST_CPP_1_ST_D = $(PROJ_OBJ_DIR)\test_cpp_1.debug.obj
OBJ_TEST_CPP_2_ST_D = $(PROJ_OBJ_DIR)\test_cpp_2.debug.obj
OBJ_TEST_C_1_ST_R = $(PROJ_OBJ_DIR)\test_c_1.obj
OBJ_TEST_CPP_1_ST_R = $(PROJ_OBJ_DIR)\test_cpp_1.obj
OBJ_TEST_CPP_2_ST_R = $(PROJ_OBJ_DIR)\test_cpp_2.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_ST_D)\
 $(OBJ_TEST_C_1_ST_R)\
 $(OBJ_TEST_CPP_1_ST_D)\
 $(OBJ_TEST_CPP_2_ST_D)\
 $(OBJ_TEST_CPP_1_ST_R)\
 $(OBJ_TEST_CPP_2_ST_R)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_ST_D = $(PROJ_OBJ_DIR)\example_c_1.debug.obj
OBJ_EXAMPLE_C_2_ST_D = $(PROJ_OBJ_DIR)\example_c_2.debug.obj
OBJ_EXAMPLE_CPP_1_ST_D = $(PROJ_OBJ_DIR)\example_cpp_1.debug.obj
OBJ_EXAMPLE_CPP_2_ST_D = $(PROJ_OBJ_DIR)\example_cpp_2.debug.obj
OBJ_EXAMPLE_C_1_ST_R = $(PROJ_OBJ_DIR)\example_c_1.obj
OBJ_EXAMPLE_C_2_ST_R = $(PROJ_OBJ_DIR)\example_c_2.obj
OBJ_EXAMPLE_CPP_1_ST_R = $(PROJ_OBJ_DIR)\example_cpp_1.obj
OBJ_EXAMPLE_CPP_2_ST_R = $(PROJ_OBJ_DIR)\example_cpp_2.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_ST_D)\
 $(OBJ_EXAMPLE_C_2_ST_D)\
 $(OBJ_EXAMPLE_C_1_ST_R)\
 $(OBJ_EXAMPLE_C_2_ST_R)\
 $(OBJ_EXAMPLE_CPP_1_ST_D)\
 $(OBJ_EXAMPLE_CPP_2_ST_D)\
 $(OBJ_EXAMPLE_CPP_1_ST_R)\
 $(OBJ_EXAMPLE_CPP_2_ST_R)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_ST_D = $(PROJ_OBJ_DIR)\sample_c_1.debug.obj
OBJ_SAMPLE_C_2_ST_D = $(PROJ_OBJ_DIR)\sample_c_2.debug.obj
OBJ_SAMPLE_CPP_1_ST_D = $(PROJ_OBJ_DIR)\sample_cpp_1.debug.obj
OBJ_SAMPLE_CPP_2_ST_D = $(PROJ_OBJ_DIR)\sample_cpp_2.debug.obj
OBJ_SAMPLE_C_1_ST_R = $(PROJ_OBJ_DIR)\sample_c_1.obj
OBJ_SAMPLE_C_2_ST_R = $(PROJ_OBJ_DIR)\sample_c_2.obj
OBJ_SAMPLE_CPP_1_ST_R = $(PROJ_OBJ_DIR)\sample_cpp_1.obj
OBJ_SAMPLE_CPP_2_ST_R = $(PROJ_OBJ_DIR)\sample_cpp_2.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_ST_D)\
 $(OBJ_SAMPLE_C_2_ST_D)\
 $(OBJ_SAMPLE_C_1_ST_R)\
 $(OBJ_SAMPLE_C_2_ST_R)\
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
	$(TARGET_TEST_C_1_ST_D) --unittest
	$(TARGET_TEST_C_1_ST_R) --unittest
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
	@-$(RM) $(TARGET_LIB_ST_D)
	@-$(RM) $(TARGET_LIB_UN_ST_D)
	@-$(RM) $(TARGET_LIB_ST_R)
	@-$(RM) $(TARGET_LIB_UN_ST_R)
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
	@-$(RM) $(TARGET_TEST_C_1_ST_D)
	@-$(RM) $(TARGET_TEST_C_1_ST_R)
	@-$(RM) $(TARGET_TEST_CPP_1_ST_D)
	@-$(RM) $(TARGET_TEST_CPP_2_ST_D)
	@-$(RM) $(TARGET_TEST_CPP_1_ST_R)
	@-$(RM) $(TARGET_TEST_CPP_2_ST_R)
	@-$(RM) $(OBJ_TEST_C_1_ST_D)
	@-$(RM) $(OBJ_TEST_C_1_ST_R)
	@-$(RM) $(OBJ_TEST_CPP_1_ST_D)
	@-$(RM) $(OBJ_TEST_CPP_2_ST_D)
	@-$(RM) $(OBJ_TEST_CPP_1_ST_R)
	@-$(RM) $(OBJ_TEST_CPP_2_ST_R)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_ST_R)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_ST_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_ST_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_ST_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_2_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_ST_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_ST_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_ST_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_2_ST_R)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_ST_D): $(TARGET_LIB_ST_D)
	@$(CP) $(TARGET_LIB_ST_D) $@

$(TARGET_LIB_ST_D): $(OBJS_CORE_ST_D) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_D_PM)

$(OBJ_CORE_matches__ST_D): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__ST_D): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__ST_D): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\api.cpp


$(TARGET_LIB_UN_ST_R): $(TARGET_LIB_ST_R)
	@$(CP) $(TARGET_LIB_ST_R) $@

$(TARGET_LIB_ST_R): $(OBJS_CORE_ST_R) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_R_PM)

$(OBJ_CORE_matches__ST_R): $(PROJ_SRC_DIR)\matches.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__ST_R): $(PROJ_SRC_DIR)\pattern.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__ST_R): $(PROJ_SRC_DIR)\api.cpp $(HEADERS_LIB) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\api.cpp


########################################
# test

# C test client

$(TARGET_TEST_C_1_ST_D):	$(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D_TEST) -fe=$@ $(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D_TEST)

$(OBJ_TEST_C_1_ST_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D_TEST) -fo=$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_ST_R):	$(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R_TEST) -fe=$@ $(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R_TEST)

$(OBJ_TEST_C_1_ST_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R_TEST) -fo=$@ $(SRC_TEST_C_1)

# C++ test client

$(TARGET_TEST_CPP_1_ST_D):	$(OBJ_TEST_CPP_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D_TEST) -fe=$@ $(OBJ_TEST_CPP_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D_TEST)

$(OBJ_TEST_CPP_1_ST_D):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D_TEST) -fo=$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_ST_D):	$(OBJ_TEST_CPP_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D_TEST) -fe=$@ $(OBJ_TEST_CPP_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D_TEST)

$(OBJ_TEST_CPP_2_ST_D):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D_TEST) -fo=$@ $(SRC_TEST_CPP_2)

$(TARGET_TEST_CPP_1_ST_R):	$(OBJ_TEST_CPP_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R_TEST) -fe=$@ $(OBJ_TEST_CPP_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R_TEST)

$(OBJ_TEST_CPP_1_ST_R):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R_TEST) -fo=$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_2_ST_R):	$(OBJ_TEST_CPP_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R_TEST) -fe=$@ $(OBJ_TEST_CPP_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R_TEST)

$(OBJ_TEST_CPP_2_ST_R):	$(SRC_TEST_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R_TEST) -fo=$@ $(SRC_TEST_CPP_2)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_ST_D):	$(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_1_ST_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_D):	$(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_2_ST_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_ST_R):	$(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_1_ST_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_R):	$(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_2_ST_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_EXAMPLE_C_2)

# C++ example client

$(TARGET_EXAMPLE_CPP_1_ST_D):	$(OBJ_EXAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_EXAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_CPP_1_ST_D):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_ST_D):	$(OBJ_EXAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_EXAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_CPP_2_ST_D):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_ST_R):	$(OBJ_EXAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_EXAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_CPP_1_ST_R):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_ST_R):	$(OBJ_EXAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_EXAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_CPP_2_ST_R):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(SRC_EXAMPLE_CPP_2)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_ST_D):	$(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_1_ST_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_D):	$(OBJ_SAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_SAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_2_ST_D):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_ST_R):	$(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_1_ST_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_R):	$(OBJ_SAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_SAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_2_ST_R):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_SAMPLE_C_2)

# C++ sample client

$(TARGET_SAMPLE_CPP_1_ST_D):	$(OBJ_SAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_SAMPLE_CPP_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_CPP_1_ST_D):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_ST_D):	$(OBJ_SAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_SAMPLE_CPP_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_CPP_2_ST_D):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -fo=$@ $(SRC_SAMPLE_CPP_2)

$(TARGET_SAMPLE_CPP_1_ST_R):	$(OBJ_SAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_SAMPLE_CPP_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_CPP_1_ST_R):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_2_ST_R):	$(OBJ_SAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_SAMPLE_CPP_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_CPP_2_ST_R):	$(SRC_SAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -fo=$@ $(SRC_SAMPLE_CPP_2)

################################################################################
