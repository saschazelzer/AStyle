@REM formats the astyle source code
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23
set srcdir=..\..\AStyle\src


REM  b - brackets=break
REM  l - brackets=linux
REM  C - indent-classes
REM  O - one-line=keep-blocks
REM  H - pad-header
REM  c - convert-tabs
REM  v - verbose

AStyle  -tbCOv  %srcdir%\*.cpp 
AStyle  -tlCOv  %srcdir%\*.h 


echo -
echo -
echo * * * *  end of format  * * * *
pause
