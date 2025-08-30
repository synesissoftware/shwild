/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.internal.cpp
 *
 * Purpose: Unit-tests for internal constructs
 *
 * Created: 17th June 2005
 * Updated: 30th August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* ////////////////////////////////////////////////////////////////////// */

/* shwild Header Files */
#include <shwild/shwild.hpp>

/* BDUT Header Files */
#include <bdut/bdut.h>

#include "../../../src/matches.hpp"

#ifndef SHWILD_NO_STLSOFT
# include <stlsoft/smartptr/shared_ptr.hpp>
#else /* ? SHWILD_NO_STLSOFT */
# include <memory>
#endif /* !SHWILD_NO_STLSOFT */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
# include <vector>
# include <string>

# include <string.h>
#endif /* 0 */
#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#ifdef __BORLANDC__
# pragma warn -8026 /* Suppresses "Functions with exception specifications are not expanded inline" */
# pragma warn -8004 /* Suppresses "'????' is assigned a value that is never used ..." */
#endif /* compiler */


/* ////////////////////////////////////////////////////////////////////// */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
#ifndef SHWILD_NO_STLSOFT
typedef stlsoft::shared_ptr<shwild::impl::Match>    Match_ptr;
#else /* ? SHWILD_NO_STLSOFT */
typedef std::shared_ptr<shwild::impl::Match>        Match_ptr;
#endif /* !SHWILD_NO_STLSOFT */
typedef std::vector<Match_ptr>                      Matches;
#endif /* 0 */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
static void shwild_tieMatches_(Matches& matches);
static bool shwild_match_(Matches const& matches, char const* pattern, char const* string);
#endif /* 0 */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char* argv[])
{
    {
        {
            static const char   PATTERN[]   =   "abc*";

            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abcd", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
        }

        { // "*"
            static const char   PATTERN[]   =   "*";

            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "123", 0));
        }

        { // "abc*"
            static const char   PATTERN[]   =   "abc*";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "a", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abcd", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abcde", 0));
        }

        { // "*abc*12"
            static const char       PATTERN[]       =       "*abc*12";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "a", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc12", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc122", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc212", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "--------------------------abc--------------------12", 0));
        }

        { // "*abc*1?2"
            static const char       PATTERN[]       =       "*abc*1?2";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "a", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc1", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc122", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc112", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "--------------------------abc--------------------1-2", 0));
        }

        { // "*abc*1[0-9]2"
            static const char       PATTERN[]       =       "*abc*1[0-9]2";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "a", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc1", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc122", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc112", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc192", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc1x2", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "--------------------------abc--------------------1-2", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "--------------------------abc--------------------152", 0));
        }

        { // "*?"
            static const char   PATTERN[]   =   "*?";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "123", 0));
        }


        { // "*??"
            static const char   PATTERN[]   =   "*??";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "123", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "-------------------123---------------------", 0));
        }


        { // "?*?"
            static const char   PATTERN[]   =   "?*?";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "123", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "-------------------123---------------------", 0));
        }

        { // "\\?*"
            static const char   PATTERN[]   =   "\\?*";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "?", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "?1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "?12", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "1?2", 0));
        }

        { // "[coprs]*vc*.ds[pw]"
            static const char   PATTERN[]   =   "[coprs]*vc*.ds[pw]";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "vc6.dsw", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "recls.vc6.dsp", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "recls.vc6.dsw", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "pantheios.mt.vc6.dsw", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "pantheios.mt.vc6.dsP", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "arturius.mt.vc6.dsw", 0));
        }

        { // "**"
            static const char   PATTERN[]   =   "**";

            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "a", 0));
        }

        { // "*[0-9]"
            static const char   PATTERN[]   =   "*[0-9]";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "a", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc122", 0));
        }

        { // "**[0-9]"
            static const char   PATTERN[]   =   "**[0-9]";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "a", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "ab", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "abc", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc1", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc12", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc122", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc112", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc192", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "abc1x2", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "--------------------------abc--------------------1-2", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "--------------------------abc--------------------152", 0));
        }

        { // "\\[[abcdef]?**?x"
            static const char   PATTERN[]   =   "\\[[abcdef]?**?x";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
        }

