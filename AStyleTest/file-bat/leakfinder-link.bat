@echo off
REM Create a gmock link to the directory with the version number

set lfdir=leakfinder-RC11

:ckDir
if not exist ..\..\%lfdir% (
echo -
echo Cannot find directory %lfdir%
pause
goto :ckDir
)

if exist ..\..\LeakFinder  rmdir ..\..\\LeakFinder

echo -

mklink  /J  ..\..\\LeakFinder   ..\..\%lfdir%

echo -
pause
