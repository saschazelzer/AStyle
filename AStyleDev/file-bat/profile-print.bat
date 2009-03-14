@echo off

set progdir=..\build\cb-mingw\bin
set mingwdir=C:\Programs\MinGW\bin


REM do NOT use recursive
%mingwdir%\gprof  "%progdir%\AStylep.exe"  > profile.txt


echo -
pause
