@echo off
REM build the UnitTest++ vs2008 libraries

set utdir=..\..\UnitTest++

echo BUILDING DEBUG
%windir%\microsoft.net\framework\v3.5\msbuild  /nologo  "/property:Configuration=Debug"  "%utdir%\UnitTest++.vsnet2008.sln"
if %ERRORLEVEL% NEQ 0  pause

echo -
echo CLEANING DEBUG
del  %utdir%\obj\UnitTest++.vsnet2008\Debug\*.obj  /s /q  > NUL

echo -
echo BUILDING RELEASE
%windir%\microsoft.net\framework\v3.5\msbuild  /nologo  "/property:Configuration=Release"  "%utdir%\UnitTest++.vsnet2008.sln"
if %ERRORLEVEL% NEQ 0  pause

echo -
echo CLEANING RELEASE
del  %utdir%\obj\UnitTest++.vsnet2008\Release\*.obj  /s /q  > NUL


echo -
pause
