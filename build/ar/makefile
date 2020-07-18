############################################################################
# File:     makefile
#
# Purpose:  Makefile for the shwild project, for the Arturius C/C++ Compiler Multiplexer
#           compiler, on Win32
#
# Created:  29th April 2006
# Updated:  18th July 2020
#
############################################################################


############################################################################
# symbols

########################################
# project & compiler version

COMP_TAG            =   ar
ARCH_TAG            =   
OS_TAG              =   
PROJ_TAG			=	shwild
PROJ_VER_MAJOR      =   0
PROJ_MOD_TAG        =   core
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG    =   $(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

########################################
# dependencies

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
PROJ_TEST_ROOT_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR =   $(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_SCRATCH_DIR   =   $(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR      =   $(PROJ_TEST_ROOT_DIR)\unit

########################################
# 3rd-party directories

############################################################################
# tools

CC                      =   arcc.debug
CPPC                    =   arcc.debug
AR                      =   lib
LD                      =   arld
RM                      =   del /f
CP                      =   copy
RC                      =   rc

############################################################
# compiler

########################################
# includes

INCLUDES_LEADER         =   

PROJ_INCLUDE            =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES         =

STLSOFT_INCLUDES		=\
 -I"$(STLSOFT)\include"\
 \

THIRDPARTY_INCLUDES		=\
 \

# CC

CC_INCLUDES_BASE =\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 $(THIRDPARTY_INCLUDES)\
 \

CC_INCLUDES_DEBUG =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_RELEASE =\
 $(CC_INCLUDES_BASE)\
 \


CC_SHWILD_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_DEBUG =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_RELEASE =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_INCLUDES_TEST=\
 $(CC_INCLUDES_BASE)\
 \

# CPPC

CPPC_INCLUDES_BASE =\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 $(THIRDPARTY_INCLUDES)\
 \

CPPC_INCLUDES_DEBUG =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_RELEASE =\
 $(CPPC_INCLUDES_BASE)\
 \


CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DEBUG =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_RELEASE =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_INCLUDES_TEST=\
 $(CPPC_INCLUDES_BASE)\
 \

########################################
# defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DSHWILD_NO_IMPLICIT_LINK\
 \

COMMON_DEFS             =   -DWIN32

CUSTOM_DEFS             =

# CC

CC_CUSTOM_DEFS          =   $(CUSTOM_DEFS)

CC_DEFS_BASE =\
 $(CC_CUSTOM_DEFS)\
 $(COMMON_DEFS)\
 \

CC_DEFS_DEBUG =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_RELEASE =\
 $(CC_DEFS_BASE)\
 \


# CPPC

CPPC_CUSTOM_DEFS        =   $(CUSTOM_DEFS)

CPPC_DEFS_BASE =\
 $(CPPC_CUSTOM_DEFS)\
 $(COMMON_DEFS)\
 \

CPPC_DEFS_DEBUG =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_RELEASE =\
 $(CPPC_DEFS_BASE)\
 \


########################################
# flags

# CC

CC_F_NOLOGO             =   
CC_F_COMPILE_ONLY       =   -c
CC_F_FORCE_INCLUDE      =   
CC_F_WARNING_MAX        =   --warning-level=maximum
CC_F_WARNING_ERR        =   --warnings-as-errors=on
CC_F_MINIMUM_SIZE       =   --minimum-size
CC_F_MAXIMUM_SPEED      =   --maximum-speed

CC_TOOL_FLAGS       =   --compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71,ow12 --active-compiler=vc/6 --announce-tool-commands

CC_FLAGS_BASE =\
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_FORCE_INCLUDE)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_DEBUG =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_RELEASE =\
 $(CC_FLAGS_BASE)\
 \


# CPPC

CPPC_F_NOLOGO           =   
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_FORCE_INCLUDE    =   
CPPC_F_WARNING_MAX      =   --warning-level=maximum
CPPC_F_WARNING_ERR      =   --warnings-as-errors=on
CPPC_F_EXCEPTIONS_ON    =   --exception-handling=on
CPPC_F_EXCEPTIONS_OFF   =   --exception-handling=off
CPPC_F_EXCEPTIONS       =   $(CPPC_F_EXCEPTIONS_ON)
CPPC_F_RTTI_ON          =   
CPPC_F_RTTI_OFF         =   
CPPC_F_RTTI             =   $(CPPC_F_RTTI_ON)
CPPC_F_MINIMUM_SIZE     =   --minimum-size
CPPC_F_MAXIMUM_SPEED    =   

CPPC_TOOL_FLAGS     =   --compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71 --active-compiler=vc/6 --announce-tool-commands

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

CPPC_FLAGS_DEBUG =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_RELEASE =\
 $(CPPC_FLAGS_BASE)\
 \


########################################
# arguments

# CC args (= flags + defines + includes)

CC_ARGS_DEBUG=\
 $(CC_FLAGS_DEBUG)\
 -D_DEBUG -UNDEBUG\
 $(CC_DEFS_DEBUG)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_DEBUG)
CC_ARGS_DEBUG_TEST=\
 $(CC_FLAGS_DEBUG)\
 -D_DEBUG -UNDEBUG\
 $(CC_DEFS_DEBUG)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_TEST)
