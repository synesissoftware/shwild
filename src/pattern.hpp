/* /////////////////////////////////////////////////////////////////////////
 * File:    src/pattern.hpp
 *
 * Purpose: C string object for shwild implementation
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


#ifndef SHWILD_INCL_HPP_PATTERN
#define SHWILD_INCL_HPP_PATTERN

/** \file pattern.hpp \brief [INTERNAL] Patterns-related internal API
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* shwild Header Files */
#include <shwild/shwild.h>

/* STLSoft Header Files */
#include "shwild.stlsoft.h"

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
/* For some weird reason, when used with VC++ 8, pattern.cpp ends up with a
 * definition of std::allocator<>::allocate() and
 * std::allocator<>::deallocate(), which breaks the linker with LNK2005
 * (multiple definitions).
 *
 * So we disable the use of std::allocator, and tell it to use
 * stlsoft::malloc_allocator instead.
 */
# define STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR
# define STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STD_ALLOCATOR
#endif /* compiler */

#ifndef SHWILD_NO_STLSOFT
# include <stlsoft/memory/auto_buffer.hpp>
#else /* ? SHWILD_NO_STLSOFT */
# include <vector>
#endif /* !SHWILD_NO_STLSOFT */

/* Standard C Header Files */
#include <limits.h>

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** \brief Types of pattern tokens */
enum token_type
{
        TOK_INVALID     =   CHAR_MIN - 1
    ,   TOK_END         =   0
    ,   TOK_WILD_1      =   CHAR_MAX + 1
    ,   TOK_WILD_N      =   CHAR_MAX + 2
    ,   TOK_RANGE_BEG   =   CHAR_MAX + 3
    ,   TOK_RANGE_END   =   CHAR_MAX + 4
    ,   TOK_ENOMEM      =   CHAR_MAX + 5
};

/** \brief Types of pattern nodes */
enum node_type
{
        NODE_NOTHING
    ,   NODE_WILD_1
    ,   NODE_WILD_N
    ,   NODE_RANGE
    ,   NODE_NOT_RANGE
    ,   NODE_LITERAL
    ,   NODE_END
};

/** \brief Node; INTERNAL CLASS. */
struct node_t
{
    node_type       type;   /*!< The type of the node */
    shwild_slice_t  data;   /*!< Indicates the contents */
};

/** \brief Buffer used when necessary. */
#ifndef SHWILD_NO_STLSOFT
typedef stlsoft::auto_buffer<
    char
,   1024
>   node_buffer_t;
#else /* ? SHWILD_NO_STLSOFT */
typedef std::vector<
    char
>   node_buffer_t;
#endif /* !SHWILD_NO_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

/** \brief Initialises a node. */
void node_init(node_t* node);

/** \brief Uninitialises a node, releasing any associated resources. */
void node_reset(node_t* node);

/** \brief Parses the next node */
int get_node(node_t* node, node_buffer_t& buffer, char const* buf, size_t* len, unsigned flags);

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SHWILD_INCL_HPP_PATTERN */

/* ///////////////////////////// end of file //////////////////////////// */

