/* /////////////////////////////////////////////////////////////////////////
 * File:    src/shwild.vector.hpp
 *
 * Purpose: vector class for shwild implementation
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


#ifndef SHWILD_INCL_HPP_SHWILD_VECTORVECTOR
#define SHWILD_INCL_HPP_SHWILD_VECTORVECTOR

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <shwild/shwild.h>
#include "shwild.stlsoft.h"

#if defined(STLSOFT_COMPILER_IS_WATCOM)

# include <wcvector.h>

#else /* ? compiler */

# include <vector>

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
namespace shwild
{
namespace impl
{
#endif /* !SHWILD_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** \brief Generator class for selecting a vector implementation; INTERNAL CLASS.
 *
 * This class abstracts away the choice between std::vector and other classes
 * that may also be used for shwild for translators that do not support the
 * standard library.
 */
template <class T>
struct vector_maker
{
#if defined(STLSOFT_COMPILER_IS_WATCOM)
    class type
        : public WCValVector<T>
    {
        typedef WCValVector<T>  parent_class_type;
    public:
        type()
        {}
        type(size_t length)
            : parent_class_type(length)
        {}

    public:
        void push_back(T const &t)
        {
            static_cast<parent_class_type*>(this)->operator [](size()) = t;
        }

    public:
        size_t size() const
        {
            return parent_class_type::length();
        }
    };
#else /* ? compiler */
    typedef std::vector<T>  type;
#endif /* compiler */
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(SHWILD_NO_NAMESPACE)
} // namespace impl

} // namespace shwild

#endif /* !SHWILD_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SHWILD_INCL_HPP_SHWILD_VECTORVECTOR */

/* ///////////////////////////// end of file //////////////////////////// */

