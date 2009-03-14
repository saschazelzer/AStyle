@echo off
REM test mingw "_CRT_glob = 0" option

:: set progdir=..\build\cb-borland\bin
set progdir=..\build\cb-dmars\bin
:: set progdir=..\build\cb-mingw\bin


%progdir%\AStyle  -atOP  ..\test-c\*.cpp  ..\test-c\*.h


echo -
pause
