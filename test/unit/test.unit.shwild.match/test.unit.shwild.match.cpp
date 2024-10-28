/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.shwild.match.cpp
 *
 * Purpose: Unit-tests for shwild C++-API functions
 *
 * Created: 28th April 2006
 * Updated: 18th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* shwild Header Files */
#include <shwild/shwild.hpp>

/* BDUT Header Files */
#include <bdut/bdut.h>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

using std::cerr;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#if 0
#elif defined(__BORLANDC__)
# pragma warn -8004                 /* Suppresses: "'????' is assigned a value that is never used ..." */
#elif defined(__COMO__)
#elif defined(__DMC__)
#elif defined(__INTEL_COMPILER)
# pragma warning(disable : 981)     /* Suppresses: "operands are evaluated in unspecified order" */
#elif defined(_MSC_VER)
# pragma warning(disable : 4189)    /* Suppresses: "'????' : local variable is initialized but not referenced" */
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char* argv[])
{
    char const* const program_name = argv[0];


    /* Matching literal strings. */
    {
        const char  pattern[]   =   "abcd";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "ABCD", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "ABCD", SHWILD_F_IGNORE_CASE));
    }

    /* Using wildcards. */
    {
        const char  pattern[]   =   "a*c?";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a*c?", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abbbbbbbbcd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "acd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abdc", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abc?", 0));
    }

    /* Using escaped characters. */
    {
        const char  pattern[]   =   "a\\*c\\?";

        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a*c?", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "a\\*c\\?", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abbbbbbbbcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "acd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abdc", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abc?", 0));

        /* All of the following search for 'a' followed by '\\' followed by any
         * number of any character, following by '\\' followed by one of any
         * character.
         */
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a\\*c\\?", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
    }

    /* Matching ranges. */
    {
        const char  pattern[]   =   "a[bc]c[defghijklm]";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "accm", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "a[bc]c[defghijklm]", 0));

        /* All of the following the given pattern as if it is a
         * literal string.
         */
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a[bc]c[defghijklm]", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
    }

    /* Matching ranges with continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[d-m]";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "accm", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", 0));

        /* All the following search for 'a' followed by 'b' or '-' or 'd',
         * followed by 'c' followed by 'd' or '-' or 'm'
         */
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a-cd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "accl", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
    }

    /* Matching ranges with high-low continuum. */
    {
        const char  pattern[]   =   "a[c-b]c[m-d]";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "accm", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", 0));

        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[b-C]c[d-M]";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "aCcJ", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", 0));

        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aCcJ", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[*]c[?]";

        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a*c?", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abbbbbbbbcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "acd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abdc", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abc?", 0));

        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "a*c?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abbbbbbbbcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "acd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abdc", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abc?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
    }

    /* Matching ranges with continuum and leading/trailing hyphens. */
    {
        const char  pattern[]   =   "a[-a-c]c[d-]";

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "acc-", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "a-c-", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abce", 0));

        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "acc-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "a-c-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abce", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
    }

    /* Matching ranges with inverse continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[^d-m]";

        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcc", 0));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "accm", 0));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcn", 0));

        BDUT_ASSERT_EQ(0, shwild::match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcc", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild::match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_NE(0, shwild::match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
    }


    fprintf(stdout, "%s: ALL TESTS PASSED\n", program_name);


    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
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
    catch(std::exception& x)
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

