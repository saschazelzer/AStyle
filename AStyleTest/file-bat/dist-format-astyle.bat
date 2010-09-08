@REM formats the astyle source code
@echo off

set PATH=PATH;"C:\Program Files (x86)\AStyle
set prog=AStyle

REM  b - brackets=break
REM  l - brackets=linux
REM  H - pad-header
REM  C - indent-classes
REM  O - one-line=keep-blocks
REM k1 - align-pointer=type
REM  c - convert-tabs
REM  v - verbose
REM Q - formatted

set options= -tbHCO  -Q --options=none
set optionsh= -tlHCO  -Q --options=none

echo Formatting AStyle
echo source %options%  
echo headers%optionsh%
echo -

%prog%  %options%  ..\..\AStyle\src\*.cpp
echo -
%prog%  %optionsh%  ..\..\AStyle\src\*.h 


echo -
echo * * * *  end of format  * * * *
pause
