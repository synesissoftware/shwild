/* /////////////////////////////////////////////////////////////////////////////
 * File:        doc_examples_test.cpp
 *
 * Purpose:     Implementation file for the doc_examples_test project.
 *
 * Created:     14th May 2006
 * Updated:     17th February 2007
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2007, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software. 
 *
 *              This source code is provided by Synesis Software Pty Ltd "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Synesis Software Pty Ltd be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage. 
 *
 *              Neither the name of Synesis Software Pty Ltd nor the names of
 *              any subdivisions, employees or agents of Synesis Software Pty
 *              Ltd, nor the names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission. 
 *
 * ////////////////////////////////////////////////////////////////////////// */

/* shwild Header Files */
#include <shwild/shwild.hpp>
#include <shwild/implicit_link.h>

/* Standard C++ Header Files */
#include <exception>

#if !defined(__WATCOMC__) && \
    (   !defined(_MSC_VER) || \
        _MSC_VER >= 1100)

#else /* ? __WATCOMC__ */
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER && _DEBUG */

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char ** /*argv*/)
{
    /* . */
    {
  shwild_match("1?2",     "122", 0);                    // Returns 0 (matches)
  shwild_match("1[0-8]2", "122", 0);                    // Returns 0 (matches)
  shwild_match("1[0-8]2", "192", 0);                    // Returns 1 (does not match)
  shwild_match("1?2",     "1x1", 0);                    // Returns 1 (does not match)
  shwild_match("1[N-Z]2", "1x2", 0);                    // Returns 1 (does not match)
  shwild_match("1[N-Z]2", "1x2", SHWILD_F_IGNORE_CASE); // Returns 0 (matches)
    }

    {
  // C or C++
  shwild_handle_t hCompiledPattern;

  if(shwild_compile_pattern("sh*.[cC]??", 0, &hCompiledPattern) >= 0)
  {
    shwild_match_pattern(hCompiledPattern, "shwild.cpp"); // Returns 0 (matches)
    shwild_match_pattern(hCompiledPattern, "shwild.hpp"); // Returns 1 (does not match)

    shwild_destroy_pattern(hCompiledPattern);
  }
    }

    {
  // C++
  shwild::Pattern   pattern("sh*.[cC]??", 0);

  pattern.match("shwild.cpp"); // Returns true (matches)
  pattern.match("shwild.hpp"); // Returns false (does not match)
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int             iRet;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    try
    {

        iRet = main_(argc, argv);
    }
    catch(std::exception &x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        iRet = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        iRet = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return iRet;
}

/* ////////////////////////////////////////////////////////////////////////// */
