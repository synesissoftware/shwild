/* /////////////////////////////////////////////////////////////////////////
 * File:    src/shwild.string.hpp
 *
 * Purpose: String class for shwild implementation
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


#ifndef SHWILD_INCL_HPP_SHWILD_STRING
#define SHWILD_INCL_HPP_SHWILD_STRING

/** \file shwild.string.hpp \brief [INTERNAL] string generator
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <shwild/shwild.h>

#include "shwild.stlsoft.h"

#if defined(SHWILD_NO_STLSOFT) || \
    defined(STLSOFT_CF_std_NAMESPACE) || \
    defined(STLSOFT_CF_std_NAMESPACE)

# if !defined(SHWILD_CUSTOM_STRING_CLASS)
#  include <string>
# else /* ? SHWILD_CUSTOM_STRING_CLASS */
#  include SHWILD_CUSTOM_STRING_CLASS_INCLUDE
# endif /* SHWILD_CUSTOM_STRING_CLASS */

#else /* ? STLSOFT_CF_std_NAMESPACE */

# if defined(STLSOFT_COMPILER_IS_WATCOM)
#  include <string.hpp>
#  define   SHWILD_CUSTOM_STRING_CLASS                      WatcomString
# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */

#endif /* STLSOFT_CF_std_NAMESPACE */

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
 * typedefs
 */

#ifndef STLSOFT_CF_std_NAMESPACE
# if defined(STLSOFT_COMPILER_IS_WATCOM)
class WatcomString
    : public String
{
public:
    WatcomString(char const* s)
        : String(s)
    {}
    WatcomString(char const* s, size_t len)
        : String(s, len)
    {}
public:
    char const* data() const
    {
        return *this;
    }
};
# endif /* ? compiler */
#endif /* !STLSOFT_CF_std_NAMESPACE */

/// Internal string type
#if !defined(SHWILD_CUSTOM_STRING_CLASS)
typedef std::string                 shwild_string_t;
#else /* ? SHWILD_CUSTOM_STRING_CLASS */
typedef SHWILD_CUSTOM_STRING_CLASS  shwild_string_t;
#endif /* SHWILD_CUSTOM_STRING_CLASS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
} // namespace impl

} // namespace shwild
#endif /* !SHWILD_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SHWILD_INCL_HPP_SHWILD_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

