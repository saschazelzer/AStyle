@echo off

set progdir=%PROGRAMFILES%\cppcheck

:: "%progdir%\cppcheck" -h

"%progdir%\cppcheck" -a -q -f --style ..\..\AStyle\src

:: "%progdir%\cppcheck" -a -q -f --style --unused-functions ..\..\AStyleWin\src


echo -
pause
