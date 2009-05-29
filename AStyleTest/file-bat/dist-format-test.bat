@REM formats the astyletest source code in the test directory
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23


REM  T - indent=force-tabs
REM  b - brackets=break
REM  H - pad-header
REM  C - indent-classes
REM  O - one-line=keep-blocks
REM  c - convert-tabs
REM  v - verbose
REM Q - formatted

set options= -TbCOvQ
set optionsh= -TlCOvQ

echo Formatting AStyleTest  source%options%  headers%optionsh%
echo -

AStyle  %options%  ..\src\*.cpp
echo -
AStyle  %optionsh%  ..\src\*.h 

echo -
echo * * * *  end of format  * * * *
pause