CC_ARGS_RELEASE=\
 $(CC_FLAGS_RELEASE)\
 -DNDEBUG -U_DEBUG $(CC_F_MAXIMUM_SPEED)\
 $(CC_DEFS_RELEASE)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_RELEASE)
CC_ARGS_RELEASE_TEST=\
 $(CC_FLAGS_RELEASE)\
 -DNDEBUG -U_DEBUG $(CC_F_MAXIMUM_SPEED)\
 $(CC_DEFS_RELEASE)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_TEST)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_DEBUG=\
 $(CPPC_FLAGS_DEBUG)\
 -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_DEBUG)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_DEBUG)
CPPC_ARGS_DEBUG_TEST=\
 $(CPPC_FLAGS_DEBUG)\
 -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_DEBUG)\
 $(CPPC_INCLUDES_TEST)
CPPC_ARGS_RELEASE=\
 $(CPPC_FLAGS_RELEASE)\
 -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_RELEASE)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_RELEASE)
CPPC_ARGS_RELEASE_TEST=\
 $(CPPC_FLAGS_RELEASE)\
 -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_RELEASE)\
 $(CPPC_INCLUDES_TEST)

############################################################
# archiver

AR_F_NOLOGO             =   

AR_ARGS                 =   

############################################################
# linker

########################################
# flags

LD_F_NOLOGO             =   

LD_FLAGS_BASE           =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_DEBUG =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_RELEASE =\
 $(LD_FLAGS_BASE)\
 \


########################################
# paths

LIBPATHS_ENV            =

LIBPATHS_COMMON         =

LIBPATHS_3PTY           =\
 \

LIBPATHS=\
 $(LIBPATHS_COMMON)\
 $(LIBPATHS_3PTY)\
 $(LIBPATHS_ENV)\
 \

LIBPATHS_TEST =\
 $(LIBPATHS)\
 \

########################################
# arguments

LD_ARGS_DEBUG      =    $(LD_F_NOLOGO) $(LIBPATHS)
LD_ARGS_DEBUG_TEST =    $(LD_F_NOLOGO) $(LIBPATHS_TEST)
LD_ARGS_RELEASE      =    $(LD_F_NOLOGO) $(LIBPATHS)
LD_ARGS_RELEASE_TEST =    $(LD_F_NOLOGO) $(LIBPATHS_TEST)

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

OBJ_CORE_matches__DEBUG    =   $(PROJ_OBJ_DIR)\core.matches.debug.obj
OBJ_CORE_pattern__DEBUG    =   $(PROJ_OBJ_DIR)\core.pattern.debug.obj
OBJ_CORE_api__DEBUG        =   $(PROJ_OBJ_DIR)\core.api.debug.obj

OBJS_CORE_DEBUG =\
 $(OBJ_CORE_matches__DEBUG)\
 $(OBJ_CORE_pattern__DEBUG)\
 $(OBJ_CORE_api__DEBUG)\
 \

OBJ_CORE_matches__RELEASE    =   $(PROJ_OBJ_DIR)\core.matches.obj
OBJ_CORE_pattern__RELEASE    =   $(PROJ_OBJ_DIR)\core.pattern.obj
OBJ_CORE_api__RELEASE        =   $(PROJ_OBJ_DIR)\core.api.obj

OBJS_CORE_RELEASE =\
 $(OBJ_CORE_matches__RELEASE)\
 $(OBJ_CORE_pattern__RELEASE)\
 $(OBJ_CORE_api__RELEASE)\
 \

