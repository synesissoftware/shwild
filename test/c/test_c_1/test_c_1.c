/* /////////////////////////////////////////////////////////////////////////////
 * File:        test_c_1.c
 *
 * Purpose:     C test file for the shwild library
 *
 * Created:     30th July 2005
 * Updated:     22nd February 2007
 *
 * Home:        http://shwild.org/
 *
 * Copyright (c) 2005-2007, Matthew Wilson and Sean Kelly
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Sean Kelly nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* shwild Header Files */
#include <shwild/shwild.h>

/* Open-RJ Header Files */
#include <openrj/openrj.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* alloca */
#if defined(__GNUC__)
# ifdef alloca
#  undef alloca
# endif /* !alloca */
# define alloca             __builtin_alloca
#elif defined(WIN32)
# include <malloc.h>
# ifndef alloca
#  define alloca            _alloca
# endif /* !alloca */
#else /* ? OS */
# include <alloca.h>
#endif /* OS */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void usage(int bExit, char const *reason, int iInvalidArg, int argc, char **argv);
static int  run_unittests(void);

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
    int         iRet        =   0;
    int         bVerbose    =   1;
    char const  *testFile   =   NULL;


#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    /* for(i=0;i < 1000000000;) {} */

    { int i; for(i = 1; i < argc; ++i)
    {
        const char  *const  arg =   argv[i];

        if(arg[0] == '-')
        {
            if(arg[1] == '-')
            {
                if( 0 == strcmp("unittest", arg + 2) ||
                    0 == strcmp("unittests", arg + 2))
                {
                    return run_unittests();
                }
                else
                {
                    /* -- arguments */
                    usage(1, "Invalid argument(s) specified", i, argc, argv);
                }
            }
            else
            {
                /* - arguments */
                switch(arg[1])
                {
                    case    '?':
                        usage(1, NULL, -1, argc, argv);
                        break;
                    case    's':
                        bVerbose    =   0;
                        break;
                    case    'v':
                        bVerbose    =   1;
                        break;
                    default:
                        usage(1, "Invalid argument(s) specified", i, argc, argv);
                        break;
                }
            }
        }
        else if(NULL == testFile)
        {
            testFile = arg;
        }
        else
        {
            /* other arguments */
            usage(1, "Invalid argument(s) specified", i, argc, argv);
        }
    }}

    /* . */
    if(NULL == testFile)
    {
        usage(1, "Must specify test file", -1, argc, argv);
    }
    else
    {
        ORJDatabase const   *database;
        ORJError            error;
        unsigned            orjFlags            =   ORJ_FLAG_ELIDEBLANKRECORDS;
        ORJRC               rc                  =   ORJ_ReadDatabaseA(testFile, NULL, orjFlags, &database, &error);
        unsigned            numPatterns         =   0;
        unsigned            numParseFailures    =   0;
        unsigned            numTests            =   0;
        unsigned            numMatches          =   0;
        unsigned            numNonMatches       =   0;
        unsigned            numFailedMatches    =   0;
        unsigned            numFailedNonMatches =   0;

        if(ORJ_RC_SUCCESS != rc)
        {
            char    sz[201];

            ORJ_FormatErrorA(&sz[0], 201, rc, &error, "Failed to load test file %s; %E", testFile);

            fprintf(stderr, "%s\n", sz);
        }
        else
        {
            size_t  maxTestStrLen = 0;

            { size_t i; for(i = 0; i < database->numFields; ++i)
            {
                if(database->fields[i].value.len > maxTestStrLen)
                {
                    maxTestStrLen = database->fields[i].value.len;
                }
            }}

            { size_t i; for(i = 0; i < database->numRecords; ++i)
            {
                ORJRecordA const    *record     =   &database->records[i];

                /* Lookup the 'Pattern' field
                 */
                ORJFieldA const     *pattern    =   ORJ_Record_FindFieldByNameA(record, "Pattern", NULL);
                ORJFieldA const     *Flags      =   ORJ_Record_FindFieldByNameA(record, "Flags", NULL);
                unsigned            flags       =   (NULL != Flags) ? strtoul(Flags->value.ptr, NULL, 0) : 0;

                if(NULL == pattern)
                {
                    fprintf(stderr, "Test file record #%d (of non-empty records) does not contain 'Pattern' field\n", (int)i);
                }
                else
                {
                    shwild_handle_t hCompiledPattern;
                    int             res =   shwild_compile_pattern(pattern->value.ptr, flags, &hCompiledPattern);

                    ++numPatterns;

                    if(res < 0)
                    {
                        fprintf(stderr, "Failed to compile pattern \"%.*s\"; shwild_compile_pattern() returned: %d\n", (int)pattern->value.len, pattern->value.ptr, res);

                        ++numParseFailures;
                    }
                    else
                    {
                        /* Test matches */
                        ORJFieldA const *test;

                        fprintf(stdout, "\nTesting pattern: \"%.*s\"\n", (int)pattern->value.len, pattern->value.ptr);

                        fprintf(stdout, " Matches:\n");
                        for(test = NULL; NULL != (test = ORJ_Record_FindNextFieldA(record, test, "Match", NULL)); )
                        {
                            res = shwild_match_pattern(hCompiledPattern, test->value.ptr);

                            if( bVerbose ||
                                0 == res)
                            {
                                fprintf(stdout, "  %-*s - %s\n", (int)maxTestStrLen, test->value.ptr, ((0 == res) ? "pass" : (++numFailedMatches, "FAIL")));
                            }

                            ++numTests;
                            ++numMatches;
                        }

                        fprintf(stdout, " Non-matches:\n");
                        for(test = NULL; NULL != (test = ORJ_Record_FindNextFieldA(record, test, "NonMatch", NULL)); )
                        {
                            res = shwild_match_pattern(hCompiledPattern, test->value.ptr);

                            if( bVerbose ||
                                0 != res)
                            {
                                fprintf(stdout, "  %-*s - %s\n", (int)maxTestStrLen, test->value.ptr, ((0 != res) ? "pass" : (++numFailedNonMatches, "FAIL")));
                            }

                            ++numTests;
                            ++numNonMatches;
                        }

                        shwild_destroy_pattern(hCompiledPattern);
                    }
                }
            }}

            ORJ_FreeDatabaseA(database);

            fprintf(stdout, "\nTest complete; results:\n");
            fprintf(stdout, "#patterns:                %4u\n", numPatterns);
            fprintf(stdout, "#pattern parse failures:  %4u\n", numParseFailures);
            fprintf(stdout, "#tests:                   %4u\n", numTests);
            fprintf(stdout, "#matches:                 %4u\n", numMatches);
            fprintf(stdout, "#matches failed:          %4u\n", numFailedMatches);
            fprintf(stdout, "#non-matches:             %4u\n", numNonMatches);
            fprintf(stdout, "#non-matches failed:      %4u\n", numFailedNonMatches);
            fprintf(stdout, "--------------------      ----\n");
            fprintf(stdout, "#tests passed:            %4u\n", numMatches + numNonMatches);
            fprintf(stdout, "#tests failed:            %4u\n", numFailedMatches + numFailedNonMatches);
            fprintf(stdout, "#patterns not parsed:     %4u\n", numParseFailures);
            fprintf(stdout, "\n");

            if(numFailedMatches + numFailedNonMatches)
            {
                iRet = EXIT_FAILURE;
            }
        }
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);

    _CrtMemDumpStatistics(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return iRet;
}

