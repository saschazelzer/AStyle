@echo off
REM build the AStyle Release Dll Configuration using the AStyle project file
REM copy the output to the AStyleDev folder

REM %1 should be the Visual Studio release date
set astyle=..\..\AStyle\build\%1
set bindir=..\build\%1\bin
set sdk=no
if %1 == vs2005  set sdk=v2.0.50727
if %1 == vs2008  set sdk=v3.5
if %1 == vs2010  set sdk=v4.0.21006
set errors=no
set called=no

REM if called from a compile, the directory structure is different
if not exist astylebuild-dll.bat (
set called=yes
set astyle=..\..\%astyle%
set bindir=..\..\%bindir%
)

echo BUILDING ASTYLE DLL
%windir%\microsoft.net\framework\%sdk%\msbuild  /nologo  "/property:Configuration=Release"  "%astyle%\AStyleDll.sln"
if %ERRORLEVEL% NEQ 0  set errors=yes

REM don't copy if compile errors
if not %errors%==yes (
echo -
echo COPYING
if not exist "%bindir%"  mkdir "%bindir%"
xcopy "%astyle%\bin\AStyle.dll"  "%bindir%\"  /y /q
if %ERRORLEVEL% NEQ 0  set errors=yes
xcopy "%astyle%\bin\AStyle.lib"  "%bindir%\"  /y /q
if %ERRORLEVEL% NEQ 0  set errors=yes
)

if %errors%==yes (
if %sdk%==no (
echo Invalid call parameter %1.
)
echo * * * *  ERRORS IN PROCESSING SCRIPT  * * * *
)

if %called%==yes  (
if %errors% == yes exit 100
) else (
echo -
pause
)