OBJS_CORE =\
 $(OBJS_CORE_DEBUG)\
 $(OBJS_CORE_RELEASE)\
 \

# *

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# examples

OBJ_EXAMPLE_CPP_1_DEBUG = $(PROJ_OBJ_DIR)\example.cpp.1.debug.obj
OBJ_EXAMPLE_CPP_1_RELEASE = $(PROJ_OBJ_DIR)\example.cpp.1.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_CPP_1_DEBUG)\
 $(OBJ_EXAMPLE_CPP_1_RELEASE)\
 \

########################################
# tests

OBJ_TEST_C_1_DEBUG = $(PROJ_OBJ_DIR)\test.unit.c.1.debug.obj
OBJ_TEST_CPP_1_DEBUG = $(PROJ_OBJ_DIR)\test.unit.cpp.1.debug.obj
OBJ_TEST_CPP_2_DEBUG = $(PROJ_OBJ_DIR)\test.unit.cpp.2.debug.obj
OBJ_TEST_CPP_3_DEBUG = $(PROJ_OBJ_DIR)\test.unit.cpp.3.debug.obj
OBJ_TEST_C_1_RELEASE = $(PROJ_OBJ_DIR)\test.unit.c.1.obj
OBJ_TEST_CPP_1_RELEASE = $(PROJ_OBJ_DIR)\test.unit.cpp.1.obj
OBJ_TEST_CPP_2_RELEASE = $(PROJ_OBJ_DIR)\test.unit.cpp.2.obj
OBJ_TEST_CPP_3_RELEASE = $(PROJ_OBJ_DIR)\test.unit.cpp.3.obj

OBJS_TEST_UNIT =\
 $(OBJ_TEST_C_1_DEBUG)\
 $(OBJ_TEST_C_1_RELEASE)\
 $(OBJ_TEST_CPP_1_DEBUG)\
 $(OBJ_TEST_CPP_2_DEBUG)\
 $(OBJ_TEST_CPP_3_DEBUG)\
 $(OBJ_TEST_CPP_1_RELEASE)\
 $(OBJ_TEST_CPP_2_RELEASE)\
 $(OBJ_TEST_CPP_3_RELEASE)\
 \

########################################
# OBJS

OBJS =\
 $(OBJS_LIBS)\
 \
 $(OBJS_EXAMPLES)\
 $(OBJS_TEST_UNIT)\
 \

############################################################################
# targets

########################################
# libraries

# core

LIB_CORE_DEBUG                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(PROJ_MOD_TAG).$(COMP_ARCH_OS_TAG).debug.lib
LIB_CORE_RELEASE                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(PROJ_MOD_TAG).$(COMP_ARCH_OS_TAG).lib

TARGETS_LIB_CORE=\
 $(LIB_CORE_DEBUG)\
 $(LIB_CORE_RELEASE)\
 \

# *

TARGETS_LIB_ALL=\
 $(TARGETS_LIB_CORE)\
 \

TARGETS_LIBS=\
 $(TARGETS_LIB_CORE)\
 \

########################################
# examples

TARGET_EXAMPLE_CPP_1_DEBUG =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_ARCH_OS_TAG).debug.exe
TARGET_EXAMPLE_CPP_1_RELEASE =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_ARCH_OS_TAG).exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_CPP_1_DEBUG)\
 $(TARGET_EXAMPLE_CPP_1_RELEASE)\
 \

########################################
# tests

TARGET_TEST_C_1_DEBUG      =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.1.$(COMP_ARCH_OS_TAG).debug.exe
TARGET_TEST_CPP_1_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.1.$(COMP_ARCH_OS_TAG).debug.exe
TARGET_TEST_CPP_2_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.2.$(COMP_ARCH_OS_TAG).debug.exe
TARGET_TEST_CPP_3_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.3.$(COMP_ARCH_OS_TAG).debug.exe
TARGET_TEST_C_1_RELEASE      =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.1.$(COMP_ARCH_OS_TAG).exe
TARGET_TEST_CPP_1_RELEASE    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.1.$(COMP_ARCH_OS_TAG).exe
TARGET_TEST_CPP_2_RELEASE    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.2.$(COMP_ARCH_OS_TAG).exe
TARGET_TEST_CPP_3_RELEASE    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.3.$(COMP_ARCH_OS_TAG).exe

