@REM formats the astyletest source code in the test directory
@echo off

set PATH=PATH;"%PROGRAMFILES%\AStyle
set prog=AStyle24e

REM  T - indent=force-tabs
REM  b - brackets=break
REM  H - pad-header
REM  C - indent-classes
REM  O - one-line=keep-blocks
REM k1 - align-pointer=type
REM  c - convert-tabs
REM  v - verbose
REM Q - formatted

set options= -TbHCO  -vQ --options=none
set optionsh= -TlHCO  -vQ --options=none

echo Formatting AStyleTest
echo source%options%  headers%optionsh%
echo -

%prog%  %options%  ..\src\*.cpp
echo -
%prog%  %optionsh%  ..\src\*.h 
echo -
%prog%  %options%  ..\srccon\*.cpp 

echo -
echo * * * *  end of format  * * * *
pause
