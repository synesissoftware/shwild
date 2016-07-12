/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_c_1.c
 *
 * Purpose:     Implementation file for the example_c_1 project.
 *
 * Created:     27th April 2006
 * Updated:     20th January 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software. 
 *
 *              This source code is provided by Synesis Software Pty Ltd "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Synesis Software Pty Ltd be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage. 
 *
 *              Neither the name of Synesis Software Pty Ltd nor the names of
 *              any subdivisions, employees or agents of Synesis Software Pty
 *              Ltd, nor the names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission. 
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* shwild Header Files */
#include <shwild/shwild.h>
#include <shwild/implicit_link.h>

/* Standard C Header Files */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////////// */

int main(void)
{
    {
        shwild_match("[ADFJMNOS][abceglnoprtuvy]", "Ja", 0);
    }

    /* Matching literal strings. */
    {
        const char  pattern[]   =   "abcd";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 != shwild_match(pattern, "ABCD", 0));
        assert(0 == shwild_match(pattern, "ABCD", SHWILD_F_IGNORE_CASE));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Using wildcards. */
    {
        const char  pattern[]   =   "a*c?";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 == shwild_match(pattern, "a*c?", 0));
        assert(0 == shwild_match(pattern, "abbbbbbbbcd", 0));
        assert(0 == shwild_match(pattern, "acd", 0));
        assert(0 != shwild_match(pattern, "abdc", 0));
        assert(0 == shwild_match(pattern, "abc?", 0));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Using escaped characters. */
    {
        const char  pattern[]   =   "a\\*c\\?";

        assert(0 != shwild_match(pattern, "abcd", 0));
        assert(0 == shwild_match(pattern, "a*c?", 0));
        assert(0 != shwild_match(pattern, "a\\*c\\?", 0));
        assert(0 != shwild_match(pattern, "abbbbbbbbcd", 0));
        assert(0 != shwild_match(pattern, "acd", 0));
        assert(0 != shwild_match(pattern, "abdc", 0));
        assert(0 != shwild_match(pattern, "abc?", 0));

        /* All of the following search for 'a' followed by '\\' followed by any
         * number of any character, following by '\\' followed by one of any
         * character.
         */
        assert(0 != shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));
        assert(0 == shwild_match(pattern, "a\\*c\\?", SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges. */
    {
        const char  pattern[]   =   "a[bc]c[defghijklm]";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 != shwild_match(pattern, "aacd", 0));
        assert(0 == shwild_match(pattern, "accm", 0));
        assert(0 != shwild_match(pattern, "abcn", 0));
        assert(0 != shwild_match(pattern, "a[bc]c[defghijklm]", 0));

        /* All of the following the given pattern as if it is a
         * literal string.
         */
        assert(0 != shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 != shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 != shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 != shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_SUPPORT));
        assert(0 == shwild_match(pattern, "a[bc]c[defghijklm]", SHWILD_F_SUPPRESS_RANGE_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[d-m]";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 != shwild_match(pattern, "aacd", 0));
        assert(0 == shwild_match(pattern, "accm", 0));
        assert(0 != shwild_match(pattern, "abcn", 0));

        /* All the following search for 'a' followed by 'b' or '-' or 'd',
         * followed by 'c' followed by 'd' or '-' or 'm'
         */
        assert(0 == shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 == shwild_match(pattern, "a-cd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 == shwild_match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 != shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 == shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 != shwild_match(pattern, "accl", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));
        assert(0 != shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with high-low continuum. */
    {
        const char  pattern[]   =   "a[c-b]c[m-d]";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 != shwild_match(pattern, "aacd", 0));
        assert(0 == shwild_match(pattern, "accm", 0));
        assert(0 != shwild_match(pattern, "abcn", 0));

        assert(0 != shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild_match(pattern, "accd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));
        assert(0 != shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[b-C]c[d-M]";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 != shwild_match(pattern, "aacd", 0));
        assert(0 == shwild_match(pattern, "aCcJ", 0));
        assert(0 != shwild_match(pattern, "abcn", 0));

        assert(0 != shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        assert(0 != shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        assert(0 != shwild_match(pattern, "aCcJ", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));
        assert(0 != shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with cross-case continuum. */
    {
        const char  pattern[]   =   "a[*]c[?]";

        assert(0 != shwild_match(pattern, "abcd", 0));
        assert(0 == shwild_match(pattern, "a*c?", 0));
        assert(0 != shwild_match(pattern, "abbbbbbbbcd", 0));
        assert(0 != shwild_match(pattern, "acd", 0));
        assert(0 != shwild_match(pattern, "abdc", 0));
        assert(0 != shwild_match(pattern, "abc?", 0));

        assert(0 != shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild_match(pattern, "a*c?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild_match(pattern, "abbbbbbbbcd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild_match(pattern, "acd", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild_match(pattern, "abdc", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));
        assert(0 != shwild_match(pattern, "abc?", SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with continuum and leading/trailing hyphens. */
    {
        const char  pattern[]   =   "a[-a-c]c[d-]";

        assert(0 == shwild_match(pattern, "abcd", 0));
        assert(0 == shwild_match(pattern, "aacd", 0));
        assert(0 == shwild_match(pattern, "acc-", 0));
        assert(0 == shwild_match(pattern, "a-c-", 0));
        assert(0 != shwild_match(pattern, "abce", 0));

        assert(0 != shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild_match(pattern, "acc-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild_match(pattern, "a-c-", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));
        assert(0 != shwild_match(pattern, "abce", SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    /* Matching ranges with inverse continuum. */
    {
        const char  pattern[]   =   "a[b-c]c[^d-m]";

        assert(0 != shwild_match(pattern, "abcd", 0));
        assert(0 != shwild_match(pattern, "aacd", 0));
        assert(0 == shwild_match(pattern, "abcc", 0));
        assert(0 != shwild_match(pattern, "accm", 0));
        assert(0 == shwild_match(pattern, "abcn", 0));

        assert(0 == shwild_match(pattern, "abcd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 != shwild_match(pattern, "aacd", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 != shwild_match(pattern, "abcc", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 == shwild_match(pattern, "accm", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));
        assert(0 != shwild_match(pattern, "abcn", SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT));

        ((void)pattern);    /* Needed to silence false Borland warnings. */
    }

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */
