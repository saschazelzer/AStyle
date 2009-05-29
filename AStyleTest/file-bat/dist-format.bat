@REM formats the astyle source code
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23
set srcdir=..\..\AStyle\src


REM  b - brackets=break
REM  l - brackets=linux
REM  H - pad-header
REM  C - indent-classes
REM  O - one-line=keep-blocks
REM  c - convert-tabs
REM  v - verbose
REM Q - formatted

set options= -tbCOvQ
set optionsh= -tlCOvQ

echo Formatting AStyle  source%options%  headers%optionsh%
echo -

AStyle  %options%  %srcdir%\*.cpp
echo -
AStyle  %optionsh%  %srcdir%\*.h 


echo -
echo * * * *  end of format  * * * *
pause
