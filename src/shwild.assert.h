/* /////////////////////////////////////////////////////////////////////////
 * File:    src/shwild.assert.h
 *
 * Purpose: Contract Programming enforcement definitions
 *
 * Created: 8th February 2008
 * Updated: 21st December 2023
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in shwild.h (included in this distribution, or
 * available from https://github.com/synesissoftware/shwild)
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SHWILD_INCL_H_SHWILD_ASSERT
#define SHWILD_INCL_H_SHWILD_ASSERT

/** \file shwild.assert.h \brief [INTERNAL] Assertions
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <shwild/shwild.h>
#ifdef SHWILD_NO_STLSOFT
# include <assert.h> /* for assert */
#else /* ? SHWILD_NO_STLSOFT */
# include "shwild.stlsoft.h"
#endif /* SHWILD_NO_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def SHWILD_ASSERT(expr)
 *
 * Simple assertion construct.
 */

/** \def SHWILD_MESSAGE_ASSERT(expr, msg)
 *
 * Simple assertion construct with qualifying message.
 */

#ifdef SHWILD_NO_STLSOFT

# define SHWILD_ASSERT(expr)                                assert(expr)

# define SHWILD_MESSAGE_ASSERT(expr, msg)                   assert(expr)
#else /* ? SHWILD_NO_STLSOFT */

# define SHWILD_ASSERT(expr)                                STLSOFT_ASSERT(expr)

# define SHWILD_MESSAGE_ASSERT(expr, msg)                   STLSOFT_MESSAGE_ASSERT(msg, expr)
#endif /* SHWILD_NO_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* SHWILD_INCL_H_SHWILD_ASSERT */

/* ///////////////////////////// end of file //////////////////////////// */

