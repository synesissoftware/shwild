/* /////////////////////////////////////////////////////////////////////////
 * File:    bdut/bdut.h
 *
 * Purpose: Brain-Dead Unit-Testing
 *
 * Created: 18th July 2020
 * Updated: 13th May 2025
 *
 * Home:    http://github.com/synesissoftware/BDUT
 *
 * Copyright (c) 2020-2025, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** @file bdut/bdut.h [C/C++] Brain-Dead Unit-Testing
 */

#ifndef BDUT_INCL_BDUT_H_BDUT
#define BDUT_INCL_BDUT_H_BDUT


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef BDUT_DOCUMENTATION_SKIP_SECTION
# define BDUT_VER_BDUT_H_BDUT_MAJOR     2
# define BDUT_VER_BDUT_H_BDUT_MINOR     1
# define BDUT_VER_BDUT_H_BDUT_REVISION  4
# define BDUT_VER_BDUT_H_BDUT_EDIT      16
#endif /* !BDUT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * version
 */

/** \def BDUT_VER_MAJOR
 * The major version number of **BDUT**
 */

/** \def BDUT_VER_MINOR
 * The minor version number of **BDUT**
 */

/** \def BDUT_VER_REVISION
 * The revision version number of **BDUT**
 */

/** \def BDUT_VER
 * The current composite version number of **BDUT**
 */

#define BDUT_VER_MAJOR                                      0
#define BDUT_VER_MINOR                                      3
#define BDUT_VER_PATCH                                      2
#define BDUT_VER_ALPHABETA                                  0xff

#define BDUT_VER \
    (0\
        |   (   BDUT_VER_MAJOR      << 24   ) \
        |   (   BDUT_VER_MINOR      << 16   ) \
        |   (   BDUT_VER_PATCH      <<  8   ) \
        |   (   BDUT_VER_ALPHABETA  <<  0   ) \
    )

#define BDUT_VER_REVISION                                   BDUT_VER_PATCH


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#if defined(__cplusplus) && \
    __cplusplus >= 201402L

# include <cstddef>
# include <cstdio>
# include <cstdlib>
# include <cstring>
#else

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#endif

#ifdef _WIN32

# include <io.h>
#else

# include <unistd.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** @def BDUT_ASSERT_TRUE(expr)
 *
 * @brief Asserts that the expression is truey
 */

/** @def BDUT_ASSERT_FALSE(expr)
 *
 * @brief Asserts that the expression is falsey
 */

#define BDUT_ASSERT_TRUE(expr)                              BDUT_ASSERT_(expr, #expr " was not true")
#define BDUT_ASSERT_FALSE(expr)                             BDUT_ASSERT_(!(expr), #expr " was not false")

/** @def BDUT_ASSERT_EQ(expected, actual)
 *
 * @brief Asserts the the \c actual value is equal to the \c expected value
 *
 * @param expected The expected value
 * @param actual The actual value
 */

/** @def BDUT_ASSERT_NE(expected, actual)
 *
 * @brief Asserts the the \c actual value is not equal to the \c expected value
 *
 * @param expected The expected value
 * @param actual The actual value
 */

#define BDUT_ASSERT_EQ(expected, actual)                    BDUT_CHECK_COMPARE_((expected), (actual), ==, "actual value of `" #actual "` not equal-to expected value `" #expected "`")
#define BDUT_ASSERT_NE(expected, actual)                    BDUT_CHECK_COMPARE_((expected), (actual), !=, "actual value of `" #actual "` not unequal-to expected value `" #expected "`")

/** @def BDUT_ASSERT_GE(expected, actual)
 *
 * @brief Asserts the the \c actual value is greater than or equal to the \c expected value
 *
 * @param expected The expected value
 * @param actual The actual value
 */

/** @def BDUT_ASSERT_GT(expected, actual)
 *
 * @brief Asserts the the \c actual value is greater than the \c expected value
 *
 * @param expected The expected value
 * @param actual The actual value
 */

/** @def BDUT_ASSERT_LE(expected, actual)
 *
 * @brief Asserts the the \c actual value is less than or equal to the \c expected value
 *
 * @param expected The expected value
 * @param actual The actual value
 */

