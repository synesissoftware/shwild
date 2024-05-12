@echo off

SETLOCAL

SET SCRIPT_DIRECTORY=%~dp0

FOR /F "usebackq" %%f IN (`DIR /A:-D /B /S %SCRIPT_DIRECTORY% ^| FINDSTR /I test.*unit.*\.exe$`) DO (
	ECHO .
	ECHO executing %%f
	%%f
)

ENDLOCAL

