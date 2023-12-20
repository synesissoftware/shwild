/* /////////////////////////////////////////////////////////////////////////
 * File:        src/shwild.assert.h
 *
 * Purpose:     Contract Programming enforcement definitions.
 *
 * Created:     8th February 2008
 * Updated:     23rd November 2023
 *
 * Author:      Matthew Wilson
 *
 * Home:        http://www.shwild.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


#ifndef SHWILD_INCL_H_SHWILD_ASSERT
#define SHWILD_INCL_H_SHWILD_ASSERT

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

#ifdef SHWILD_NO_STLSOFT

# define SHWILD_ASSERT(expr)                                assert(expr)

# define SHWILD_MESSAGE_ASSERT(msg, expr)                   assert(expr)
#else /* ? SHWILD_NO_STLSOFT */

# define SHWILD_ASSERT(expr)                                STLSOFT_ASSERT(expr)

# define SHWILD_MESSAGE_ASSERT(msg, expr)                   STLSOFT_MESSAGE_ASSERT(msg, expr)
#endif /* SHWILD_NO_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* SHWILD_INCL_H_SHWILD_ASSERT */

/* ///////////////////////////// end of file //////////////////////////// */

