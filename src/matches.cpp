/* /////////////////////////////////////////////////////////////////////////
 * File:    src/matches.cpp
 *
 * Purpose: Implementation of Match interface class and concrete match
 *          classes
 *
 * Created: 17th June 2005
 * Updated: 7th September 2024
 *
 * Copyright (c) 2005-2024, Matthew Wilson and Sean Kelly
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in shwild.h (included in this distribution, or
 * available from https://github.com/synesissoftware/shwild)
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file matches.cpp \brief [INTERNAL] Match protocol class and specific implementations
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <shwild/shwild.h>
#include "shwild.stlsoft.h"

#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
# pragma warning(disable : 4530) // Suppress: "C++ exception handler used, but unwind semantics are not enabled."
#endif /* NoX && VC++ */

#include "matches.hpp"
#include "shwild.assert.h"
#include "shwild.cover.h"

#include <ctype.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#if defined(STLSOFT_COMPILER_IS_WATCOM)
# pragma warning(disable : 656)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
namespace shwild
{
namespace impl
{
#endif /* !SHWILD_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#ifndef SHWILD_DOCUMENTATION_SKIP_SECTION
char* shwild_strchr(char const*, int);
char* shwild_strichr(char const*, int);
char* shwild_strstr(char const*, char const*);
char* shwild_stristr(char const*, char const*);
int shwild_strncmp(char const*, char const*, size_t);
int shwild_strnicmp(char const*, char const*, size_t);
#endif /* !SHWILD_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* /////////////////////////////////////////////////////////////////////////
 * Match
 */

/* virtual */ Match::~Match()
{
    SHWILD_COVER_MARK_LINE();
}

/* /////////////////////////////////////////////////////////////////////////
 * MatchWild
 */

MatchWild::MatchWild(unsigned /* flags */)
    : m_next(NULL)
{
    SHWILD_COVER_MARK_LINE();
}

MatchWild::~MatchWild()
{
    SHWILD_COVER_MARK_LINE();
}

void MatchWild::setNext(Match* next)
{
    SHWILD_ASSERT(NULL == m_next);

    SHWILD_COVER_MARK_LINE();

    m_next = next;
}

bool MatchWild::match(char const* first, char const* last) const
{
    SHWILD_ASSERT(NULL != m_next);

    SHWILD_COVER_MARK_LINE();

    if (m_next->match(last, last))
    {
        SHWILD_COVER_MARK_LINE();

        return true;
    }
    else
    {
        SHWILD_COVER_MARK_LINE();

        char const* next;
        size_t      nextLen;

        for (next = first; last != (next = m_next->nextSub(next, last, &nextLen)); next += nextLen)
        {
            SHWILD_COVER_MARK_LINE();

            if (m_next->match(next, last))
            {
                SHWILD_COVER_MARK_LINE();

                return true;
            }
        }
    }

    SHWILD_COVER_MARK_LINE();

    return false;
}

char const* MatchWild::nextSub(char const* /* first */, char const* /* last */, size_t* /* nextLen */) const
{
    SHWILD_MESSAGE_ASSERT(false, "nextSub() not callable on MatchWild");

    SHWILD_COVER_MARK_LINE();

    return NULL;
}


/* /////////////////////////////////////////////////////////////////////////
 * MatchWild1
 */

MatchWild1::MatchWild1(unsigned /* flags */)
    : m_next(NULL)
{
    SHWILD_COVER_MARK_LINE();
}

MatchWild1::~MatchWild1()
{
    SHWILD_COVER_MARK_LINE();
}

void MatchWild1::setNext(Match* next)
{
    SHWILD_ASSERT(NULL == m_next);

    SHWILD_COVER_MARK_LINE();

    m_next = next;
}

bool MatchWild1::match(char const* first, char const* last) const
{
    SHWILD_ASSERT(NULL != m_next);

    SHWILD_COVER_MARK_LINE();

    if (0 == (last - first))
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
    else if (m_next->match(first + 1, last))
    {
        SHWILD_COVER_MARK_LINE();

        return true;
    }

    SHWILD_COVER_MARK_LINE();

    return false;
}

char const* MatchWild1::nextSub(char const* first, char const* /* last */, size_t* nextLen) const
{
    SHWILD_COVER_MARK_LINE();

    *nextLen = 1;   // If the contract for nextSub was that *nextLen was valid when return != last, then we'd
                    // have to set to 0 if first == last

    return first;
}


/* /////////////////////////////////////////////////////////////////////////
 * MatchRange
 */

MatchRange::MatchRange(size_t len, char const* chars, unsigned flags)
    : m_next(NULL)
    , m_chars(chars, len)
    , m_flags(flags)
{
    SHWILD_COVER_MARK_LINE();
}

MatchRange::~MatchRange()
{
    SHWILD_COVER_MARK_LINE();
}

void MatchRange::setNext(Match* next)
{
    SHWILD_ASSERT(NULL == m_next);

    SHWILD_COVER_MARK_LINE();

    m_next = next;
}

bool MatchRange::matchContents(char ch) const
{
    SHWILD_COVER_MARK_LINE();

    typedef char* (*pfn_t)(char const*, int);

    pfn_t const pfn =   (m_flags & SHWILD_F_IGNORE_CASE)
                            ? shwild_strichr
                            : shwild_strchr
                            ;

    return NULL != (*pfn)(m_chars.c_str(), ch);
}

bool MatchRange::match(char const* first, char const* last) const
{
    SHWILD_ASSERT(NULL != m_next);

    SHWILD_COVER_MARK_LINE();

    if (0 == (last - first))
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
    else if (!this->matchContents(*first))
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
    else if (m_next->match(first + 1, last))
    {
        SHWILD_COVER_MARK_LINE();

        return true;
    }

    SHWILD_COVER_MARK_LINE();

    return false;
}

char const* MatchRange::nextSub(char const* first, char const* /* last */, size_t* nextLen) const
{
    SHWILD_COVER_MARK_LINE();

    *nextLen = 1;   // If the contract for nextSub was that *nextLen was valid when return != last, then we'd
                    // have to set to 0 if first == last

    return first;
}


/* /////////////////////////////////////////////////////////////////////////
 * MatchNotRange
 */

MatchNotRange::MatchNotRange(size_t len, char const* chars, unsigned flags)
    : parent_class_type(len, chars, flags)
{
    SHWILD_COVER_MARK_LINE();
}

MatchNotRange::~MatchNotRange()
{
    SHWILD_COVER_MARK_LINE();
}

bool MatchNotRange::match(char const* first, char const* last) const
{
    SHWILD_ASSERT(NULL != m_next);

    SHWILD_COVER_MARK_LINE();

    if (0 == (last - first))
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
    else if (this->matchContents(*first))
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
    else if (m_next->match(first + 1, last))
    {
        SHWILD_COVER_MARK_LINE();

        return true;
    }

    SHWILD_COVER_MARK_LINE();

    return false;
}


/* /////////////////////////////////////////////////////////////////////////
 * MatchEnd
 */

MatchEnd::MatchEnd(unsigned /* flags */)
    : m_next(NULL)
{
    SHWILD_COVER_MARK_LINE();
}

MatchEnd::~MatchEnd()
{
    SHWILD_COVER_MARK_LINE();
}

void MatchEnd::setNext(Match* next)
{
    SHWILD_ASSERT(NULL == next);
    SHWILD_MESSAGE_ASSERT(false, "WildEnd must always be the end");

    STLSOFT_SUPPRESS_UNUSED(next);

    SHWILD_COVER_MARK_LINE();
}

bool MatchEnd::match(char const* first, char const* last) const
{
    SHWILD_COVER_MARK_LINE();

    return first == last;
}

char const* MatchEnd::nextSub(char const* /* first */, char const* last, size_t* nextLen) const
{
    SHWILD_COVER_MARK_LINE();

    *nextLen = 0;

    return last;
}


/* /////////////////////////////////////////////////////////////////////////
 * MatchLiteral
 */

MatchLiteral::MatchLiteral(size_t cchContents, char const* contents, unsigned flags)
    : m_next(NULL)
    , m_contents(contents, cchContents)
    , m_flags(flags)
{
    SHWILD_COVER_MARK_LINE();
}

MatchLiteral::~MatchLiteral()
{
    SHWILD_COVER_MARK_LINE();
}

void MatchLiteral::setNext(Match* next)
{
    SHWILD_ASSERT(NULL == m_next);

    SHWILD_COVER_MARK_LINE();

    m_next = next;
}

bool MatchLiteral::match(char const* first, char const* last) const
{
    SHWILD_ASSERT(first <= last);

    SHWILD_COVER_MARK_LINE();

    typedef int (*pfn_t)(char const*, char const*, size_t);

    size_t const    len =   m_contents.length();

    pfn_t const     pfn =   (m_flags & SHWILD_F_IGNORE_CASE)
                                ? shwild_strnicmp
                                : shwild_strncmp
                                ;

    if (static_cast<size_t>(last - first) < len)
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
    else if (0 == (*pfn)(first, m_contents.data(), len))
    {
        SHWILD_COVER_MARK_LINE();

        return m_next->match(first + len, last);
    }
    else
    {
        SHWILD_COVER_MARK_LINE();

        return false;
    }
}

char const* MatchLiteral::nextSub(char const* first, char const* last, size_t* nextLen) const
{
    SHWILD_COVER_MARK_LINE();

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    !defined(_DEBUG) && \
    _MSC_VER == 1300
//# error This assumes *last == '\0', which is NOT VALID!
#endif

    typedef char* (*pfn_t)(char const*, char const*);

    char const* next;
    pfn_t const pfn =   (m_flags & SHWILD_F_IGNORE_CASE)
                            ? shwild_stristr
                            : shwild_strstr
                            ;

    if (NULL == (next = (*pfn)(first, m_contents.c_str())))
    {
        SHWILD_COVER_MARK_LINE();

        return last;
    }
    else
    {
        SHWILD_COVER_MARK_LINE();

        *nextLen = m_contents.length();

        return next;
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * utility functions
 */

#ifndef SHWILD_DOCUMENTATION_SKIP_SECTION

char* shwild_strchr(char const* s, int ch)
{
    SHWILD_COVER_MARK_LINE();

    return ::strchr(const_cast<char*>(s), ch);
}

char* shwild_strichr(char const* s, int ch)
{
    SHWILD_COVER_MARK_LINE();

    for (; '\0' != *s; ++s)
    {
        SHWILD_COVER_MARK_LINE();

        if (toupper(*s) == toupper(ch))
        {
            SHWILD_COVER_MARK_LINE();

            return const_cast<char*>(s);
        }
    }

    return NULL;
}

char* shwild_strstr(char const* s1, char const* s2)
{
    SHWILD_COVER_MARK_LINE();

    return ::strstr(const_cast<char*>(s1), s2);
}

char* shwild_stristr(char const* s1, char const* s2)
{
    SHWILD_COVER_MARK_LINE();

    const size_t len2 = ::strlen(s2);

    for (; '\0' != *s1; ++s1)
    {
        SHWILD_COVER_MARK_LINE();

        if (0 == shwild_strnicmp(s1, s2, len2))
        {
            SHWILD_COVER_MARK_LINE();

            return const_cast<char*>(s1);
        }
    }

    return NULL;
}

int shwild_strncmp(char const* s1, char const* s2, size_t n)
{
    SHWILD_COVER_MARK_LINE();

    return ::strncmp(s1, s2, n);
}

int shwild_strnicmp(char const* s1, char const* s2, size_t n)
{
    SHWILD_COVER_MARK_LINE();

#if defined(STLSOFT_COMPILER_IS_DMC)
    return ::strnicmp(s1, s2, n);
#elif (   defined(STLSOFT_COMPILER_IS_INTEL) && \
          defined(WIN32)) || \
      defined(STLSOFT_COMPILER_IS_MSVC)
    return ::_strnicmp(s1, s2, n);
#else /* ? compiler */

    { for (size_t i = 0; i < n; ++i)
    {
        SHWILD_COVER_MARK_LINE();

        char    ch1 =   (char)tolower(*s1++);
        char    ch2 =   (char)tolower(*s2++);

        if (ch1 < ch2)
        {
            SHWILD_COVER_MARK_LINE();

            return -1;
        }
        else if (ch1 > ch2)
        {
            SHWILD_COVER_MARK_LINE();

            return +1;
        }
        else if (0 == ch1)
        {
            SHWILD_COVER_MARK_LINE();

            break;
        }
    }}

    SHWILD_COVER_MARK_LINE();

    return 0;

#endif /* compiler */
}
#endif /* !SHWILD_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
} // namespace impl

} // namespace shwild

#endif /* !SHWILD_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

