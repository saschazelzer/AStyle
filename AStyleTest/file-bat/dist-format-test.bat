@REM formats the astyletest source code in the test directory
@echo off

set PATH=PATH;"C:\Program Files (x86)\AStyle
set prog=AStyle

REM  T - indent=force-tabs
REM  b - brackets=break
REM  H - pad-header
REM  C - indent-classes
REM  O - keep-one-line-blocks
REM k1 - align-pointer=type
REM  v - verbose
REM  w - indent-preprocessor
REM  Q - formatted
REM  x - delete-empty-lines
REM z1 - windows lineends

set options= -A1THCOwk1  -Qz1  --options=none
set optionsh= -A3THCOwk1  -Qz1  --options=none

echo Formatting AStyleTest
echo source %options%
echo headers%optionsh%
echo -

%prog%  %options%  ..\src\*.cpp
echo -
%prog%  %optionsh%  ..\src\*.h
echo -
%prog%  %options%  ..\srccon\*.cpp
echo -
%prog%  %options%  ..\srccon\*.h
echo -
%prog%  %options%  ..\srci18n\*.cpp
echo -
REM override force-tabs with tabs
%prog%  %options%  -t  ..\srcx\*.cpp
echo -
%prog%  %options%  -t  ..\srcx\*.h

echo -
echo * * * *  end of format  * * * *
pause
