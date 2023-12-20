/* /////////////////////////////////////////////////////////////////////////
 * File:    shwild/bdt/bdt.h
 *
 * Purpose: shwild Brain-Dead Testing
 *
 * Created: 18th July 2020
 * Updated: 21st December 2023
 *
 * Copyright (c) 2020-2023, Matthew Wilson and Synesis Information Systems
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
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
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


/** \file shwild/shwild.h [C/C++] shwild Brain-Dead Testing
 */

#ifndef SHWILD_INCL_SHWILD_BDT_H_BDT
#define SHWILD_INCL_SHWILD_BDT_H_BDT

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef SHWILD_DOCUMENTATION_SKIP_SECTION
# define SHWILD_VER_SHWILD_BDT_H_BDT_MAJOR      1
# define SHWILD_VER_SHWILD_BDT_H_BDT_MINOR      0
# define SHWILD_VER_SHWILD_BDT_H_BDT_REVISION   1
# define SHWILD_VER_SHWILD_BDT_H_BDT_EDIT       1
#endif /* !SHWILD_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <assert.h> /* for assert */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define SHWILD_BDT_CHECK(expr)                              assert(expr)
#define SHWILD_BDT_CHECK_FALSE(expr)                        assert(!(expr))

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !SHWILD_INCL_SHWILD_BDT_H_BDT */

/* ///////////////////////////// end of file //////////////////////////// */

