/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.shwild_match.c
 *
 * Purpose: Unit-tests for shwild C-API
 *
 * Created: 27th April 2006
 * Updated: 11th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* shwild Header Files */
#include <shwild/shwild.h>
#include <shwild//bdt/bdt.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    {
        shwild_match("[ADFJMNOS][abceglnoprtuvy]", "Ja", 0);
    }

    /* Matching literal strings. */
    {
        const char  pattern[]   =   "abcd";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "ABCD", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "ABCD", SHWILD_F_IGNORE_CASE));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Using wildcards. */
    {
        const char  pattern[]   =   "a*c?";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a*c?", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abbbbbbbbcd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "acd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abdc", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abc?", 0));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Using escaped characters. */
    {
        const char  pattern[]   =   "a\\*c\\?";

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a*c?", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "a\\*c\\?", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abbbbbbbbcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "acd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abdc", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abc?", 0));

        /* All of the following search for 'a' followed by '\\' followed by any
         * number of any character, following by '\\' followed by one of any
         * character.
         */
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a\\*c\\?", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges. */
    {
        const char  pattern[]   =   "a[bc]c[defghijklm]";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "accm", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "a[bc]c[defghijklm]", 0));

        /* All of the following the given pattern as if it is a
         * literal string.
         */
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a[bc]c[defghijklm]", SHWILD_F_SUPPRESS_RANGE_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[d-m]";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "accm", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", 0));

        /* All the following search for 'a' followed by 'b' or '-' or 'd',
         * followed by 'c' followed by 'd' or '-' or 'm'
         */
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a-cd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "accl", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with high-low continuum. */
    {
        const char  pattern[]   =   "a[c-b]c[m-d]";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "accm", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", 0));

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[b-C]c[d-M]";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "aCcJ", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", 0));

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aCcJ", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[*]c[?]";

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a*c?", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abbbbbbbbcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "acd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abdc", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abc?", 0));

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "a*c?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abbbbbbbbcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "acd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abdc", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abc?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with continuum and leading/trailing hyphens. */
    {
        const char  pattern[]   =   "a[-a-c]c[d-]";

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "aacd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "acc-", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "a-c-", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abce", 0));

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "acc-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "a-c-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abce", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with inverse continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[^d-m]";

        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcd", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcc", 0));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "accm", 0));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcn", 0));

        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcc", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        SHWILD_BDT_CHECK_EQ(0, shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        SHWILD_BDT_CHECK_NE(0, shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