/** @def BDUT_ASSERT_LT(expected, actual)
 *
 * @brief Asserts the the \c actual value is less than the \c expected value
 *
 * @param expected The expected value
 * @param actual The actual value
 */

#define BDUT_ASSERT_GE(expected, actual)                    BDUT_CHECK_COMPARE_((expected), (actual), >=, "actual value of `" #actual "` not greater-than-or-equal-to expected value `" #expected "`")
#define BDUT_ASSERT_GT(expected, actual)                    BDUT_CHECK_COMPARE_((expected), (actual), >, "actual value of `" #actual "` not greater-than expected value `" #expected "`")
#define BDUT_ASSERT_LE(expected, actual)                    BDUT_CHECK_COMPARE_((expected), (actual), <=, "actual value of `" #actual "` not less-than-or-equal-to expected value `" #expected "`")
#define BDUT_ASSERT_LT(expected, actual)                    BDUT_CHECK_COMPARE_((expected), (actual), <, "actual value of `" #actual "` not less-than expected value `" #expected "`")

/** @def BDUT_ASSERT_STRING_CONTAINS(needle, haystack)
 *
 * @brief Asserts the the \c needle string found within the \c haystack
 *   string
 *
 * @param needle The string to be found within \c haystack
 * @param haystack The string in which to find \c needle
 *
 * @note The parameters are first \c needle (the expected value) and
 *   then \c haystack (the actual value), for consistency with the other
 *   assertions
 */

#define BDUT_ASSERT_STRING_CONTAINS(needle, haystack)       ( !BDUT_strcontains_(haystack, needle) ? BDUT_report_string_contains_failure_and_abort_(__FILE__, __LINE__, BDUT_FUNCTION_, needle, haystack) : BDUT_STATIC_CAST_(void, 0) )


/* /////////////////////////////////////////////////////////////////////////
 * macros (internal)
 */

#ifndef BDUT_DOCUMENTATION_SKIP_SECTION

/** @def BDUT_ASSERT_(expr, msg)
 *
 * @brief TBC.
 */

/** @def BDUT_CHECK_COMPARE_(expected, actual, op, msg)
 *
 * @brief TBC.
 */

/** @def BDUT_INLINE_
 *
 * @brief TBC.
 */

/** @def BDUT_NUM_ELEMENTS_(ar)
 *
 * @brief Compile-time evaluation of the size of an array.
 *
 * @note Implemented in terms of `std::size<>()` if C++17+
 */

/** @def BDUT_STATIC_CAST_(t, v)
 *
 * @brief TBC.
 */


# define BDUT_ASSERT_(expr, msg)                            ( (!(expr)) ? BDUT_report_assertion_failure_and_abort_(__FILE__, __LINE__, BDUT_FUNCTION_, #expr, msg) : BDUT_STATIC_CAST_(void, 0) )

# define BDUT_CHECK_COMPARE_(expected, actual, op, msg)     BDUT_ASSERT_((expected) op (actual), msg)




#if 0
# elif defined(__BORLANDC__) && (__BORLANDC__ & 0xfff0) >= 0x0620
#  define BDUT_FUNCTION_                                    __FUNC__
# elif defined(__clang__)
#  define BDUT_FUNCTION_                                    __func__
# elif defined(__COMO__)
#  define BDUT_FUNCTION_                                    __FUNCTION__
# elif defined(__DMC__) && __DMC__ >= 0x850
#  define BDUT_FUNCTION_                                    __FUNCTION__
# elif defined(__GNUC__)
#  define BDUT_FUNCTION_                                    __func__
# elif defined(__INTEL_COMPILER) && __INTEL_COMPILER >= 700
#  define BDUT_FUNCTION_                                    __FUNCTION__
# elif defined(__MWERKS__) && (__MWERKS__ & 0xFF00) >= 0x3000
#  define BDUT_FUNCTION_                                    __FUNCTION__
# elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#  define BDUT_FUNCTION_                                    __func__
# elif defined(__WATCOMC__) && __WATCOMC__ >= 1240
#  define BDUT_FUNCTION_                                    __FUNCTION__
# elif defined(_MSC_VER) && _MSC_VER >= 1300
#  define BDUT_FUNCTION_                                    __FUNCTION__
#else /* ? compiler */
#  define BDUT_FUNCTION_                                    ""
#endif /* compiler */


# if defined(__cplusplus) && \
     __cplusplus >= 201703L

#  include <string>
#  define BDUT_NUM_ELEMENTS_(ar)                            (std::size(ar))
# else

#  if defined(__DMC__)

#   define BDUT_NUM_ELEMENTS_(ar)                           ((sizeof(ar) / sizeof((ar)[0])))
#  else

#   define BDUT_NUM_ELEMENTS_(ar)                           ((sizeof(ar) / sizeof(0[(ar)])))
#  endif
# endif

# ifdef __cplusplus

#  define BDUT_INLINE_                                      inline
#  define BDUT_STATIC_CAST_(t, v)                           static_cast<t>(v)
# else

#  if 1 && \
      defined(__STDC_VERSION__) && \
      __STDC_VERSION__ >= 199901L &&\
      !defined(__clang__) && \
      1

#   define BDUT_INLINE_                                     static inline
# else

#   define BDUT_INLINE_                                     static
#  endif
#  define BDUT_STATIC_CAST_(t, v)                           ((t)(v))
# endif
#endif /* !BDUT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * functions (implementation)
 */

#ifndef BDUT_DOCUMENTATION_SKIP_SECTION

# if 1 && \
     !defined(__cplusplus) && \
     defined(__clang__) && \
     1

static
void
BDUT_reference_all_impl_functions_(void);
# endif

BDUT_INLINE_
int
BDUT_isatty_(
    FILE* stm
)
{
#ifdef _WIN32

    return _isatty(_fileno(stm));
#else

    return isatty(fileno(stm));
#endif
}


/** @brief Determines whether \c needle is found within \c haystack
 *
 * @param haystack The string in which to find \c needle
 * @param needle The string to be found within \c haystack
 *
 * @note The return value is truthy (i.e 0 is falsey, every other value is
 *   truey)
 */
BDUT_INLINE_
int
BDUT_strcontains_(
    char const* haystack
,   char const* needle
)
{
# if defined(__cplusplus) && \
     __cplusplus >= 201402L

    using std::strstr;
# endif

    if (NULL == haystack)
    {
        haystack = "";
    }
    if (NULL == needle)
    {
        needle = "";
    }

    return NULL != strstr(haystack, needle);
}

/** @brief TBC
 *
 * @param file The source file
 * @param line The source line
 * @param function The source function. May be NULL if the compiler is not
 *  recognised to support function identification
 * @param expr The expression. Currently unused
 * @param message The message
 */
BDUT_INLINE_
void
BDUT_report_assertion_failure_and_abort_(
    char const*     file
,   int             line
,   char const*     function
,   char const*     expr
,   char const*     message
)
{
# if defined(__cplusplus) && \
    __cplusplus >= 201402L

    using std::exit;
    using std::fprintf;
# endif

#if  1 && \
     !defined(__cplusplus) && \
     defined(__clang__) && \
     1

    ((void)&BDUT_reference_all_impl_functions_);
# endif

    char const* clr_pre = "";
    char const* clr_post = "";

    if (BDUT_isatty_(stdout))
    {
        clr_pre = "\x1B[1;31m";
        clr_post = "\033[0m";
    }

    ((void)&expr);

    if (NULL == function ||
        '\0' == function[0])
    {
        fprintf(
            stderr
        ,   "ASSERTION FAILURE:\n\n%s:%d: %sassertion failed%s: %s\n"
        ,   file
        ,   line
        ,   clr_pre
        ,   clr_post
        ,   message
        );
    }
    else
    {
        fprintf(
            stderr
        ,   "ASSERTION FAILURE:\n\n%s:%d:%s: %sassertion failed%s: %s\n"
        ,   file
        ,   line
        ,   function
        ,   clr_pre
        ,   clr_post
        ,   message
        );
    }

    exit(1);
}

