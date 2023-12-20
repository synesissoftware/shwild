/* /////////////////////////////////////////////////////////////////////////
 * File:        src/shwild.stlsoft.h
 *
 * Purpose:     Includes the STLSoft library header(s), and verifies
 *              required version.
 *
 * Created:     11th February 2009
 * Updated:     24th November 2023
 *
 * Author:      Matthew Wilson
 *
 * Home:        http://www.shwild.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson
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
 * - Neither the names of Matthew Wilson and Synesis Information Systems nor
 *   the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
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

