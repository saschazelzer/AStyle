:: @echo off
REM build the astyle executables if necessary
REM called from the xx-test.bat files
REM builds only for Visual Studio
REM %1 is the path to the AStyle executable

set inpath=%1
set config=Release
set sdk=v3.5

REM extract the build directory from the input path
set builddir=%inpath:~0,25%
:: echo %builddir%

REM check directory for Visual Studio
:: echo %builddir:~19,6%
if not %builddir:~19,2% == vs  (
echo No Build %inpath:~19%
goto :END
)
if %builddir:~19,6% == vs2005  set sdk=v2.0.50727


REM check if release or debug
if %inpath:~-1% == e (
echo Building Release
) else (
if %inpath:~-1% == d (
echo Building Debug
set config=Debug
) else (
echo No Build %inpath:~19%
goto :END
)
)

%WINDIR%\Microsoft.NET\Framework\%sdk%\MSBuild  "/property:Configuration=%config%"  "%builddir%\AStyle.sln"  > NUL
if %ERRORLEVEL% NEQ 0 (
echo errors on compile
pause
exit 10
)


:END
:: pause