/* ////////////////////////////////////////////////////////////////////////// */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    /* Determine the output stream, and the executable name */
    FILE    *stm    =   (NULL == reason) ? stdout : stderr;
    int     i;
    char    *EXE_NAME   =   strcpy((char*)alloca(1 + strlen(argv[0])), argv[0]);
    char    *p;

    if(NULL != (p = strrchr(EXE_NAME, '\\')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    if(NULL != (p = strrchr(EXE_NAME, '/')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }


    fprintf(stm, "\n");
    fprintf(stm, "  test_c_1\n\n");
    fprintf(stm, "\n");

    if(NULL != reason)
    {
        fprintf(stm, "  Error: %s\n", reason);
        fprintf(stm, "\n");
    }

    if(0 < invalidArg)
    {
        fprintf(stm, "  First invalid argument #%d: %s\n", invalidArg, argv[invalidArg]);
        fprintf(stm, "  Arguments were (first bad marked *):\n\n");

        for(i = 1; i < argc; ++i)
        {
            fprintf(stm, "  %s%s\n", (i == invalidArg) ? "* " : "  ", argv[i]);
        }
        fprintf(stm, "\n");
    }

    fprintf(stm, "  USAGE 1: %s [-s | -v] <test-patterns>\n", EXE_NAME);
    fprintf(stm, "\n");
    fprintf(stm, "    -v              - verbose output\n");
    fprintf(stm, "    -s              - succinct output; default\n");
    fprintf(stm, "    <test-patterns> - Open-RJ (http://openrj.org/) file containing\n");
    fprintf(stm, "                      test cases\n");
    fprintf(stm, "\n");
    fprintf(stm, "    Runs given test suite, producing success/fail statistics\n");
    fprintf(stm, "\n");
    fprintf(stm, "  USAGE 2: %s --unittest\n", EXE_NAME);
    fprintf(stm, "\n");
    fprintf(stm, "    Runs internal tests, returning 0 if all succeed, non-0 otherwise\n");
    fprintf(stm, "\n");
    fprintf(stm, "  USAGE 3: %s -?\n", EXE_NAME);
    fprintf(stm, "\n");
    fprintf(stm, "    Displays this help\n");
    fprintf(stm, "\n");

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

static int run_unittests()
{
    /* TODO: Implement this */

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */
