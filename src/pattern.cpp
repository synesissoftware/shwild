/* /////////////////////////////////////////////////////////////////////////
 * File:    src/pattern.cpp
 *
 * Purpose: C string object for shwild implementation
 *
 * Created: 17th June 2005
 * Updated: 15th May 2025
 *
 * Copyright (c) 2005-2025, Matthew Wilson and Sean Kelly
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in shwild.h (included in this distribution, or
 * available from https://github.com/synesissoftware/shwild)
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file pattern.cpp \brief [INTERNAL] Patterns-related internal API
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <shwild/shwild.h>

#include "shwild.safestr.h"
#include "shwild.stlsoft.h"
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    defined(SHWILD_USING_SAFE_STR_FUNCTIONS)
# pragma warning(disable : 4996)
#endif /* SHWILD_USING_SAFE_STR_FUNCTIONS && compiler */

#include "pattern.hpp"
#include "shwild.assert.h"
#include "shwild.cover.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifdef _MSC_VER
# include <crtdbg.h>
#endif /* _MSC_VER */

/* /////////////////////////////////////////////////////////////////////////
 * compiler features
 */

/* /////////////////////////////////////////////////////////////////////////
 * checks
 */

#if CHAR_MAX >= INT_MAX || \
    CHAR_MIN <= INT_MIN
# error char must be smaller than int
#endif

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

namespace
{
    char const* strnchr(char const* s, size_t len, char ch)
    {
        SHWILD_COVER_MARK_LINE();

        for (; 0 != len; ++s, --len)
        {
            SHWILD_COVER_MARK_LINE();

            if (ch == 0[s])
            {
                SHWILD_COVER_MARK_LINE();

                return s;
            }
        }

        return NULL;
    }

