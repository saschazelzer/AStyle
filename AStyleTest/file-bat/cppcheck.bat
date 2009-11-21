@echo off

set progdir=%PROGRAMFILES%\Cppcheck 1.37

:: "%progdir%\cppcheck"  --version

:: "%progdir%\cppcheck"  --help

REM -a, --all			Make the checking more sensitive
REM -q, --quiet		Print only error messages
REM -f, --force		Foorce checking ?????
REM -s, --style		Check the coding style
REM -v, --verbose	Detailed error reports

"%progdir%\cppcheck" -a -f -s -v --unused-functions ..\..\AStyle\src

:: "%progdir%\cppcheck" -a -f -s -v --unused-functions ..\..\AStyleWin\src> cppcheck.txt

echo -
pause
