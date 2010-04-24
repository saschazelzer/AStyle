@echo off
REM build the AStyle Release Java Configuration using the AStyle project file
REM copy the output to the AStyleDev\test-j(x) folder

set astyle=..\..\AStyle\build\vs2005
set bindir1=..\src-j
set bindir2=..\src-jx
set sdk=v3.5
if %astyle:~-6% == vs2005  set sdk=v2.0.50727
if %astyle:~-6% == vs2008  set sdk=v3.5
if %astyle:~-6% == vs2010  set sdk=v4.0.30319
set errors=no

echo BUILDING ASTYLE JAVA
%windir%\microsoft.net\framework\%sdk%\msbuild  /nologo  "/property:Configuration=Release"  "%astyle%\AStyleJava.sln"
if %ERRORLEVEL% NEQ 0  set errors=yes

REM don't copy if compile errors
if not %errors%==yes (
echo -
echo COPYING
xcopy "%astyle%\bin\AStylej.dll"  "%bindir1%\"  /y /q
if %ERRORLEVEL% NEQ 0  set errors=yes
xcopy "%astyle%\bin\AStylej.dll"  "%bindir2%\"  /y /q
if %ERRORLEVEL% NEQ 0  set errors=yes
)

if %errors%==yes (
echo -
echo * * * *  ERRORS IN PROCESSING SCRIPT  * * * *
)

echo -
pause
