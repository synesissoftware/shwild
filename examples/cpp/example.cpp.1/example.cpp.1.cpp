/// \file example.cpp.1.cpp
//
// Created: 29th April 2006
// Updated: 24th November 2023

#include <shwild/shwild.hpp>

#include <platformstl/platformstl.hpp>
#include <platformstl/filesystem/readdir_sequence.hpp>

#include <iostream>
#include <string>
#include <vector>

/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#if 0
#elif defined(__BORLANDC__)
#elif defined(__COMO__)
#elif defined(__DMC__)
#elif defined(__INTEL_COMPILER)
# pragma warning(disable : 383)     /* Suppresses: "value copied to temporary, reference to temporary used" */
#elif defined(_MSC_VER)
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////// */

typedef std::string             string_t;
typedef std::vector<string_t>   strings_t;

using platformstl::readdir_sequence;


int main(int argc, char* argv[])
{
    strings_t patterns;

    if (1 == argc)
    {
        patterns.push_back("*");
    }
    else
    {
        { for (int i = 1; i < argc; ++i)
        {
            char const* arg = argv[i];

            if ('-' == arg[0])
            {
                ;
            }
            else
            {
                patterns.push_back(arg);
            }
        }}
    }

    readdir_sequence const files(".", readdir_sequence::files);

    { for (readdir_sequence::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        { for (strings_t::const_iterator b1 = patterns.begin(); b1 != patterns.end(); ++b1)
        {
            if (0 == shwild::match((*b1).c_str(), *b, 0))
            {
                std::cout << *b << std::endl;

                break;
            }
        }}
    }}

    return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */

