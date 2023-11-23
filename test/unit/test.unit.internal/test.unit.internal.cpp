/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.internal.cpp
 *
 * Purpose:     C++ test file for the shwild library
 *
 * Created:     17th June 2005
 * Updated:     18th July 2020
 *
 * Home:        http://shwild.org/
 *
 * Copyright (c) 2005-2020, Matthew Wilson and Sean Kelly
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
 * - Neither the names of Matthew Wilson and Sean Kelly nor the names of
 *   any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* shwild Header Files */
#include <shwild/shwild.hpp>
#include <shwild//bdt/bdt.h>

#include "../../../src/matches.hpp"

#include <stlsoft/smartptr/shared_ptr.hpp>

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
typedef stlsoft::shared_ptr<shwild::impl::Match>    Match_ptr;
typedef std::vector<Match_ptr>                      Matches;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
static void shwild_tieMatches_(Matches& matches);
static bool shwild_match_(Matches const& matches, char const* pattern, char const* string);
#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char* /* argv */[])
{
    {
        {
            static const char   PATTERN[]   =   "abc*";

            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abcd", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
        }

        { // "*"
            static const char   PATTERN[]   =   "*";

            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "123", 0));
        }

        { // "abc*"
            static const char   PATTERN[]   =   "abc*";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "a", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abcd", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abcde", 0));
        }

        { // "*abc*12"
            static const char       PATTERN[]       =       "*abc*12";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "a", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc12", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc122", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc212", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "--------------------------abc--------------------12", 0));
        }

        { // "*abc*1?2"
            static const char       PATTERN[]       =       "*abc*1?2";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "a", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc1", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc122", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc112", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "--------------------------abc--------------------1-2", 0));
        }

        { // "*abc*1[0-9]2"
            static const char       PATTERN[]       =       "*abc*1[0-9]2";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "a", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc1", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc122", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc112", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc192", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc1x2", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "--------------------------abc--------------------1-2", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "--------------------------abc--------------------152", 0));
        }

        { // "*?"
            static const char   PATTERN[]   =   "*?";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "123", 0));
        }


        { // "*??"
            static const char   PATTERN[]   =   "*??";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "123", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "-------------------123---------------------", 0));
        }


        { // "?*?"
            static const char   PATTERN[]   =   "?*?";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "123", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "-------------------123---------------------", 0));
        }

        { // "\\?*"
            static const char   PATTERN[]   =   "\\?*";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "?", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "?1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "?12", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "1?2", 0));
        }

        { // "[coprs]*vc*.ds[pw]"
            static const char   PATTERN[]   =   "[coprs]*vc*.ds[pw]";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "vc6.dsw", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "recls.vc6.dsp", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "recls.vc6.dsw", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "pantheios.mt.vc6.dsw", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "pantheios.mt.vc6.dsP", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "arturius.mt.vc6.dsw", 0));
        }

        { // "**"
            static const char   PATTERN[]   =   "**";

            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "a", 0));
        }

        { // "*[0-9]"
            static const char   PATTERN[]   =   "*[0-9]";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "a", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc122", 0));
        }

        { // "**[0-9]"
            static const char   PATTERN[]   =   "**[0-9]";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "a", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "ab", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "abc", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc1", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc12", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc122", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc112", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc192", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "abc1x2", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "--------------------------abc--------------------1-2", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "--------------------------abc--------------------152", 0));
        }

        { // "\\[[abcdef]?**?x"
            static const char   PATTERN[]   =   "\\[[abcdef]?**?x";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
        }

#if 0
        { // "\\[[?**?]?**?x"
            static const char   PATTERN[]   =   "\\[[?**?]?**?x";

            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "", 0));
            SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "?", 0));
            SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "[?abx", 0));
//          SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "?1", 0));
//          SHWILD_BDT_CHECK(0 == shwild::match(PATTERN, "?12", 0));
//          SHWILD_BDT_CHECK(0 != shwild::match(PATTERN, "1?2", 0));
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

        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "1"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "123"));
    }

    {
        static const char       PATTERN[]       =       "abc*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "a"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "ab"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abcd"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abcde"));
    }

    {
        static const char       PATTERN[]       =       "*abc*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchLiteral(3, "abc", 0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "a"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "ab"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abcd"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "dabc"));
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

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "a"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "ab"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc1"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc12"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc122"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc212"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "--------------------------abc--------------------12"));
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

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "a"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "ab"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc1"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc122"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc112"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "--------------------------abc--------------------1-2"));
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

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "a"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "ab"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc1"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc122"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc112"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "abc192"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "abc1x2"));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "--------------------------abc--------------------1-2"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "--------------------------abc--------------------152"));
    }

    {
        static const char   PATTERN[]   =   "*?";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "1"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "123"));
    }


    {
        static const char   PATTERN[]   =   "*??";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "1"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "123"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "-------------------123---------------------"));
    }


    {
        static const char   PATTERN[]   =   "?*?";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchWild1(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK_FALSE(shwild_match_(matches, PATTERN, "1"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "123"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "-------------------123---------------------"));
    }


    {
        static const char   PATTERN[]   =   "*";

        std::vector<Match_ptr>  matches;

        matches.push_back(Match_ptr(new MatchWild(0)));
        matches.push_back(Match_ptr(new MatchEnd(0)));

        shwild_tieMatches_(matches);

        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, ""));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "1"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "12"));
        SHWILD_BDT_CHECK(shwild_match_(matches, PATTERN, "123"));
    }
#endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_GCC) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
    ((void)&shwild_match_);
#else /* ? compiler */
    STLSOFT_SUPPRESS_UNUSED(shwild_match_);
#endif /* compiler */

    return 0;
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
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        r = EXIT_FAILURE;
    }
#endif /* compiler */
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        r = EXIT_FAILURE;
    }

#ifdef STLSOFT_COMPILER_IS_MSVC
    _CrtMemDumpAllObjectsSince(&state);
#endif /* STLSOFT_COMPILER_IS_MSVC */

    return r;
}

/* ////////////////////////////////////////////////////////////////////// */

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