#if 0
        { // "\\[[?**?]?**?x"
            static const char   PATTERN[]   =   "\\[[?**?]?**?x";

            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "", 0));
            BDUT_ASSERT_NE(0, shwild::match(PATTERN, "?", 0));
            BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "[?abx", 0));
//          BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "?1", 0));
//          BDUT_ASSERT_EQ(0, shwild::match(PATTERN, "?12", 0));
//          BDUT_ASSERT_NE(0, shwild::match(PATTERN, "1?2", 0));
        }
#endif /* 0 */
    }

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
    using shwild::impl::MatchEnd;
    using shwild::impl::MatchLiteral;
    using shwild::impl::MatchRange;
    using shwild::impl::MatchWild;
    using shwild::impl::MatchWild1;

    {
        static const char   PATTERN[]   =   "*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "1"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "123"));
    }

    {
        static const char       PATTERN[]       =       "abc*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "a"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "ab"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abcd"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abcde"));
    }

    {
        static const char       PATTERN[]       =       "*abc*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "a"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "ab"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abcd"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "dabc"));
    }

    {
        static const char       PATTERN[]       =       "*abc*12";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(2, "12", 0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "a"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "ab"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc1"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc12"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc122"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc212"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "--------------------------abc--------------------12"));
    }

    {
        static const char       PATTERN[]       =       "*abc*1?2";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(1, "1", 0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchLiteral(1, "2", 0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "a"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "ab"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc1"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc122"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc112"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "--------------------------abc--------------------1-2"));
    }


    {
        static const char       PATTERN[]       =       "*abc*1[0-9]2";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(1, "1", 0)));
        matches.push_back(Match_ptr(new MatchRange(10, "0123456789", 0)));
        matches.push_back(Match_ptr(new MatchLiteral(1, "2", 0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "a"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "ab"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc1"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc122"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc112"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "abc192"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "abc1x2"));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "--------------------------abc--------------------1-2"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "--------------------------abc--------------------152"));
    }

    {
        static const char   PATTERN[]   =   "*?";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "1"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "123"));
    }


    {
        static const char   PATTERN[]   =   "*??";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "1"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "123"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "-------------------123---------------------"));
    }


    {
        static const char   PATTERN[]   =   "?*?";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_FALSE(shwild_match_(matches, PATTERN, "1"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "123"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "-------------------123---------------------"));
    }


    {
        static const char   PATTERN[]   =   "*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, ""));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "1"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "12"));
        BDUT_ASSERT_TRUE(shwild_match_(matches, PATTERN, "123"));
    }
#endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_GCC) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
    ((void)&shwild_match_);
#else /* ? compiler */
    STLSOFT_SUPPRESS_UNUSED(&shwild_match_);
#endif /* compiler */


    return BDUT_TESTS_PASSED(argc, argv);
}

int main(int argc, char* argv[])
{
    int             r;
#if defined(STLSOFT_COMPILER_IS_MSVC)
    _CrtMemState    state;

    _CrtMemCheckpoint(&state);

    STLSOFT_SUPPRESS_UNUSED(state);
#endif /* STLSOFT_COMPILER_IS_MSVC */

//  for (;;) {}

    try
    {
        r = main_(argc, argv);
    }
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
    catch (std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        r = EXIT_FAILURE;
    }
#endif /* compiler */
    catch (...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        r = EXIT_FAILURE;
    }

#ifdef STLSOFT_COMPILER_IS_MSVC
    _CrtMemDumpAllObjectsSince(&state);
#endif /* STLSOFT_COMPILER_IS_MSVC */

    return r;
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementations
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

bool shwild_match_(Matches const& matches, char const* pattern, char const* string)
{
    STLSOFT_SUPPRESS_UNUSED(pattern);

    const size_t    len =   strlen(string);

    return matches[0]->match(&string[0], &string[0] + len);
}

void shwild_tieMatches_(Matches& matches)
{
    for (size_t i = 1; i < matches.size(); ++i)
    {
        matches[i - 1]->setNext(&*matches[i]);
    }
}
#endif /* compiler */


/* ///////////////////////////// end of file //////////////////////////// */

