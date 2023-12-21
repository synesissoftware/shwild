/* /////////////////////////////////////////////////////////////////////////
 * File:    src/shwild.stlsoft.h
 *
 * Purpose: Includes STLSoft library header(s), and verifies required
 *          version
 *
 * Created: 11th February 2009
 * Updated: 21st December 2023
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in shwild.h (included in this distribution, or
 * available from https://github.com/synesissoftware/shwild)
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SHWILD_INCL_H_SHWILD_STLSOFT
#define SHWILD_INCL_H_SHWILD_STLSOFT

/** \file shwild.stlsoft.h \brief [INTERNAL] Manages inclusion of STLSoft
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef SHWILD_NO_STLSOFT
# include <stlsoft/stlsoft.h> /* If the compiler cannot find this, you are not using STLSoft 1.9 or later, as required. */
#endif /* !SHWILD_NO_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef SHWILD_NO_STLSOFT
# define STLSOFT_SUPPRESS_UNUSED(x)                         ((void)x)
#endif /* SHWILD_NO_STLSOFT */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef SHWILD_NO_STLSOFT
# if !defined(_STLSOFT_VER) || \
    _STLSOFT_VER < 0x010986ff
#  error Requires STLSoft 1.9.134, or later. (www.stlsoft.org/downloads.html)
# endif /* STLSoft version */
#endif /* !SHWILD_NO_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* SHWILD_INCL_H_SHWILD_STLSOFT */

/* ///////////////////////////// end of file //////////////////////////// */

