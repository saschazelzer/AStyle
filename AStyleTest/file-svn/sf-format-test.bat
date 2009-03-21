@REM formats the astyletest source code in the test directory
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23


REM T - indent=force-tabs
REM  b - brackets=break; l - brackets=linux; 
REM  C - indent-classes;
REM  O - one-line=keep-blocks 
REM  c - convert-tabs; 

AStyle  -TbCO  ..\src\*.cpp 


echo -
echo -
echo * * * *  end of format  * * * *
pause
