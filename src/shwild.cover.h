/* /////////////////////////////////////////////////////////////////////////
 * File:    src/shwild.cover.h
 *
 * Purpose: Code coverage enforcement definitions
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


#ifndef SHWILD_INCL_H_SHWILD_COVER
#define SHWILD_INCL_H_SHWILD_COVER

/** \file shwild.cover.h \brief [INTERNAL] Code Coverage
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

/* shwild Header Files */
#include <shwild/shwild.h>
#include "shwild.stlsoft.h"

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility - 1
 */

#ifdef SHWILD_QUALITY_USE_XCOVER

# if !defined(STLSOFT_PPF_COUNTER_SYMBOL_SUPPORT) || \
     !defined(STLSOFT_PPF_FUNCTION_SYMBOL_SUPPORT)

#  undef SHWILD_QUALITY_USE_XCOVER
# endif
#endif

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef SHWILD_QUALITY_USE_XCOVER
# include <xcover/xcover.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * compatibility - 2
 */

/** \def SHWILD_COVER_MARK_LINE()
 *
 * [UNDOCUMENTED].
 */

#ifdef SHWILD_QUALITY_USE_XCOVER

# define SHWILD_COVER_MARK_LINE()                           XCOVER_MARK_LINE()
#else

# ifdef SHWILD_NO_STLSOFT
#  define SHWILD_COVER_MARK_LINE()                          ((void)0)
# else /* ? SHWILD_NO_STLSOFT */
#  define SHWILD_COVER_MARK_LINE()                          stlsoft_static_cast(void, 0)
# endif /* SHWILD_NO_STLSOFT */
#endif

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SHWILD_INCL_H_SHWILD_COVER */

/* ///////////////////////////// end of file //////////////////////////// */

