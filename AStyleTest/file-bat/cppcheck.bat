@echo off

set progdir=C:\Program Files (x86)\Cppcheck

"%progdir%\cppcheck"  --version

:: "%progdir%\cppcheck"  --help

REM  --enable=all               Enable all checks
REM           style             Check the coding style
REM           information       Enable information messages
REM           unusedFunction    Check for unused functions
REM           missingInclude    Check for missing includes
REM -f, --force        Force checking on files that have "too many"  configurations.
REM -v, --verbose      More detailed error reports.
REM -j <jobs>          Start [jobs] threads. (not implemented on Windows).
REM -q, --quiet        Only print error messages.
REM --report-progress  Report progress messages while checking a file.
REM --xml              Write results in xml to error stream.
REM --suppress=<spec>  Suppress a specific warning.

set options= --enable=all --force --verbose --xml
REM Checking uninitialized variables lists errors for variables in the "init" functions.
REM For some reason using the filename and line don't work here?
set suppress= --suppress=uninitVar

"%progdir%\cppcheck" %options% %suppress% ..\..\AStyle\src


echo -
pause
