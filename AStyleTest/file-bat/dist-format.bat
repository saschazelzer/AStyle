@REM formats the astyle source code in the test directory
@echo off

set astyledir=..\..\AStyle
set srcdir=%astyledir%\src

:: set progdir=%astyledir%\buildcb-borland\bin
:: set progdir=%astyledir%\buildcb-dmars\bin
:: set progdir=%astyledir%\buildcb-mingw\bin
:: set progdir=%astyledir%\buildvs2003\bin
:: set progdir=%astyledir%\buildvs2005\bin
set progdir=%astyledir%\buildvs2008\bin


if not exist ..\test  md  ..\test
del ..\test\*.*  /q
copy %srcdir%\*.cpp  ..\test\
copy %srcdir%\*.h     ..\test\

REM  b - brackets=break; l - brackets=linux; 
REM  C - indent-classes;
REM  O - one-line=keep-blocks 
REM  c - convert-tabs; 
REM  Z - preserve-dates;

%progdir%\AStyle.exe  -tbCOcZ  ..\test\*.cpp 
%progdir%\AStyle.exe   -tlCOcZ  ..\test\*.h 

echo -
echo -
echo * * * *  end of dist-format  * * * *
pause
