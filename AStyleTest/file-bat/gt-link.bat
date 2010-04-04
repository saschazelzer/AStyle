@echo off
REM Create a gtest link to the directory with the version number

set gtdir=gtest-1.4.0

:ckDir
if not exist ..\..\%gtdir% (
echo -
echo Cannot find directory %gtdir%
pause
goto :ckDir
)

if exist ..\..\gtest  rmdir ..\..\gtest

echo -

mklink  /J  ..\..\gtest   ..\..\%gtdir%

echo -
pause
