/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.pattern_1.cpp
 *
 * Purpose: Scratch-test for shwild C++-API functions
 *
 * Created: 6th January 2008
 * Updated: 3rd May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* shwild Header Files */
#include <shwild/shwild.hpp>

#ifndef SHWILD_NO_STLSOFT
 /* STLSoft Header Files */
# include <stlsoft/stlsoft.h>
# include <platformstl/platformstl.hpp>
#endif /* !SHWILD_NO_STLSOFT */

/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char* /*argv*/[])
{
#if 0
    shwild::match("*", "");
    shwild::match("*", "a");
    shwild::match("?", "a");
    shwild::match("a", "a");
    shwild::match("a", "b");
#endif /* 0 */

    shwild::match("[0-9]", "0");
    shwild::match("[0-9]", "a");

    char const* pattern =   "[0-9][0-9][.][0-9][0-9][.][0-9][0-9][.][0-9][0-9][0-9][0-9][0-9][0-9] [ACDEINW][ABLMNOR][FGIORT][CGNRTO0-3] Task-*";
    char const* string  =   "12.15.34.952000 WARN|main(): creating 10";

    pattern = "[0-9][0-9].[0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9][0-9][0-9] [ACDEINW][ABLMNOR][FGIORT][CGNRTO0-3] Task-[0-9]*";

    shwild::match(pattern, string);

//  test.scratch.pattern_1

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
        res = main_(argc, argv);
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch (...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* ///////////////////////////// end of file //////////////////////////// */

