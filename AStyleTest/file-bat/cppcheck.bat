@echo off

set progdir=C:\Program Files (x86)\Cppcheck

:: "%progdir%\cppcheck"  --version

:: "%progdir%\cppcheck"  --help

REM  --enable=all               Enable all checks
REM           style             Check the coding style
REM           information       Enable information messages
REM           unusedFunction    Check for unused functions
REM           missingInclude    Check for missing includes
REM -q, --quiet     Print only error messages
REM -f, --force     Foorce checking ?????
REM -v, --verbose   Detailed error reports

set options= --enable=all,style,information,unusedFunction,missingInclude -f -v --xml 
REM Checking uninitialized variables for lists errors for the errors in the "init" functions.
REM For some reason using the filename and line don't work here?
REM Most other warnings can be eliminated with --suppress=stlSize.
set suppress= --suppress=uninitVar 

"%progdir%\cppcheck" %options% %suppress% ..\..\AStyle\src

:: "%progdir%\cppcheck" %options% ..\..\AStyleWin\src> cppcheck.txt

echo -
pause
