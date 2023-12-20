/* /////////////////////////////////////////////////////////////////////////
 * File:    src/shwild.safestr.h
 *
 * Purpose: Handles detection of "safe string" library
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


#ifndef SHWILD_INCL_H_SHWILD_SAFESTR
#define SHWILD_INCL_H_SHWILD_SAFESTR

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <shwild/shwild.h>

#include "shwild.stlsoft.h"

#ifdef SHWILD_SAFE_STR_USE_crtdefs_h_
# undef SHWILD_SAFE_STR_USE_crtdefs_h_
#endif /* SHWILD_SAFE_STR_USE_crtdefs_h_ */

#if 0
#elif defined(__BORLANDC__)
#elif defined(__DMC__)
#elif defined(__GNUC__)
#elif defined(__INTEL_COMPILER)

# if defined(_MSC_VER) && \
     _MSC_VER >= 1400

#  define SHWILD_SAFE_STR_USE_crtdefs_h_
# endif /* _MSC_VER >= 1400 */
#elif defined(__MWERKS__)
#elif defined(__WATCOMC__)
#elif defined(_MSC_VER)

# if _MSC_VER >= 1400

#  define SHWILD_SAFE_STR_USE_crtdefs_h_
# endif /* _MSC_VER >= 1400 */
#elif defined(__COMO__)
#else
#endif /* compiler */

#ifdef SHWILD_SAFE_STR_USE_crtdefs_h_

# include <crtdefs.h>
#else /* ? SHWILD_SAFE_STR_USE_crtdefs_h_ */

# include <string.h>
#endif /* SHWILD_SAFE_STR_USE_crtdefs_h_ */

/* /////////////////////////////////////////////////////////////////////////
 * feature detection
 */

#ifdef __STDC_SECURE_LIB__

# if defined(__STDC_WANT_SECURE_LIB__) && \
     __STDC_WANT_SECURE_LIB__ == 1

#  define SHWILD_USING_SAFE_STR_FUNCTIONS
# endif /* __STDC_WANT_SECURE_LIB__ */
#endif /* __STDC_SECURE_LIB__ */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* SHWILD_INCL_H_SHWILD_SAFESTR */

/* ///////////////////////////// end of file //////////////////////////// */

