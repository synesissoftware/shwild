/* /////////////////////////////////////////////////////////////////////////////
 * File:        test_cpp_2.cpp
 *
 * Purpose:     C++ test file for the shwild library
 *
 * Created:     7th July 2005
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

/* Standard C++ Header Files */
#include <exception>

#ifdef __WATCOMC__
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */

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

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void usage(int bExit, char const *reason, int iInvalidArg, int argc, char **argv);
static int  run_unittests(void);

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char **argv)
{
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
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
        }
        else
        {
            /* other arguments */
            usage(1, "Invalid argument(s) specified", i, argc, argv);
        }
    }}

    return 0;
}

int main(int argc, char *argv[])
{
    try
    {
        return main_(argc, argv);
    }
    catch(std::exception &x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");
    }

    return EXIT_FAILURE;
}

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    /* Determine the output stream, and the executable name */
    FILE    *stm    =   (NULL == reason) ? stdout : stderr;
    int     i;
    char    *EXE_NAME   =   strcpy(static_cast<char*>(alloca(1 + strlen(argv[0]))), argv[0]);
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
    fprintf(stm, "  test_cpp_2\n\n");
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
    // TODO: Implement this

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */
