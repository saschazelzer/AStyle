@REM formats the astyle source code
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23
set srcdir=..\..\AStyle\src


REM  b - brackets=break; l - brackets=linux; 
REM  C - indent-classes;
REM  O - one-line=keep-blocks 
REM  c - convert-tabs; 

AStyle  -tbCO  %srcdir%\*.cpp 
AStyle  -tlCO  %srcdir%\*.h 


echo -
echo -
echo * * * *  end of format  * * * *
pause
