/* /////////////////////////////////////////////////////////////////////////
 * File:    shwild/shwild.hpp
 *
 * Purpose: C++ root file for the shwild C++ API
 *
 * Created: 17th June 2005
 * Updated: 24th  November 2023
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


/** \file shwild/shwild.hpp \brief [C++] C++ root file for the **shwild C++ API**
 */

#ifndef SHWILD_INCL_SHWILD_HPP_SHWILD
#define SHWILD_INCL_SHWILD_HPP_SHWILD

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef SHWILD_DOCUMENTATION_SKIP_SECTION
# define SHWILD_VER_SHWILD_HPP_SHWILD_MAJOR     1
# define SHWILD_VER_SHWILD_HPP_SHWILD_MINOR     2
# define SHWILD_VER_SHWILD_HPP_SHWILD_REVISION  3
# define SHWILD_VER_SHWILD_HPP_SHWILD_EDIT      13
#endif /* !SHWILD_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef __cplusplus
# error This file can only be used in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef SHWILD_INCL_SHWILD_H_SHWILD
# include <shwild/shwild.h>
#endif /* !SHWILD_INCL_SHWILD_H_SHWILD */

#include <stdexcept>

/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#ifdef __BORLANDC__
# pragma warn -8026 /* Suppresses "Functions with exception specifications are not expanded inline" */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
namespace shwild
{
#endif /* !SHWILD_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// TODO: Flesh this out to be a full and complete exception class
/// Exception thrown by the Pattern constructor
///
/// \ingroup group__shwild_api__cpp_api
class PatternException
    : public std::runtime_error
{
/// \name Member Types
/// @{
public:
    /// The parent exception type
    typedef std::runtime_error  parent_class_type;
    /// This type
    typedef PatternException    class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Construct from the given message and failure code
    PatternException(char const* message, int shwildErrorCode)
        : parent_class_type(message)
        , m_shwildErrorCode(shwildErrorCode)
    {}
/// @}

/// \name Accessors
/// @{
public:
    /// Non-`null`, `nul`-terminated C-style string describing the exception
    virtual char const* what() const throw()
    {
        char const* const wh = parent_class_type::what();

        if (NULL != wh &&
            '\0' != wh[0])
        {
            return wh;
        }

        return "Pattern Exception";
    }

    /// The error code associated with the exception
    int errorCode() const throw()
    {
        return m_shwildErrorCode;
    }
/// @}

/// \name Fields
/// @{
private:
    int m_shwildErrorCode;
/// @}
};

/// Facade for the \ref group__shwild_api__c_api "shwild C API"'s
/// compiled-pattern functionality
///
/// \ingroup group__shwild_api__cpp_api
class Pattern
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef Pattern     class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Parses and precompiles the given pattern, according to the behaviour specified by the given flags
    ///
    /// \note If the parsing fails, an instance of PatternException is thrown
    explicit Pattern(char const* pattern, unsigned flags = 0);
    /// Parses and precompiles the given pattern, according to the behaviour specified by the given flags
    ///
    /// \note If the parsing fails, an instance of PatternException is thrown
    explicit Pattern(slice_t const* pattern, unsigned flags = 0);
    /// Parses and precompiles the given pattern, according to the behaviour specified by the given flags
    ///
    /// \note If the parsing fails, an instance of PatternException is thrown
    explicit Pattern(slice_t const& pattern, unsigned flags = 0);
    /// Releases any resources associated with the instance
    ~Pattern();

# if __cplusplus >= 201103L
    /// Move constructor
    Pattern(class_type&& rhs)
        : m_hCompiledPattern(rhs.m_hCompiledPattern)
        , m_numMatches(rhs.m_numMatches)
    {
        rhs.m_hCompiledPattern = nullptr;
        rhs.m_numMatches = -1;
    }
# endif /* C++-11+ */
private:
    Pattern(class_type const&);
    void operator =(class_type const&);
/// @}

/// \name Operations
/// @{
public:
    /// Match the given string against the precompiled pattern maintained as member state
    bool match(char const* string) const;
    /// Match the given string against the precompiled pattern maintained as member state
    bool match(slice_t const* string) const;
    /// Match the given string against the precompiled pattern maintained as member state
    bool match(slice_t const& string) const;
/// @}

/// \name Attributes
/// @{
public:
    /** The number of potential matches (including the end marker) in
     *    the compiled pattern.
     *
     * \note For compilation without exception support, this will be <0 if a
     *    compilation error occurred
     */
    int numMatched() const
    {
        return m_numMatches;
    }
/// @}

/// \name Implementation
/// @{
private:
    static shwild_handle_t init_(char const* pattern, unsigned flags, int& numMatches);
    static shwild_handle_t init_(slice_t const* pattern, unsigned flags, int& numMatches);
/// @}

/// \name Fields
/// @{
private:
    shwild_handle_t m_hCompiledPattern;
    int             m_numMatches;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef SHWILD_DOCUMENTATION_SKIP_SECTION

inline /* static */ shwild_handle_t Pattern::init_(char const* pattern, unsigned flags, int& numMatches)
{
    shwild_handle_t hCompiledPattern;

    numMatches = shwild_compile_pattern(pattern, flags, &hCompiledPattern);

    if (numMatches < 0)
    {
        hCompiledPattern    =   NULL;

        throw PatternException("Failed to compile pattern", numMatches);
    }

    return hCompiledPattern;
}

inline /* static */ shwild_handle_t Pattern::init_(slice_t const* pattern, unsigned flags, int& numMatches)
{
    shwild_handle_t hCompiledPattern;

    numMatches = shwild_compile_pattern_s(pattern, flags, &hCompiledPattern);

    if (numMatches < 0)
    {
        hCompiledPattern    =   NULL;

        throw PatternException("Failed to compile pattern", numMatches);
    }

    return hCompiledPattern;
}

inline Pattern::Pattern(char const* pattern, unsigned flags)
    : m_hCompiledPattern(init_(pattern, flags, m_numMatches))
{}

inline Pattern::Pattern(slice_t const* pattern, unsigned flags)
    : m_hCompiledPattern(init_(pattern, flags, m_numMatches))
{}

inline Pattern::Pattern(slice_t const& pattern, unsigned flags)
    : m_hCompiledPattern(init_(&pattern, flags, m_numMatches))
{}

inline Pattern::~Pattern()
{
    shwild_destroy_pattern(m_hCompiledPattern);
}

inline bool Pattern::match(char const* string) const
{
    int r = shwild_match_pattern(m_hCompiledPattern, string);

    if (r < 0)
    {
        throw PatternException("Match failed", r);
    }

    return 0 == r;
}

inline bool Pattern::match(slice_t const* string) const
{
    int r = shwild_match_pattern_s(m_hCompiledPattern, string);

    if (r < 0)
    {
        throw PatternException("Match failed", r);
    }

    return 0 == r;
}

inline bool Pattern::match(slice_t const& string) const
{
    int r = shwild_match_pattern_s(m_hCompiledPattern, &string);

    if (r < 0)
    {
        throw PatternException("Match failed", r);
    }

    return 0 == r;
}

#endif /* !SHWILD_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
} // namespace shwild
#endif /* !SHWILD_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !SHWILD_INCL_SHWILD_H_SHWILD */

/* ///////////////////////////// end of file //////////////////////////// */

