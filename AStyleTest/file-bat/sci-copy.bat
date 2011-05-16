@echo off

set testdata=..\..\TestData
set progdir=..\..\

REM remove SciTE
if exist "%testdata%\scite" (
echo -
echo Removing directory scite
rmdir  /s  "%testdata%\scite"
)

REM copy SciTE
echo -
echo copying SciTE
xcopy "%progdir%\scite\*.h"    "%testdata%\scite\"  /s /y /q
xcopy "%progdir%\scite\*.cxx"  "%testdata%\scite\"  /s /y /q
xcopy "%progdir%\scite\*.c"    "%testdata%\scite\"  /s /y /q

echo -
pause
