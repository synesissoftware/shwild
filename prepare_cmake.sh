#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=$Dir/_build


CMakeExamplesDisabled=0
CMakeTestingDisabled=0
CMakeVerboseMakefile=0
Configuration=Release
RunMake=0
STLSoftDirGiven=
UseSTLSoft=0


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --bdut-root-dir)

      shift
      BDUTDirGiven=$1
      ;;
    -v|--cmake-verbose-makefile)

      CMakeVerboseMakefile=1
      ;;
    -d|--debug-configuration)

      Configuration=Debug
      ;;
    -E|--disable-examples)

      CMakeExamplesDisabled=1
      ;;
    -T|--disable-testing)

      CMakeTestingDisabled=1
      ;;
    -m|--run-make)

      RunMake=1
      ;;
    -s|--stlsoft-root-dir)

      shift
      STLSoftDirGiven=$1
      ;;
    --use-stlsoft)

      UseSTLSoft=1
      ;;
    --help)

      cat << EOF
shwild is a small, standalone library, implemented in C++ with a C and a C++ API, that provides shell-compatible wildcard matching
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2005-2023, Matthew Wilson and Sean Kelly
Creates/reinitialises the CMake build script(s)

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    --bdut-root-dir <dir>
        specifies the BDUT root-directory, which will be passed to CMake
        as the variable BDUT_ROOT, from which the BDUT library will be used,
        rather than using the bundled version

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (by setting
        CMAKE_VERBOSE_MAKEFILE=ON)

    -d
    --debug-configuration
        use Debug configuration (by setting CMAKE_BUILD_TYPE=Debug). Default
        is to use Release

    -E
    --disable-examples
        disables building of examples (by setting BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (by setting BUILD_TESTING=OFF)

    -m
    --run-make
        executes make after a successful running of CMake

    -s <dir>
    --stlsoft-root-dir <dir>
        specifies the STLSoft root-directory, which will be passed to CMake
        as the variable STLSOFT, and which will override the environment
        variable STLSOFT (if present)

    --use-stlsoft
        causes shwild to assume STLSoft - either as a findable CMake package
        or in the directory specified by --stlsoft-root-dir - in its
        implementation and interface


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

mkdir -p $CMakeDir || exit 1

cd $CMakeDir

echo "Executing CMake"

if [ -z $BDUTDirGiven ]; then CMakeBDUTVariable="" ; else CMakeBDUTVariable="-DBDUT_ROOT=$BDUTDirGiven/" ; fi
if [ $CMakeExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi
if [ $CMakeTestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi
if [ $CMakeVerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi
if [ -z $STLSoftDirGiven ]; then CMakeSTLSoftVariable="" ; else CMakeSTLSoftVariable="-DSTLSOFT=$STLSoftDirGiven/" ; fi
if [ $UseSTLSoft -eq 0 ]; then CMakeUseSTLSoftFlag="OFF" ; else CMakeUseSTLSoftFlag="ON" ; fi

cmake \
  $CMakeBDUTVariable \
  $CMakeSTLSoftVariable \
  -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
  -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
  -DCMAKE_BUILD_TYPE=$Configuration \
  -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
  -DUSE_STLSOFT_PKG:BOOL=$CMakeUseSTLSoftFlag \
  .. || (cd ->/dev/null ; exit 1)

status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing make"

  make
  status=$?
fi

cd ->/dev/null

if [ $CMakeVerboseMakefile -ne 0 ]; then

  echo -e "contents of $CMakeDir:"
  ls -al $CMakeDir
fi

exit $status


# ############################## end of file ############################# #

