#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do
    case $1 in
        --help)
            cat << EOF
shwild is a small, standalone library, implemented in C++ with a C and a C++ API, that provides shell-compatible wildcard matching
Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
Copyright (c) 2005-2023, Matthew Wilson and Sean Kelly
Runs all (matching) unit-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:


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

mkdir -p $CMakePath || exit 1

cd $CMakePath

echo "Executing make and then running all test programs"

make && for f in $(find $Dir -type f -perm +111 '(' -name 'test_*' -o -name 'test.*' ')')
do
    echo
    echo "executing $f:"

    $f || break 1
done

cd ->/dev/null


# ############################## end of file ############################# #

