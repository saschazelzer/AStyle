@echo off
REM Run gprof to print the profile report
REM AStylep must be run to create the gmon.out file

set gcovfile=ASFormatter
set mingwdir=C:\Programs\MinGW\bin

cd  ..\build\cb-mingw\objp\AStyle\src

REM check for the graph file created by the compile
if not exist *.gcno  (
echo Must compile AStylep to create the .gcno graph files!
pause
exit 100
)

REM check for the data file created by running the program
if not exist *.gcda  (
echo Must run AStylep to create the .gcda data files!
pause
exit 100
)

REM use the source file name to print the report
"%mingwdir%\gcov"  %gcovfile%

REM open the coverage file in SciTE
"C:\Program Files (x86)\SciTE\SciTE"  "%USERPROFILE%\Projects\AStyleDev\build\cb-mingw\objp\AStyle\src\%gcovfile%.cpp.gcov"


echo -
echo end of gcov
echo -
pause
