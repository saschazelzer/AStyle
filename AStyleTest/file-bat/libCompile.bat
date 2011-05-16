:: @echo off
REM build the astyle executables if necessary
REM called from the xx-test.bat files
REM builds only for Visual Studio
REM %1 is the path to the AStyle executable
REM sdk is Windiws the sub directory - default is vs2005
REM config is Release or Debug
set inpath=%1
set sdk=v2.0.50727
set config=Release

REM extract the build directory from the input path
set vsdir=%inpath:~0,22%
set builddir=%inpath:~16%

if %inpath:~0,6% == ..\..\  (
set vsdir=%inpath:~0,25%
set builddir=%inpath:~19%
)

:: echo %vsdir%
:: echo %builddir%
:: pause

REM check directory for Visual Studio
if not %builddir:~0,2% == vs  (
echo No Build %builddir%
goto :END
)
if %builddir:~0,6% == vs2008  set sdk=v3.5
if %builddir:~0,6% == vs2010  set sdk=v4.0.30319


REM check if release or debug
REM NOTE: the case of the == must match!
if %builddir:~-6% == AStyle (
echo Building Release
) else (
if %builddir:~-7% == AStyled (
echo Building Debug
set config=Debug
) else (
echo No Build %builddir%
goto :END
)
)

%WINDIR%\Microsoft.NET\Framework\%sdk%\MSBuild  "/property:Configuration=%config%"  "/property:Platform=Win32"  "%vsdir%\AStyle.sln" > NUL
if %ERRORLEVEL% NEQ 0 (
echo errors on compile
pause
exit 10
)


:END
:: pause
