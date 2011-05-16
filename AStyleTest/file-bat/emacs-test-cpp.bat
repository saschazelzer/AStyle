@echo off
REM this file will format source code with both AStyle and Emacs
REM the Emacs files will have an .emacs extension
REM the format options are obtained from the .emacs file
REM this file uses format-file.el when calling Emacs

REM CHANGE THE FOLLOWING VARIABLES
REM indir is the input top level directory containing the files
set indir=%USERPROFILE%\Projects\TestData\CodeBlocks\src
set fileext=.cpp

set asdir=..\..\AStyle\build\vs2008\bin
set emdir=C:\Program Files\Emacs\bin

REM check for program file
if not exist "%asdir%\AStyle.exe" (
echo AStyle program not found
pause
exit
)

REM loop thru the input directory and find the files
REM MOVEIT is called outside the FOR loop so the variables will be resolved
REM arguments must be in quotes to allow spaces in names
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                   Converting Files                    *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
for /R  "%indir%"  %%v   in (*%fileext%)  do (
    call  :CONVERT  "%%v"
)
echo %count% files processed
echo -
pause
goto :EOF

:CONVERT
:: echo %1
REM increment the file count
call  set /A  count += 1
REM echo for every 100 files processed
set /A  mod=%count%%%100
if %mod% == 0 echo %count% files processed

goto :EOF



:EOF