TARGETS_TEST_UNIT =\
 $(TARGET_TEST_C_1_DEBUG)\
 $(TARGET_TEST_CPP_1_DEBUG)\
 $(TARGET_TEST_CPP_2_DEBUG)\
 $(TARGET_TEST_CPP_3_DEBUG)\
 $(TARGET_TEST_C_1_RELEASE)\
 $(TARGET_TEST_CPP_1_RELEASE)\
 $(TARGET_TEST_CPP_2_RELEASE)\
 $(TARGET_TEST_CPP_3_RELEASE)\
 \

########################################
# TARGETS

TARGETS =\
 $(TARGETS_LIBS)\
 \
 $(TARGETS_TEST_UNIT)\
 $(TARGETS_EXAMPLES)\
 \

############################################################
# libs

LIBS_EXPLICIT_DEBUG =\
  \
 \

LIBS_EXPLICIT_RELEASE =\
  \
 \


LIBS_3PTY_DEBUG =\
 \

LIBS_3PTY_DEBUG_TEST =\
 $(LIBS_3PTY_DEBUG)\
 \

LIBS_3PTY_RELEASE =\
 \

LIBS_3PTY_RELEASE_TEST =\
 $(LIBS_3PTY_RELEASE)\
 \


LIBS_EXAMPLES_DEBUG=\
 $(LIB_CORE_DEBUG)\
 \


LIBS_EXAMPLES_RELEASE=\
 $(LIB_CORE_RELEASE)\
 \


LIBS_TESTS_DEBUG=\
 $(LIB_CORE_DEBUG)\
 \


LIBS_TESTS_RELEASE=\
 $(LIB_CORE_RELEASE)\
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

compile.libs.3pty:			$(PROJ_MAKEFILE_NAME)

compile.libs.all:                                   compile.libs compile.libs.3pty

compile.examples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_EXAMPLES)

compile.test.component:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_COMPONENT)

compile.test.scratch:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_SCRATCH)

compile.test.unit:			$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_UNIT)

compile.test:										compile.test.unit compile.test.component compile.test.scratch

compile:											compile.libs compile.libs.3pty compile.test compile.examples

compile.all:										compile




# build targets

build.libs.core:			check.lib.dir			$(TARGETS_LIB_CORE)

build.libs.shwild:									build.libs.core

build.libs:											build.libs.core

build.libs.3pty:			check.bin.dir

build.libs.all:										build.libs build.libs.3pty

build.examples:				check.bin.dir			$(TARGETS_EXAMPLES)

build.test.component:		check.bin.dir			$(TARGETS_TEST_COMPONENT)

build.test.scratch:			check.bin.dir			$(TARGETS_TEST_SCRATCH)

build.test.unit:			check.bin.dir			$(TARGETS_TEST_UNIT)

build.test:											build.test.unit build.test.component build.test.scratch

build:												build.libs build.test build.examples

build.all:											build build.libs.all



# test targets

test.component_:
	@echo Running Test:Component programs ...

test.scratch_:
	@echo Running Test:Scratch programs ...

test.unit_:
	@echo Running Test:Unit programs ...
 $(TARGET_TEST_C_1_DEBUG)
 $(TARGET_TEST_CPP_1_DEBUG)
 $(TARGET_TEST_CPP_2_DEBUG)
 $(TARGET_TEST_CPP_3_DEBUG)
 $(TARGET_TEST_C_1_RELEASE)
 $(TARGET_TEST_CPP_1_RELEASE)
 $(TARGET_TEST_CPP_2_RELEASE)
 $(TARGET_TEST_CPP_3_RELEASE)

test.component:			$(PROJ_MAKEFILE_NAME)	build.test.component test.component_

test.scratch:			$(PROJ_MAKEFILE_NAME)	build.test.scratch test.scratch_

test.unit:				$(PROJ_MAKEFILE_NAME)	build.test.unit test.unit_

test:											test.unit test.component

test.all:										test test.scratch
test-all:				test.all


# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-if exist $(LIB_CORE_DEBUG) $(RM) $(LIB_CORE_DEBUG)
	@-if exist $(LIB_CORE_RELEASE) $(RM) $(LIB_CORE_RELEASE)
	@-if exist core.obj $(RM) core.obj
	@-if exist core.*.obj $(RM) core.*.obj
	@-if exist $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.shwild:	clean.libs.core

