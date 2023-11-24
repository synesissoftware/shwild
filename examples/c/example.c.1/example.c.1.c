/** \file example.c.1.c
 *
 * Created: 24th November 2023
 * Updated: 24th November 2023
 */

#include <shwild/shwild.h>

#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int list_for_pattern(
        char const* directory
    ,   char const* pattern
)
{
    DIR* d = opendir(directory);

    if (NULL == d)
    {
        fprintf(stderr, "failed to search in directory '%s'", directory);

        return EXIT_FAILURE;
    }
    else
    {
        struct dirent *de;

        while (NULL != (de = readdir(d)))
        {
            int r = shwild_match(pattern, de->d_name, 0);

            if (r < 0)
            {
                fprintf(stderr, "match operation for directory '%s' failed: %s", directory, strerror(r));

                return EXIT_FAILURE;
            }
            else
            {
                if (0 == r)
                {
                    printf("%s\n", de->d_name);
                }
            }
        }

        closedir(d);

        return EXIT_SUCCESS;
    }
}


int main(int argc, char* argv[])
{
    int r = shwild_init();

    if (r < 0)
    {
        fprintf(stderr, "failed to initialise shwild library: %s", strerror(r));

        return EXIT_FAILURE;
    }
    else
    {
        if (1 == argc)
        {
            return list_for_pattern(".", "*");
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
                    int r2 = list_for_pattern(".", arg);

                    if (EXIT_SUCCESS != r2)
                    {
                        return r2;
                    }
                }
            }}
        }

        shwild_uninit();

        return EXIT_SUCCESS;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

