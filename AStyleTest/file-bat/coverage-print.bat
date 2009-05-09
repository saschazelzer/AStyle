@echo off
REM Run gcov to print the coverage report
REM AStylec must be run to create the *.gcno files

set mingwdir=C:\Programs\MinGW\bin

cd  ..\build\cb-mingw\obj\Coverage\AStyle\src

REM check for the graph file created by the compile
if not exist *.gcno  (
echo Must compile AStylec to create the .gcno graph files!
pause
exit 100
)

REM check for the data file created by running the program
if not exist *.gcda  (
echo Must run AStylec to create the .gcda data files!
pause
exit 100
)

REM use the source file name to print the report
"%mingwdir%\gcov"  ASFormatter

REM open the coverage file in SciTE
start "%PROGRAMFILES%\SciTE\SciTE"  %USERPROFILE%\Projects\AStyle\src\ASFormatter.cpp.gcov


echo -
echo end of gcov
echo -
pause
