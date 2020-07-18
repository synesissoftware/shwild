# Microsoft Developer Studio Project File - Name="shwild.core" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=shwild.core - Win32 Debug pseudoUNIX
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "shwild.core.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "shwild.core.mak" CFG="shwild.core - Win32 Debug pseudoUNIX"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "shwild.core - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "shwild.core - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "shwild.core - Win32 Debug Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "shwild.core - Win32 Debug Multithreaded DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "shwild.core - Win32 Release Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "shwild.core - Win32 Release Multithreaded DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "shwild.core - Win32 Debug pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "shwild.core - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.lib"

!ELSEIF  "$(CFG)" == "shwild.core - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.debug.lib"

!ELSEIF  "$(CFG)" == "shwild.core - Win32 Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMT"
# PROP BASE Intermediate_Dir "DebugMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMT"
# PROP Intermediate_Dir "DebugMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.mt.debug.lib"

!ELSEIF  "$(CFG)" == "shwild.core - Win32 Debug Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMTDLL"
# PROP BASE Intermediate_Dir "DebugMTDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMTDLL"
# PROP Intermediate_Dir "DebugMTDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.dll.debug.lib"

!ELSEIF  "$(CFG)" == "shwild.core - Win32 Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMT"
# PROP BASE Intermediate_Dir "ReleaseMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMT"
# PROP Intermediate_Dir "ReleaseMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.lib"
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.mt.lib"

!ELSEIF  "$(CFG)" == "shwild.core - Win32 Release Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMTDLL"
# PROP BASE Intermediate_Dir "ReleaseMTDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMTDLL"
# PROP Intermediate_Dir "ReleaseMTDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.lib"
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.dll.lib"

!ELSEIF  "$(CFG)" == "shwild.core - Win32 Debug pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUNIX"
# PROP BASE Intermediate_Dir "DebugUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUNIX"
# PROP Intermediate_Dir "DebugUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_STLSOFT_FORCE_ANY_COMPILER" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/shwild.0.core.vc6.debug.lib"

!ENDIF 

# Begin Target

# Name "shwild.core - Win32 Release"
# Name "shwild.core - Win32 Debug"
# Name "shwild.core - Win32 Debug Multithreaded"
# Name "shwild.core - Win32 Debug Multithreaded DLL"
# Name "shwild.core - Win32 Release Multithreaded"
# Name "shwild.core - Win32 Release Multithreaded DLL"
# Name "shwild.core - Win32 Debug pseudoUNIX"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\src\api.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\matches.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\pattern.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_selector.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\std\alt.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\auto_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\collections\util\collections.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\constraints.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_helper.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\library_discriminator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\msvc.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\obsolete.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\pod.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\safestr.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\shared_ptr.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\size_of.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std_swap.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\yesno.hpp"
# End Source File
# End Group
# End Group
# Begin Group "shwild Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\shwild\shwild.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\matches.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\pattern.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\shwild.assert.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\shwild.cover.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\shwild.safestr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\shwild.string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\shwild.vector.hpp
# End Source File
# End Group
# Begin Group "Documentation Files"

# PROP Default_Filter "src"
# Begin Source File

SOURCE="..\..\..\_internal\doc-src\mainpage.src"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\doc-src\shwild.css"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\doc-src\shwild.footer.html"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\doc-src\shwild.header.html"
# End Source File
# End Group
# End Target
# End Project
