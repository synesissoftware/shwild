/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.shwild_match.c
 *
 * Purpose: Unit-tests for shwild C-API
 *
 * Created: 27th April 2006
 * Updated: 30th August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* shwild Header Files */
#include <shwild/shwild.h>

/* BDUT Header Files */
#include <bdut/bdut.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    {
        shwild_match("[ADFJMNOS][abceglnoprtuvy]", "Ja", 0);
    }

    /* Matching literal strings. */
    {
        const char  pattern[]   =   "abcd";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "ABCD", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "ABCD", SHWILD_F_IGNORE_CASE));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Using wildcards. */
    {
        const char  pattern[]   =   "a*c?";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a*c?", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abbbbbbbbcd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "acd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abdc", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abc?", 0));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Using escaped characters. */
    {
        const char  pattern[]   =   "a\\*c\\?";

        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a*c?", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "a\\*c\\?", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abbbbbbbbcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "acd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abdc", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abc?", 0));

        /* All of the following search for 'a' followed by '\\' followed by any
         * number of any character, following by '\\' followed by one of any
         * character.
         */
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a\\*c\\?", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges. */
    {
        const char  pattern[]   =   "a[bc]c[defghijklm]";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "accm", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "a[bc]c[defghijklm]", 0));

        /* All of the following the given pattern as if it is a
         * literal string.
         */
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a[bc]c[defghijklm]", SHWILD_F_SUPPRESS_RANGE_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[d-m]";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "accm", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", 0));

        /* All the following search for 'a' followed by 'b' or '-' or 'd',
         * followed by 'c' followed by 'd' or '-' or 'm'
         */
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a-cd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "accl", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with high-low continuum. */
    {
        const char  pattern[]   =   "a[c-b]c[m-d]";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "accm", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", 0));

        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[b-C]c[d-M]";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "aCcJ", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", 0));

        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aCcJ", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[*]c[?]";

        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a*c?", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abbbbbbbbcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "acd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abdc", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abc?", 0));

        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "a*c?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abbbbbbbbcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "acd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abdc", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abc?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with continuum and leading/trailing hyphens. */
    {
        const char  pattern[]   =   "a[-a-c]c[d-]";

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "acc-", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "a-c-", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abce", 0));

        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "acc-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "a-c-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abce", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with inverse continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[^d-m]";

        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcd", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcc", 0));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "accm", 0));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcn", 0));

        BDUT_ASSERT_EQ(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcc", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_EQ(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        BDUT_ASSERT_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }


    return BDUT_TESTS_PASSED(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

