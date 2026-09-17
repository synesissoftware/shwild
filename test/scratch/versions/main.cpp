
#include <shwild/shwild.h>

#include <bdut/bdut.h>

#ifdef SHWILD_HAS_STLSoft
# include <stlsoft/stlsoft.h>
#endif

#include <iomanip>
#include <iostream>

#include <stdlib.h>


#define PROGRAM_NAME                                        "versions"


template<
    typename T_stream
,   typename T_integer
>
void
version(
    T_stream&   stm
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
)
{
    stm
        << prefix
        << libname
        << ": v"
        << ((libver >> 24) & 0xff)
        << '.'
        << ((libver >> 16) & 0xff)
        << '.'
        << ((libver >> 8) & 0xff)
        << '.'
        << ((libver >> 0) & 0xff)
        << " ("
        << macroname
        << " = 0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << ")"
        << std::endl
        ;
}


int main(int /* argc */, char* /* argv */[])
{
    {
        unsigned const libver = SHWILD_VER;

        version(std::cout, "", "shwild", "SHWILD_VER", libver);
    }

    std::cout << "\n" << "efferent dependencies:" << std::endl;

    {
        unsigned const libver = BDUT_VER;

        version(std::cout, "\t", "BDUT", "BDUT_VER", libver);
    }

#ifdef SHWILD_HAS_STLSoft

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }
#endif

    return EXIT_SUCCESS;
}

