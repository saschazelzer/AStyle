@REM formats the astyletest source code in the test directory
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23


REM  T - indent=force-tabs
REM  b - brackets=break
REM  C - indent-classes
REM  O - one-line=keep-blocks
REM  H - pad-header
REM  c - convert-tabs
REM  v - verbose

AStyle  -TbCOv  ..\src\*.cpp 


echo -
echo -
echo * * * *  end of format  * * * *
pause