clean.test.component:
	@echo cleaning Test:Component programs ...
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.$(COMP_ARCH_OS_TAG)*.exe
	@-for %f in (test.component.*.obj) do @$(RM) %f

clean.test.scratch:
	@echo cleaning Test:Scratch programs ...
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.$(COMP_ARCH_OS_TAG)*.exe
	@-for %f in (test.scratch.*.obj) do @$(RM) %f

clean.test.unit:
	@echo cleaning Test:Unit programs ...
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.$(COMP_ARCH_OS_TAG)*.exe
	@-for %f in (test.unit.*.obj) do @$(RM) %f

clean.libs: 									clean.libs.core

clean.libs.3pty:

clean.libs.all: 								clean.libs clean.libs.3pty

clean.examples:
	@echo cleaning example programs ...
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.$(COMP_ARCH_OS_TAG)*.exe
	@-for %f in (example.*.obj) do @$(RM) %f

clean.test:										clean.test.component clean.test.scratch clean.test.unit

clean:					$(PROJ_MAKEFILE_NAME)	clean.libs.all clean.test clean.examples

clean.all:										clean

############################################################################
# build targets

##################################################
# libraries

########################################
# core


$(LIB_CORE_DEBUG): $(OBJS_CORE_DEBUG) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_DEBUG)

$(OBJ_CORE_matches__DEBUG): $(PROJ_SRC_DIR)\matches.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__DEBUG): $(PROJ_SRC_DIR)\pattern.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__DEBUG): $(PROJ_SRC_DIR)\api.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\api.cpp


$(LIB_CORE_RELEASE): $(OBJS_CORE_RELEASE) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_RELEASE)

$(OBJ_CORE_matches__RELEASE): $(PROJ_SRC_DIR)\matches.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\matches.cpp
$(OBJ_CORE_pattern__RELEASE): $(PROJ_SRC_DIR)\pattern.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\pattern.cpp
$(OBJ_CORE_api__RELEASE): $(PROJ_SRC_DIR)\api.cpp $(SRCS_HDR_CORE) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\api.cpp


########################################
# examples

# C++ example client

$(TARGET_EXAMPLE_CPP_1_DEBUG):	$(OBJ_EXAMPLE_CPP_1_DEBUG) $(LIBS_EXAMPLES_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_1_DEBUG) $(LIBS_EXAMPLES_DEBUG) $(LIBS_3PTY_DEBUG) $(LIBS_EXPLICIT_DEBUG)

$(OBJ_EXAMPLE_CPP_1_DEBUG):	$(PROJ_EXAMPLES_DIR)\cpp\example.cpp.1\example.cpp.1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(PROJ_EXAMPLES_DIR)\cpp\example.cpp.1\example.cpp.1.cpp

$(TARGET_EXAMPLE_CPP_1_RELEASE):	$(OBJ_EXAMPLE_CPP_1_RELEASE) $(LIBS_EXAMPLES_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_1_RELEASE) $(LIBS_EXAMPLES_RELEASE) $(LIBS_3PTY_RELEASE) $(LIBS_EXPLICIT_RELEASE)

$(OBJ_EXAMPLE_CPP_1_RELEASE):	$(PROJ_EXAMPLES_DIR)\cpp\example.cpp.1\example.cpp.1.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(PROJ_EXAMPLES_DIR)\cpp\example.cpp.1\example.cpp.1.cpp

########################################
# test

# C test client

$(TARGET_TEST_C_1_DEBUG):	$(OBJ_TEST_C_1_DEBUG) $(LIB_CORE_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG_TEST) $@ $(OBJ_TEST_C_1_DEBUG) $(LIB_CORE_DEBUG) $(LIBS_3PTY_DEBUG_TEST) $(LIBS_EXPLICIT_DEBUG)

$(OBJ_TEST_C_1_DEBUG):	$(PROJ_TEST_UNIT_DIR)\test.unit.shwild_match\test.unit.shwild_match.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_DEBUG_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shwild_match\test.unit.shwild_match.c

$(TARGET_TEST_C_1_RELEASE):	$(OBJ_TEST_C_1_RELEASE) $(LIB_CORE_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE_TEST) $@ $(OBJ_TEST_C_1_RELEASE) $(LIB_CORE_RELEASE) $(LIBS_3PTY_RELEASE_TEST) $(LIBS_EXPLICIT_RELEASE)

