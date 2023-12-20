/* /////////////////////////////////////////////////////////////////////////
 * File:    src/matches.hpp
 *
 * Purpose: Definition of Match interface class and concrete match classes
 *
 * Created: 17th June 2005
 * Updated: 23rd November 2023
 *
 * Home:    http://shwild.org/
 *
 * Copyright (c) 2005-2023, Matthew Wilson and Sean Kelly
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
 * - Neither the names of Matthew Wilson and Sean Kelly nor the names of
 *   any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


#ifndef SHWILD_INCL_SRC_HPP_MATCHES
#define SHWILD_INCL_SRC_HPP_MATCHES

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <shwild/shwild.h>
#include "shwild.string.hpp"    // for shwild_string_t
#include "shwild.stlsoft.h"

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

char* STLSOFT_CDECL shwild_strchr(char const*, int);
char* STLSOFT_CDECL shwild_strichr(char const*, int);
char* STLSOFT_CDECL shwild_strstr(char const*, char const*);
char* STLSOFT_CDECL shwild_stristr(char const*, char const*);
int STLSOFT_CDECL   shwild_strncmp(char const*, char const*, size_t);
int STLSOFT_CDECL   shwild_strnicmp(char const*, char const*, size_t);

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** \brief Root class of the match hierarchy; INTERNAL CLASS. */
class Match
{
/// \name Construction
/// @{
public:
    virtual ~Match() = 0;

    /// \brief Sets the next Match in the series
    virtual void setNext(Match* next) = 0;
/// @}

/// \name Operations
/// @{
public:
    /// \brief Attempt full match of the given string range
    ///
    /// The instance matches the given string range against its criteria, and
    /// the criteria of all its down-the-line peers
    virtual bool match(char const* first, char const* last) const = 0;
    /// \brief Attempt partial match of the given string range
    ///
    /// Match the given string range against the instance's criteria. If the
    /// match is successful, `*nextLen` is set to the matched length, and the
    /// return value is `first + *nextLen`
    virtual char const* nextSub(char const* first, char const* last, size_t* nextLen) const = 0;
/// @}
};

/** \brief Matches 0 or more of any characters; INTERNAL CLASS. */
class MatchWild
    : public Match
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef MatchWild   class_type;
/// @}

/// \name Construction
/// @{
public:
    explicit MatchWild(unsigned flags);
    virtual ~MatchWild();

    virtual void setNext(Match* next);
private:
    class_type& operator =(class_type const&);
/// @}

public:
    virtual bool match(char const* first, char const* last) const;
    virtual char const* nextSub(char const* first, char const* last, size_t* nextLen) const;

/// \name Fields
/// @{
private:
    Match* m_next;
/// @}
};

/** \brief Matches exactly 1 of any characters; INTERNAL CLASS. */
class MatchWild1
    : public Match
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef MatchWild1  class_type;
/// @}

/// \name Construction
/// @{
public:
    explicit MatchWild1(unsigned flags);
    virtual ~MatchWild1();

    virtual void setNext(Match* next);
private:
    class_type& operator =(class_type const&);
/// @}

public:
    virtual bool match(char const* first, char const* last) const;
    virtual char const* nextSub(char const* first, char const* last, size_t* nextLen) const;

/// \name Fields
/// @{
private:
    Match* m_next;
/// @}
};

/** \brief Matches exactly 1 character from a given range; INTERNAL CLASS. */
class MatchRange
    : public Match
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef MatchRange  class_type;
/// @}

/// \name Construction
/// @{
public:
    MatchRange(size_t len, char const* chars, unsigned flags);
    virtual ~MatchRange();

    virtual void setNext(Match* next);
private:
    class_type& operator =(class_type const&);
/// @}

public:
    virtual bool match(char const* first, char const* last) const;
    virtual char const* nextSub(char const* first, char const* last, size_t* nextLen) const;

protected:
    bool matchContents(char ch) const;

/// \name Fields
/// @{
protected:
    Match*                  m_next;
private:
    shwild_string_t const   m_chars;
    unsigned const          m_flags;
/// @}
};

/** \brief Matches exactly 1 character not from a given range; INTERNAL CLASS. */
class MatchNotRange
    : public MatchRange
{
/// \name Member Types
/// @{
public:
    /// The parent type
    typedef MatchRange      parent_class_type;
    /// This type
    typedef MatchNotRange   class_type;
/// @}

/// \name Construction
/// @{
public:
    MatchNotRange(size_t len, char const* chars, unsigned flags);
    virtual ~MatchNotRange();
private:
    class_type& operator =(class_type const&);
/// @}

public:
    virtual bool match(char const* first, char const* last) const;
};

/** \brief Matches the end of a string; INTERNAL CLASS. */
class MatchEnd
    : public Match
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef MatchEnd    class_type;
/// @}

/// \name Construction
/// @{
public:
    explicit MatchEnd(unsigned flags);
    virtual ~MatchEnd();

    virtual void setNext(Match* next);
private:
    class_type& operator =(class_type const&);
/// @}

public:
    virtual bool match(char const* first, char const* last) const;
    virtual char const* nextSub(char const* first, char const* last, size_t* nextLen) const;

/// \name Fields
/// @{
private:
    Match* m_next;
/// @}
};

/** \brief Matches a literal string; INTERNAL CLASS. */
class MatchLiteral
    : public Match
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef MatchLiteral    class_type;
/// @}

/// \name Construction
/// @{
public:
    MatchLiteral(size_t cchContents, char const* contents, unsigned flags);
    virtual ~MatchLiteral();

    virtual void setNext(Match* next);

private:
    class_type& operator =(class_type const&);
/// @}

public:
    virtual bool match(char const* first, char const* last) const;
    virtual char const* nextSub(char const* first, char const* last, size_t* nextLen) const;

/// \name Fields
/// @{
private:
    Match*                  m_next;
    shwild_string_t const   m_contents;
    unsigned const          m_flags;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
} // namespace impl

} // namespace shwild
#endif /* !SHWILD_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SHWILD_INCL_SRC_HPP_MATCHES */

/* ///////////////////////////// end of file //////////////////////////// */

