@REM formats the astyle source code in the test directory
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23
set srcdir=..\..\AStyle\src


echo --------------------------------------------------
echo copy files to ..\test\*.cpp
echo --------------------------------------------------
if not exist ..\test  md  ..\test
del ..\test\*.*  /q
copy %srcdir%\*.cpp  ..\test\
copy %srcdir%\*.h     ..\test\

REM  b - brackets=break; l - brackets=linux; 
REM  C - indent-classes;
REM  O - one-line=keep-blocks 
REM  c - convert-tabs; 

AStyle  -tbCO  ..\test\*.cpp 
AStyle  -tlCO  ..\test\*.h 


echo -
echo -
echo * * * *  end of format  * * * *
pause
