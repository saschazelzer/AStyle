@echo off
REM Run gprof to print the profile report
REM AStylep must be run to create the gmon.out file

set progdir=..\build\cb-mingw\bin
set mingwdir=C:\Programs\MinGW\bin

REM check for the compiled program
if not exist gmon.out  (
echo Must run AStylep to create gmon.out!
pause
exit 100
)

REM do NOT use recursive
%mingwdir%\gprof  "%progdir%\AStylep.exe"  > profile.txt

echo -
echo end of gprof
echo -
pause