$(OBJ_TEST_C_1_RELEASE):	$(PROJ_TEST_UNIT_DIR)\test.unit.shwild_match\test.unit.shwild_match.c $(SRCS_HDR_CORE) makefile
	$(CC) $(CC_ARGS_RELEASE_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shwild_match\test.unit.shwild_match.c

# C++ test client

$(TARGET_TEST_CPP_1_DEBUG):	$(OBJ_TEST_CPP_1_DEBUG) $(LIB_CORE_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG_TEST) $@ $(OBJ_TEST_CPP_1_DEBUG) $(LIB_CORE_DEBUG) $(LIBS_3PTY_DEBUG_TEST) $(LIBS_EXPLICIT_DEBUG)

$(OBJ_TEST_CPP_1_DEBUG):	$(PROJ_TEST_UNIT_DIR)\test.unit.shwild.match\test.unit.shwild.match.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shwild.match\test.unit.shwild.match.cpp

$(TARGET_TEST_CPP_2_DEBUG):	$(OBJ_TEST_CPP_2_DEBUG) $(LIB_CORE_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG_TEST) $@ $(OBJ_TEST_CPP_2_DEBUG) $(LIB_CORE_DEBUG) $(LIBS_3PTY_DEBUG_TEST) $(LIBS_EXPLICIT_DEBUG)

$(OBJ_TEST_CPP_2_DEBUG):	$(PROJ_TEST_UNIT_DIR)\test.unit.shwild.pattern\test.unit.shwild.pattern.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shwild.pattern\test.unit.shwild.pattern.cpp

$(TARGET_TEST_CPP_3_DEBUG):	$(OBJ_TEST_CPP_3_DEBUG) $(LIB_CORE_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG_TEST) $@ $(OBJ_TEST_CPP_3_DEBUG) $(LIB_CORE_DEBUG) $(LIBS_3PTY_DEBUG_TEST) $(LIBS_EXPLICIT_DEBUG)

$(OBJ_TEST_CPP_3_DEBUG):	$(PROJ_TEST_UNIT_DIR)\test.unit.internal\test.unit.internal.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.internal\test.unit.internal.cpp

$(TARGET_TEST_CPP_1_RELEASE):	$(OBJ_TEST_CPP_1_RELEASE) $(LIB_CORE_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE_TEST) $@ $(OBJ_TEST_CPP_1_RELEASE) $(LIB_CORE_RELEASE) $(LIBS_3PTY_RELEASE_TEST) $(LIBS_EXPLICIT_RELEASE)

$(OBJ_TEST_CPP_1_RELEASE):	$(PROJ_TEST_UNIT_DIR)\test.unit.shwild.match\test.unit.shwild.match.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shwild.match\test.unit.shwild.match.cpp

$(TARGET_TEST_CPP_2_RELEASE):	$(OBJ_TEST_CPP_2_RELEASE) $(LIB_CORE_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE_TEST) $@ $(OBJ_TEST_CPP_2_RELEASE) $(LIB_CORE_RELEASE) $(LIBS_3PTY_RELEASE_TEST) $(LIBS_EXPLICIT_RELEASE)

$(OBJ_TEST_CPP_2_RELEASE):	$(PROJ_TEST_UNIT_DIR)\test.unit.shwild.pattern\test.unit.shwild.pattern.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shwild.pattern\test.unit.shwild.pattern.cpp

$(TARGET_TEST_CPP_3_RELEASE):	$(OBJ_TEST_CPP_3_RELEASE) $(LIB_CORE_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE_TEST) $@ $(OBJ_TEST_CPP_3_RELEASE) $(LIB_CORE_RELEASE) $(LIBS_3PTY_RELEASE_TEST) $(LIBS_EXPLICIT_RELEASE)

$(OBJ_TEST_CPP_3_RELEASE):	$(PROJ_TEST_UNIT_DIR)\test.unit.internal\test.unit.internal.cpp $(SRCS_HDR_CORE) $(SRCS_HDR_MAPPING) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE_TEST) --output-path=$@ $(PROJ_TEST_UNIT_DIR)\test.unit.internal\test.unit.internal.cpp

############################### end of file ################################
