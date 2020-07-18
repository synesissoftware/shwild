/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.unit.shwild.match.cpp
 *
 * Purpose:     Implementation file for the test.unit.shwild.match project.
 *
 * Created:     28th April 2006
 * Updated:     18th July 2020
 *
 * Status:      Wizard-generated
 *
 * Copyright (c) 2006-2020, Matthew Wilson and Sean Kelly
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
#include <shwild/shwild.hpp>
#include <shwild/implicit_link.h>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

using std::cerr;
using std::endl;

/* Standard C Header Files */
#include <assert.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#if defined(__BORLANDC__)
# pragma warn -8004                 /* Suppresses: "'????' is assigned a value that is never used ..." */
#elif defined(__COMO__)
#elif defined(__DMC__)
#elif defined(__INTEL_COMPILER)
# pragma warning(disable : 981)     /* Suppresses: "operands are evaluated in unspecified order" */
#elif defined(_MSC_VER)
# pragma warning(disable : 4189)    /* Suppresses: "'????' : local variable is initialized but not referenced" */
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char * /* argv */[])
{
    /* Matching literal strings. */
    {
        const char  pattern[]   =   "abcd";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 != shwild::match(pattern, "ABCD", 0));
        assert(0 == shwild::match(pattern, "ABCD", SHWILD_F_IGNORE_CASE));
    }

    /* Using wildcards. */
    {
        const char  pattern[]   =   "a*c?";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 == shwild::match(pattern, "a*c?", 0));
        assert(0 == shwild::match(pattern, "abbbbbbbbcd", 0));
        assert(0 == shwild::match(pattern, "acd", 0));
        assert(0 != shwild::match(pattern, "abdc", 0));
        assert(0 == shwild::match(pattern, "abc?", 0));
    }

    /* Using escaped characters. */
    {
        const char  pattern[]   =   "a\\*c\\?";

        assert(0 != shwild::match(pattern, "abcd", 0));
        assert(0 == shwild::match(pattern, "a*c?", 0));
        assert(0 != shwild::match(pattern, "a\\*c\\?", 0));
        assert(0 != shwild::match(pattern, "abbbbbbbbcd", 0));
        assert(0 != shwild::match(pattern, "acd", 0));
        assert(0 != shwild::match(pattern, "abdc", 0));
        assert(0 != shwild::match(pattern, "abc?", 0));

        /* All of the following search for 'a' followed by '\\' followed by any
         * number of any character, following by '\\' followed by one of any
         * character.
         */
        assert(0 != shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
        assert(0 == shwild::match(pattern, "a\\*c\\?", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
    }

    /* Matching ranges. */
    {
        const char  pattern[]   =   "a[bc]c[defghijklm]";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 != shwild::match(pattern, "aacd", 0));
        assert(0 == shwild::match(pattern, "accm", 0));
        assert(0 != shwild::match(pattern, "abcn", 0));
        assert(0 != shwild::match(pattern, "a[bc]c[defghijklm]", 0));

        /* All of the following the given pattern as if it is a
         * literal string.
         */
        assert(0 != shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 != shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 != shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 != shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 == shwild::match(pattern, "a[bc]c[defghijklm]", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
    }

    /* Matching ranges with continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[d-m]";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 != shwild::match(pattern, "aacd", 0));
        assert(0 == shwild::match(pattern, "accm", 0));
        assert(0 != shwild::match(pattern, "abcn", 0));

        /* All the following search for 'a' followed by 'b' or '-' or 'd',
         * followed by 'c' followed by 'd' or '-' or 'm'
         */
        assert(0 == shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 == shwild::match(pattern, "a-cd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 == shwild::match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 != shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 == shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 != shwild::match(pattern, "accl", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 != shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
    }

    /* Matching ranges with high-low continuum. */
    {
        const char  pattern[]   =   "a[c-b]c[m-d]";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 != shwild::match(pattern, "aacd", 0));
        assert(0 == shwild::match(pattern, "accm", 0));
        assert(0 != shwild::match(pattern, "abcn", 0));

        assert(0 != shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild::match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[b-C]c[d-M]";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 != shwild::match(pattern, "aacd", 0));
        assert(0 == shwild::match(pattern, "aCcJ", 0));
        assert(0 != shwild::match(pattern, "abcn", 0));

        assert(0 != shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        assert(0 != shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        assert(0 != shwild::match(pattern, "aCcJ", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        assert(0 != shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[*]c[?]";

        assert(0 != shwild::match(pattern, "abcd", 0));
        assert(0 == shwild::match(pattern, "a*c?", 0));
        assert(0 != shwild::match(pattern, "abbbbbbbbcd", 0));
        assert(0 != shwild::match(pattern, "acd", 0));
        assert(0 != shwild::match(pattern, "abdc", 0));
        assert(0 != shwild::match(pattern, "abc?", 0));

        assert(0 != shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild::match(pattern, "a*c?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild::match(pattern, "abbbbbbbbcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild::match(pattern, "acd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild::match(pattern, "abdc", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild::match(pattern, "abc?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
    }

    /* Matching ranges with continuum and leading/trailing hyphens. */
    {
        const char  pattern[]   =   "a[-a-c]c[d-]";

        assert(0 == shwild::match(pattern, "abcd", 0));
        assert(0 == shwild::match(pattern, "aacd", 0));
        assert(0 == shwild::match(pattern, "acc-", 0));
        assert(0 == shwild::match(pattern, "a-c-", 0));
        assert(0 != shwild::match(pattern, "abce", 0));

        assert(0 != shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild::match(pattern, "acc-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild::match(pattern, "a-c-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild::match(pattern, "abce", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
    }

    /* Matching ranges with inverse continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[^d-m]";

        assert(0 != shwild::match(pattern, "abcd", 0));
        assert(0 != shwild::match(pattern, "aacd", 0));
        assert(0 == shwild::match(pattern, "abcc", 0));
        assert(0 != shwild::match(pattern, "accm", 0));
        assert(0 == shwild::match(pattern, "abcn", 0));

        assert(0 == shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 != shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 != shwild::match(pattern, "abcc", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 == shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 != shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int             iRet;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    try
    {
        iRet = main_(argc, argv);
    }
    catch(std::exception &x)
    {
        cerr << "Unhandled error: " << x.what() << endl;

        iRet = EXIT_FAILURE;
    }
    catch(...)
    {
        cerr << "Unhandled unknown error" << endl;

        iRet = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return iRet;
}

/* ///////////////////////////// end of file //////////////////////////// */

