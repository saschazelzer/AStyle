@REM formats the astyletest source code in the test directory
@echo off

set PATH=PATH;"%PROGRAMFILES%\astyle_1.23


echo --------------------------------------------------
echo copy files to ..\test\*.cpp
echo --------------------------------------------------
if not exist ..\test  md  ..\test
del ..\test\*.*  /q
copy ..\src\*.cpp  ..\test\

REM T - indent=force-tabs
REM  b - brackets=break; l - brackets=linux; 
REM  C - indent-classes;
REM  O - one-line=keep-blocks 
REM  c - convert-tabs; 

AStyle  -TbCO  ..\test\*.cpp 


echo -
echo -
echo * * * *  end of format  * * * *
pause
