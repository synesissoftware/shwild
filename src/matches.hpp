/* /////////////////////////////////////////////////////////////////////////
 * File:    src/matches.hpp
 *
 * Purpose: Definition of Match interface class and concrete match classes
 *
 * Created: 17th June 2005
 * Updated: 21st December 2023
 *
 * Copyright (c) 2005-2023, Matthew Wilson and Sean Kelly
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in shwild.h (included in this distribution, or
 * available from https://github.com/synesissoftware/shwild)
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SHWILD_INCL_SRC_HPP_MATCHES
#define SHWILD_INCL_SRC_HPP_MATCHES

/** \file matches.hpp \brief [INTERNAL] Match protocol class and specific implementations
 */

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
    /// Constructs instance
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
    /// Constructs instance
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
    /// Constructs instance
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
    /// [UNDOCUMENTED]
    bool matchContents(char ch) const;

/// \name Fields
/// @{
protected:
#ifndef SHWILD_DOCUMENTATION_SKIP_SECTION
    Match*                  m_next;
#endif /* !SHWILD_DOCUMENTATION_SKIP_SECTION */
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
    /// Constructs instance
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
    /// Constructs instance
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
    /// Constructs instance
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