    // This function serves solely to provide an abstraction over the
    // `stlsoft::auto_buffer<>::resize()` / `std::vector<>::resize()`
    bool resize_buffer(node_buffer_t& buffer, size_t size)
    {
#ifndef SHWILD_NO_STLSOFT
        return buffer.resize(size);
#else /* ? SHWILD_NO_STLSOFT */
        buffer.resize(size);

        return true;
#endif /* !SHWILD_NO_STLSOFT */
    }

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

static int get_token(char const* buf, size_t* len, unsigned flags)
{
    int tok;

    SHWILD_ASSERT(NULL != len && NULL != buf);

    SHWILD_COVER_MARK_LINE();

    *len = 1;
    if ((tok = *buf) != TOK_END)
    {
        SHWILD_COVER_MARK_LINE();

        switch (tok)
        {
            case '\\':
                SHWILD_COVER_MARK_LINE();

                if (0 != (flags & SHWILD_F_SUPPRESS_BACKSLASH_ESCAPE))
                {
                    return tok;
                }

                ++buf;
                ++*len;
                tok = *buf;

                switch (tok)
                {
                case '\\':
                case '?':
                case '*':
                case '[':
                case ']':
                case '^':
                    return tok;
                default:
                    return TOK_INVALID;
                }
            case '?':
                SHWILD_COVER_MARK_LINE();

                return TOK_WILD_1;
            case '*':
                SHWILD_COVER_MARK_LINE();

                return TOK_WILD_N;
            case '[':
                SHWILD_COVER_MARK_LINE();

                if (0 != (flags & SHWILD_F_SUPPRESS_RANGE_SUPPORT))
                {
                    SHWILD_COVER_MARK_LINE();

                    return tok;
                }

                return TOK_RANGE_BEG;
            case ']':
                SHWILD_COVER_MARK_LINE();

                if (0 != (flags & SHWILD_F_SUPPRESS_RANGE_SUPPORT))
                {
                    SHWILD_COVER_MARK_LINE();

                    return tok;
                }

                return TOK_RANGE_END;
            default:
                SHWILD_COVER_MARK_LINE();

                return tok;
        }
    }

    SHWILD_COVER_MARK_LINE();

    return TOK_END;
}

static int get_literal(shwild_slice_t& content, node_buffer_t& scratch, char const* buf, size_t* len, unsigned flags, int bInRange)
{
    SHWILD_ASSERT( NULL != buf && 0 != len );

    SHWILD_COVER_MARK_LINE();

    char const* pos = buf;
    int         tok;
    size_t      tok_len;

    if (!resize_buffer(scratch, 1)) // This trims without discarding any hard-won heap mem.
    {
        SHWILD_COVER_MARK_LINE();

        return TOK_ENOMEM;
    }

    /*
     * NOTE: I'm cheating here a bit and checking the token by range rather than
     *       against specific token values.
     */
    for (;;)
    {
        SHWILD_COVER_MARK_LINE();

        tok = get_token( pos, &tok_len, flags );

        if (bInRange &&
            0 == (SHWILD_F_SUPPRESS_RANGE_LITERAL_WILDCARD_SUPPORT & flags))
        {
            SHWILD_COVER_MARK_LINE();

            if (tok == TOK_WILD_1)
            {
                SHWILD_COVER_MARK_LINE();

                tok = '?';
            }

            if (tok == TOK_WILD_N)
            {
                SHWILD_COVER_MARK_LINE();

                tok = '*';
            }
        }

        if (tok != TOK_END &&
            tok >= CHAR_MIN &&
            tok <= CHAR_MAX )
        {
            SHWILD_COVER_MARK_LINE();

            const size_t sz = scratch.size();

            if (!resize_buffer(scratch, 1 + sz))
            {
                SHWILD_COVER_MARK_LINE();

                return TOK_ENOMEM;
            }

            scratch[sz] = static_cast<char>(tok);

            pos += tok_len;
        }
        else
        {
            SHWILD_COVER_MARK_LINE();

            break;
        }
    }

    SHWILD_COVER_MARK_LINE();

    SHWILD_ASSERT(scratch.size() >= 1);

    content.len =   scratch.size() - 1;
    content.ptr =   &scratch[0] + 1;

    *len = static_cast<size_t>(pos - buf);

    return tok;
}

int get_node(node_t* node, node_buffer_t& scratch, char const* buf, size_t* len, unsigned flags)
{
    SHWILD_ASSERT( node && buf && len );

    SHWILD_COVER_MARK_LINE();

    int     tok;
    size_t  tok_len;

    *len = 0;

    /* memset( node, 0, sizeof( node_t ) ); */
    switch (tok = get_token(buf, &tok_len, flags))
    {
    case TOK_INVALID:
        SHWILD_COVER_MARK_LINE();
    case TOK_RANGE_END:
        SHWILD_COVER_MARK_LINE();

        return SHWILD_RC_PARSE_ERROR;
    case TOK_END:
        SHWILD_COVER_MARK_LINE();

        node->type      =   NODE_END;
        node->data.len  =   0;

        break;
    case TOK_WILD_1:
        SHWILD_COVER_MARK_LINE();

        node->type      =   NODE_WILD_1;
        node->data.len  =   0;

        break;
    case TOK_WILD_N:
        SHWILD_COVER_MARK_LINE();

        node->type      =   NODE_WILD_N;
        node->data.len  =   0;

        break;
    case TOK_RANGE_BEG:
        SHWILD_COVER_MARK_LINE();

        node->type      =   NODE_RANGE;
        node->data.len  =   0;
        *len += tok_len;
        tok = get_literal( node->data, scratch, buf + tok_len, &tok_len, flags, 1 );

        if (TOK_ENOMEM == tok)
        {
            SHWILD_COVER_MARK_LINE();

            return SHWILD_RC_ALLOC_ERROR;
        }
        else if (tok != TOK_RANGE_END)
        {
            SHWILD_COVER_MARK_LINE();

            *len = 0;

            return SHWILD_RC_PARSE_ERROR;
        }

        SHWILD_COVER_MARK_LINE();

        *len += tok_len;
        tok = get_token( buf + *len, &tok_len, flags );

        STLSOFT_SUPPRESS_UNUSED(tok);
        SHWILD_ASSERT(tok == TOK_RANGE_END);

        /* Account for !range */
        if (0 == (flags & SHWILD_F_SUPPRESS_RANGE_NOT_SUPPORT) &&
            node->data.len > 0 &&
            '^' == node->data.ptr[0] &&
            '\\' != buf[tok_len])
        {
            SHWILD_COVER_MARK_LINE();

            node->type = NODE_NOT_RANGE;
            ++node->data.ptr;
            --node->data.len;
        }

        /* Now must post-process if got any embedded '-'. */
        if (0 == (flags & SHWILD_F_SUPPRESS_RANGE_CONTINUUM_SUPPORT) &&
            node->data.len > 0)
        {
            SHWILD_COVER_MARK_LINE();

            /* Search for the first '-', ignoring the first ... */
            char const*         first   =   node->data.ptr;
            char const*         minus   =   strnchr(first + 1, node->data.len - 1, '-');
            char const* const   last    =   node->data.ptr + (node->data.len - 1);

            if (SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT == (flags & SHWILD_F_SUPPRESS_RANGE_LEADTRAIL_LITERAL_HYPHEN_SUPPORT))
            {
                SHWILD_COVER_MARK_LINE();

                if ('-' == *first ||
                    '-' == *last)
                {
                    SHWILD_COVER_MARK_LINE();

                    return SHWILD_RC_PARSE_ERROR;
                }
            }

            SHWILD_COVER_MARK_LINE();

            /* ... and the last, since they're treated as literals. */
            if (NULL != minus &&
                minus != last)
            {
                SHWILD_COVER_MARK_LINE();

                node_buffer_t   xstr(1);

                char const*         begin  =   node->data.ptr;
                char const* const   end    =   begin + node->data.len;

                for (; NULL != minus && last != minus; )
                {
                    SHWILD_COVER_MARK_LINE();

                    char    prev    =   minus[-1];
                    char    post    =   minus[+1];

                    if (!isalnum(prev) ||
                        !isalnum(post) ||
                        isdigit(prev) != isdigit(post))
                    {
                        SHWILD_COVER_MARK_LINE();

                        return SHWILD_RC_PARSE_ERROR;   /* "[%-&]", "[a-9]" not valid */
                    }

                    SHWILD_COVER_MARK_LINE();

                    const size_t sz = xstr.size();

                    if (!resize_buffer(xstr, sz + (static_cast<size_t>(minus - begin) - 1)))
                    {
                        SHWILD_COVER_MARK_LINE();

                        return SHWILD_RC_ALLOC_ERROR;
                    }
                    else
                    {
                        SHWILD_COVER_MARK_LINE();

                        std::copy(begin, minus - 1, xstr.begin() + sz);
                    }

                    if (isupper(prev) == isupper(post))
                    {
                        SHWILD_COVER_MARK_LINE();

                        if (post < prev)
                        {
                            SHWILD_COVER_MARK_LINE();

                            if (0 != (flags & SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT))
                            {
                                SHWILD_COVER_MARK_LINE();

                                return SHWILD_RC_PARSE_ERROR;
                            }
                            else
                            {
                                SHWILD_COVER_MARK_LINE();

                                prev = minus[+1];
                                post = minus[-1];
                            }
                        }

                        SHWILD_COVER_MARK_LINE();

                        { for (char ch = prev; ch <= post; ++ch)
                        {
                            SHWILD_COVER_MARK_LINE();

                            const size_t sz2 = xstr.size();

                            if (!resize_buffer(xstr, 1 + sz2))
                            {
                                SHWILD_COVER_MARK_LINE();

                                return SHWILD_RC_ALLOC_ERROR;
                            }
                            else
                            {
                                SHWILD_COVER_MARK_LINE();

                                xstr[sz2] = ch;
                            }
                        }}
                    }
                    else
                    {
                        SHWILD_COVER_MARK_LINE();

                        if (0 != (flags & SHWILD_F_SUPPRESS_RANGE_CONTINUUM_CROSSCASE_SUPPORT))
                        {
                            SHWILD_COVER_MARK_LINE();

                            return SHWILD_RC_PARSE_ERROR;
                        }
                        else
                        {
                            SHWILD_COVER_MARK_LINE();

                            char    prevLower   =   static_cast<char>(tolower(prev));
                            char    postLower   =   static_cast<char>(tolower(post));
                            char    prevUpper   =   static_cast<char>(toupper(prev));
                            char    postUpper   =   static_cast<char>(toupper(post));

                            SHWILD_ASSERT((postLower < prevLower) == (postUpper < prevUpper));

                            if (postLower < prevLower)
                            {
                                SHWILD_COVER_MARK_LINE();

                                if (0 != (flags & SHWILD_F_SUPPRESS_RANGE_CONTINUUM_HIGHLOW_SUPPORT))
                                {
                                    SHWILD_COVER_MARK_LINE();

                                    return SHWILD_RC_PARSE_ERROR;
                                }
                                else
                                {
                                    SHWILD_COVER_MARK_LINE();
// TODO: Use std::swap()
                                    char    ch;

                                    ch          =   prevLower;
                                    prevLower   =   postLower;
                                    postLower   =   ch;

                                    ch          =   prevUpper;
                                    prevUpper   =   postUpper;
                                    postUpper   =   ch;
                                }
                            }

                            SHWILD_COVER_MARK_LINE();

                            { for (char ch = prevLower; ch <= postLower; ++ch)
                            {
                                SHWILD_COVER_MARK_LINE();

                                size_t const sz3 = xstr.size();

                                if (!resize_buffer(xstr, 1 + sz3))
                                {
                                    SHWILD_COVER_MARK_LINE();

                                    return SHWILD_RC_ALLOC_ERROR;
                                }
                                else
                                {
                                    SHWILD_COVER_MARK_LINE();

                                    xstr[sz3] = ch;
                                }
                            }}

                            SHWILD_COVER_MARK_LINE();

                            { for (char ch = prevUpper; ch <= postUpper; ++ch)
                            {
                                SHWILD_COVER_MARK_LINE();

                                size_t const sz4 = xstr.size();

                                if (!resize_buffer(xstr, 1 + sz4))
                                {
                                    SHWILD_COVER_MARK_LINE();

                                    return SHWILD_RC_ALLOC_ERROR;
                                }
                                else
                                {
                                    SHWILD_COVER_MARK_LINE();

                                    xstr[sz4] = ch;
                                }
                            }}

                            SHWILD_COVER_MARK_LINE();
                        }
                    }

                    begin = minus + 2;
                    if (end == begin)
                    {
                        SHWILD_COVER_MARK_LINE();

                        break;
                    }
                    else
                    {
                        SHWILD_COVER_MARK_LINE();

                        if ('-' == *begin)
                        {
                            SHWILD_COVER_MARK_LINE();

                            return SHWILD_RC_PARSE_ERROR;   /* "[0-1-234]" not valid */
                        }

                        minus = strnchr(begin, static_cast<size_t>(end - begin), '-');
                    }
                }

                const size_t sz = xstr.size();

                if (!resize_buffer(xstr, sz + static_cast<size_t>(end - begin)))
                {
                    SHWILD_COVER_MARK_LINE();

                    return SHWILD_RC_ALLOC_ERROR;
                }
                else
                {
                    SHWILD_COVER_MARK_LINE();

                    std::copy(begin, end, xstr.begin() + sz);
                }

                SHWILD_COVER_MARK_LINE();

                scratch.swap(xstr);

                SHWILD_ASSERT(scratch.size() >= 1);

                node->data.len   =   scratch.size() - 1;
                node->data.ptr   =   &scratch[0] + 1;
            }
        }
        break;
    default:
        SHWILD_COVER_MARK_LINE();

        node->type      =   NODE_LITERAL;
        node->data.len  =   0;
        tok = get_literal( node->data, scratch, buf, &tok_len, flags, 0 );

        if (TOK_ENOMEM == tok)
        {
            SHWILD_COVER_MARK_LINE();

            return SHWILD_RC_ALLOC_ERROR;
        }
    }

    SHWILD_COVER_MARK_LINE();

    *len += tok_len;
    return 0;
}

void node_init(node_t* node)
{
    SHWILD_COVER_MARK_LINE();

    node->type      =   NODE_NOTHING;
    node->data.len  =   0;
}

void node_reset(node_t* node)
{
    SHWILD_COVER_MARK_LINE();

    node->type      =   NODE_NOTHING;
    node->data.len  =   0;
}

/* ///////////////////////////// end of file //////////////////////////// */

