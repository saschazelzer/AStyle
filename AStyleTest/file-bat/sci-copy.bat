@echo off

REM USB is not used
:checkUSB
set USBdrive=E:
if not exist E:\USB (
set USBdrive=F:
if not exist F:\USB (
set USBdrive=G:
if not exist G:\USB (
set USBdrive=H:
if not exist H:\USB (
echo -
echo Mount USB drive
pause
goto :checkUSB
)
)
)
)

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
