@echo off

set progdir=%PROGRAMFILES%\Cppcheck

"%progdir%\cppcheck"  --version

:: "%progdir%\cppcheck"  --help

REM  --enable=all               Enable all checks
REM  --enable=possibleError     Make the checking more sensitive
REM  --enable=style             Check the coding style
REM  --enable=unusedFunctions   Check for unused functions
REM -q, --quiet     Print only error messages
REM -f, --force     Foorce checking ?????
REM -v, --verbose   Detailed error reports

set options= --enable=all,possibleError,style,unusedFunctions -f -v 
"%progdir%\cppcheck" %options% ..\..\AStyle\src

:: "%progdir%\cppcheck" %options% ..\..\AStyleWin\src> cppcheck.txt

echo -
pause
