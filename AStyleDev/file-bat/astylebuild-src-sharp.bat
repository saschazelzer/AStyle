@echo off
REM build the AStyle Release Dll Configuration using the AStyle project file
REM copy the output to the AStyleDev\test-sx) folder

REM %1 should be the Visual Studio release date
set astyle=..\..\AStyle\build\vs2008
set bindir1=..\src-s
set bindir2=..\src-sx
set sdk=no
set sdk=v3.5
if %astyle:~-6% == vs2010  set sdk=v4.0.21006
set errors=no

echo BUILDING ASTYLE DLL
%windir%\microsoft.net\framework\%sdk%\msbuild  /nologo  "/property:Configuration=Release"  "%astyle%\AStyleDll.sln"
if %ERRORLEVEL% NEQ 0  set errors=yes

REM don't copy if compile errors
if not %errors%==yes (
echo -
echo COPYING
xcopy "%astyle%\bin\AStyle.dll"  "%bindir1%\"  /y /q
if %ERRORLEVEL% NEQ 0  set errors=yes
xcopy "%astyle%\bin\AStyle.dll"  "%bindir2%\"  /y /q
if %ERRORLEVEL% NEQ 0  set errors=yes
)

if %errors%==yes (
echo * * * *  ERRORS IN PROCESSING SCRIPT  * * * *
exit 100
)

echo -
pause
