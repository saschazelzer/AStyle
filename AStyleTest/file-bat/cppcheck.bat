@echo off

set progdir=%PROGRAMFILES%\cppcheck

:: "%progdir%\cppcheck"  --version

:: "%progdir%\cppcheck"  --help

:: "%progdir%\cppcheck" -a -q -f --style --unused-functions ..\..\AStyle\src

"%progdir%\cppcheck" -a -q -f --style --unused-functions ..\..\AStyleWin\src


echo -
pause
