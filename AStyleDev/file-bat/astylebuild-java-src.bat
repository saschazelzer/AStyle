@echo off
REM build the AStyle Release Java Configuration using the AStyle project file
REM copy the output to the AStyleDev/test-j(x)  folder

set astyle=..\..\AStyle\build\vs2008
set bindir1=..\src-j
set bindir2=..\src-jx
set errors=no
set called=no

REM the following batch file is needed for VS2005
REM and change the build directory to buildvs2005
REM call "%VS80COMNTOOLS%\vsvars32.bat"

echo BUILDING ASTYLE JAVA
%windir%\microsoft.net\framework\v3.5\msbuild  /nologo  "/property:Configuration=Release Java"  "%astyle%\AStyle.sln"
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

if %called%==yes  (
if %errors% == yes exit 100
) else (
echo -
pause
)
