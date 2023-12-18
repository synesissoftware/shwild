/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.shwild.pattern.cpp
 *
 * Purpose:     Implementation file for the test.unit.shwild.pattern project.
 *
 * Created:     28th April 2006
 * Updated:     18th December 2023
 *
 * Status:      Wizard-generated
 *
 * Copyright (c) 2006-2023, Matthew Wilson and Sean Kelly
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
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
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
 * ////////////////////////////////////////////////////////////////////// */


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

/* /////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char* /*argv*/[])
{
    /* Matching literal strings. */
    {
        const shwild::Pattern   pattern1("abcd");

        assert(pattern1.match("abcd"));
        assert(!pattern1.match("ABCD"));

        const shwild::Pattern   pattern2("abcd", SHWILD_F_IGNORE_CASE);

        assert(pattern2.match("ABCD"));
    }

    /* Using wildcards. */
    {
        const shwild::Pattern   pattern("a*c?");

        assert(pattern.match("abcd"));
        assert(pattern.match("a*c?"));
        assert(pattern.match("abbbbbbbbcd"));
        assert(pattern.match("acd"));
        assert(!pattern.match("abdc"));
        assert(pattern.match("abc?"));
    }

    /* Using escaped characters. */
    {
        const shwild::Pattern   pattern1("a\\*c\\?");

        assert(!pattern1.match("abcd"));
        assert(pattern1.match("a*c?"));
        assert(!pattern1.match("abbbbbbbbcd"));
        assert(!pattern1.match("acd"));
        assert(!pattern1.match("abdc"));
        assert(!pattern1.match("abc?"));

        /* All of the following search for 'a' followed by '\\' followed by any
         * number of any character, following by '\\' followed by one of any
         * character.
         */
        const shwild::Pattern   pattern2("a\\*c\\?", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE);

        assert(!pattern2.match("abcd"));
        assert(pattern2.match("a\\*c\\?"));
    }

    /* Matching ranges. */
    {
        const shwild::Pattern   pattern1("a[bc]c[defghijklm]");

        assert(pattern1.match("abcd"));
        assert(!pattern1.match("aacd"));
        assert(pattern1.match("accm"));
        assert(!pattern1.match("abcn"));
        assert(!pattern1.match("a[bc]c[defghijklm]"));

        /* All of the following the given pattern as if it is a
         * literal string.
         */
        const shwild::Pattern   pattern2("a[bc]c[defghijklm]", SHWILD_F_SUPPRESS_RANGE_SUPPORT);

        assert(!pattern2.match("abcd"));
        assert(!pattern2.match("aacd"));
        assert(!pattern2.match("accm"));
        assert(!pattern2.match("abcn"));
        assert(pattern2.match("a[bc]c[defghijklm]"));
    }

    /* Matching ranges with continuum. */
    {
        const shwild::Pattern   pattern1("a[b-c]c[d-m]");

        assert(pattern1.match("abcd"));
        assert(!pattern1.match("aacd"));
        assert(pattern1.match("accm"));
        assert(!pattern1.match("abcn"));

        const shwild::Pattern   pattern2("a[b-c]c[d-m]", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT);

        assert(pattern2.match("abcd"));
        assert(pattern2.match("a-cd"));
        assert(pattern2.match("accd"));
        assert(!pattern2.match("aacd"));
        assert(pattern2.match("accm"));
        assert(!pattern2.match("accl"));
        assert(!pattern2.match("abcn"));
    }

    /* Matching ranges with high-low continuum. */
    {
        const shwild::Pattern   pattern1("a[c-b]c[m-d]");

        assert(pattern1.match("abcd"));
        assert(!pattern1.match("aacd"));
        assert(pattern1.match("accm"));
        assert(!pattern1.match("abcn"));

        try
        {
            const shwild::Pattern   pattern2("a[c-b]c[m-d]", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT);

            assert(!"Should not get here, since the continuum is high->low");

            assert(!pattern2.match("aacd"));
            assert(!pattern2.match("abcd"));
            assert(!pattern2.match("accd"));
            assert(!pattern2.match("accm"));
            assert(!pattern2.match("abcn"));
        }
        catch(shwild::PatternException &)
        {
        }
    }

    /* Matching ranges with cross-case continuum. */
    {
        const shwild::Pattern   pattern1("a[b-C]c[d-M]");

        assert(pattern1.match("abcd"));
        assert(!pattern1.match("aacd"));
        assert(pattern1.match("aCcJ"));
        assert(!pattern1.match("abcn"));

        try
        {
            const shwild::Pattern   pattern2("a[b-C]c[d-M]", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT);

            assert(!"Should not get here, since the continuum is cross-case");

            assert(!pattern2.match("abcd"));
            assert(!pattern2.match("aacd"));
            assert(!pattern2.match("aCcJ"));
            assert(!pattern2.match("abcn"));
        }
        catch(shwild::PatternException &)
        {
        }
    }

    /* Matching ranges with cross-case continuum. */
    {
        const shwild::Pattern   pattern1("a[*]c[?]");

        assert(!pattern1.match("abcd"));
        assert(pattern1.match("a*c?"));
        assert(!pattern1.match("abbbbbbbbcd"));
        assert(!pattern1.match("acd"));
        assert(!pattern1.match("abdc"));
        assert(!pattern1.match("abc?"));

        try
        {
            const shwild::Pattern   pattern2("a[*]c[?]", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT);

            assert(!"Should not get here, since the range contains literal wildcards");

            assert(!pattern2.match("abcd"));
            assert(!pattern2.match("a*c?"));
            assert(!pattern2.match("abbbbbbbbcd"));
            assert(!pattern2.match("acd"));
            assert(!pattern2.match("abdc"));
            assert(!pattern2.match("abc?"));
        }
        catch(shwild::PatternException &)
        {
        }
    }

    /* Matching ranges with continuum and leading/trailing hyphens. */
    {
        const shwild::Pattern   pattern1("a[-a-c]c[d-]");

        assert(pattern1.match("abcd"));
        assert(pattern1.match("aacd"));
        assert(pattern1.match("acc-"));
        assert(pattern1.match("a-c-"));
        assert(!pattern1.match("abce"));

        try
        {
            const shwild::Pattern   pattern2("a[-a-c]c[d-]", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT);

            assert(!"Should not get here, since the range contains leading/trailing hyphens");

            assert(!pattern2.match("abcd"));
            assert(!pattern2.match("aacd"));
            assert(!pattern2.match("acc-"));
            assert(!pattern2.match("a-c-"));
            assert(!pattern2.match("abce"));
        }
        catch(shwild::PatternException &)
        {
        }
    }

    /* Matching ranges with inverse continuum. */
    {
        const shwild::Pattern   pattern1("a[b-c]c[^d-m]");

        assert(!pattern1.match("abcd"));
        assert(!pattern1.match("aacd"));
        assert(pattern1.match("abcc"));
        assert(!pattern1.match("accm"));
        assert(pattern1.match("abcn"));

        try
        {
            const shwild::Pattern   pattern2("a[b-c]c[^d-m]", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT);

            assert(pattern2.match("abcd"));
            assert(!pattern2.match("aacd"));
            assert(!pattern2.match("abcc"));
            assert(pattern2.match("accm"));
            assert(!pattern2.match("abcn"));
        }
        catch(shwild::PatternException &)
        {
        }
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

