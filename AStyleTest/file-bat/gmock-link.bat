@echo off
REM Create a gmock link to the directory with the version number

set gmdir=gmock-1.6.0

:ckDir
if not exist ..\..\%gmdir% (
echo -
echo Cannot find directory %gmdir%
pause
goto :ckDir
)

if exist ..\..\gmock  rmdir ..\..\gmock

echo -

mklink  /J  ..\..\gmock   ..\..\%gmdir%

echo -
pause
