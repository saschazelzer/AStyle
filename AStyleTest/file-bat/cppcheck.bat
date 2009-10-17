@echo off

set progdir=%PROGRAMFILES%\Cppcheck 1.37

:: "%progdir%\cppcheck"  --version

:: "%progdir%\cppcheck"  --help

REM -a, --all
REM -q, --quiet
REM -f, --force

"%progdir%\cppcheck" -a -q -f --style --unused-functions ..\..\AStyle\src

:: "%progdir%\cppcheck" -a -q -f --style --unused-functions ..\..\AStyleWin\src


echo -
pause