/** @brief TBC
 *
 * @param file The source file
 * @param line The source line
 * @param function The source function. May be NULL if the compiler is not
 *  recognised to support function identification
 * @param needle The string to be found within \c haystack
 * @param haystack The string in which to find \c needle
 */
BDUT_INLINE_
void
BDUT_report_string_contains_failure_and_abort_(
    char const*     file
,   int             line
,   char const*     function
,   char const*     needle
,   char const*     haystack
)
{
# if defined(__cplusplus) && \
     __cplusplus >= 201402L

    using std::size_t;
    using std::snprintf;
    using std::strlen;
# endif

    if (NULL == haystack)
    {
        haystack = "";
    }
    if (NULL == needle)
    {
        needle = "";
    }

    {
        size_t const     needle_length   =   (NULL == needle) ? 0 : strlen(needle);
        size_t const     haystack_length =   (NULL == haystack) ? 0 : strlen(haystack);

        /* build a message, ensuring it cannot overflow the fixed stack buffer */

        const char  ellipsis[] = "...";
        const char  fmt[] = "actual string '%.*s%.*s' does not contain search string '%.*s%.*s'";
        char        message[1000];

        int const   cch_fmt     = BDUT_NUM_ELEMENTS_(fmt) - 1;
        int const   cch_message = BDUT_NUM_ELEMENTS_(message);

        /* NOTE: all lengths are `int` because that's required by `"%.*s"` and thus save on casting */

        int         width_needle        =   BDUT_STATIC_CAST_(int, needle_length);
        int         width_haystack      =   BDUT_STATIC_CAST_(int, haystack_length);
        int         width_e_needle      =   0;
        int         width_e_haystack    =   0;

        if (((cch_fmt - 8) + width_needle + width_e_needle + width_haystack + width_e_haystack + 1) > cch_message)
        {
            int excess = ((cch_fmt - 8) + width_needle + width_e_needle + width_haystack + width_e_haystack + 1) - cch_message;

            if (excess > 0)
            {
                /* try taking it from the haystack only */

                if (width_haystack > 2 * excess + 3)
                {
                    width_haystack -= excess + 3;
                    width_e_haystack = 3;

                    excess = ((cch_fmt - 8) + width_needle + width_e_needle + width_haystack + width_e_haystack + 1) - cch_message;
                }
            }

            if (excess > 0)
            {
                /* try taking it from the needle only */

                if (width_needle > 5 + excess + 3)
                {
                    width_needle -= excess + 3;
                    width_e_needle = 3;

                    excess = ((cch_fmt - 8) + width_needle + width_e_needle + width_haystack + width_e_haystack + 1) - cch_message;
                }
            }

            if (excess > 0)
            {
                /* try taking it from both equally */

                int half_excess = (1 + excess) / 2;

                if (width_needle > (1 + half_excess + 3) &&
                    width_haystack > (1 + half_excess + 3))
                {
                    width_needle -= half_excess + 3;
                    width_e_needle = 3;
                    width_haystack -= half_excess + 3;
                    width_e_haystack = 3;

                    excess = ((cch_fmt - 8) + width_needle + width_e_needle + width_haystack + width_e_haystack + 1) - cch_message;
                }
            }
        }

        int const r = snprintf(
            message
        ,   cch_message
        ,   fmt
        ,   width_haystack
        ,   haystack
        ,   width_e_haystack
        ,   ellipsis
        ,   width_needle
        ,   needle
        ,   width_e_needle
        ,   ellipsis
        );

        ((void)&r);

        BDUT_report_assertion_failure_and_abort_(
            file
        ,   line
        ,   function
        ,   ""
        ,   message
        );
    }
}


# if 1 && \
     !defined(__cplusplus) && \
     defined(__clang__) && \
     1

static
void
BDUT_reference_all_impl_functions_(void)
{
    ((void)&BDUT_strcontains_);
    ((void)&BDUT_report_assertion_failure_and_abort_);
    ((void)&BDUT_report_string_contains_failure_and_abort_);
}
# endif
#endif /* !BDUT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !BDUT_INCL_BDUT_H_BDUT */

/* ///////////////////////////// end of file //////////////////////////// */

