
#include <shwild/shwild.h>

#include <bdut/bdut.h>

#ifdef SHWILD_HAS_STLSoft
# include <stlsoft/stlsoft.h>
#endif

#include <iomanip>
#include <iostream>

#include <stdlib.h>


#define PROGRAM_NAME                                        "libver"

template<
    typename T_stream
,   typename T_integer
>
void
version(
    T_stream&   stm
,   char const* libname
,   T_integer   libver
)
{
    stm
        << libname
        << " v"
        << ((libver >> 24) & 0xff)
        << '.'
        << ((libver >> 16) & 0xff)
        << '.'
        << ((libver >> 8) & 0xff)
        << '.'
        << ((libver >> 0) & 0xff)
        << std::endl
        ;
}


int main(int /* argc */, char* /* argv */[])
{
    {
        auto const libver = SHWILD_VER;

        version(std::cout, "\tshwild", libver);
    }

    {
        auto const libver = BDUT_VER;

        version(std::cout, "\tBDUT", libver);
    }

#ifdef SHWILD_HAS_STLSoft

    {
        auto const libver = _STLSOFT_VER;

        version(std::cout, "\tSTLSoft", libver);
    }
#endif

    return EXIT_SUCCESS;
}

