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
set appfile=%APPDATA%\.emacs.d\astyle-hooks.el

REM check for program file
if not exist "%asdir%\AStyle.exe" (
echo AStyle program not found
pause
exit
)

echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *          Get Variables from astyle-hooks.el           *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

REM get style variable from astyle-hooks.el file
REM do NOT use %%~v to strip the quotes, the & in k&r causes problems
set style-string=findstr /c:"setq c-default-style"  %appfile%
for  /f  "tokens=3 delims=() "  %%v  in ('%style-string%') do  set style=%%v
if not defined style (
echo style variable not found
pause
exit
)

REM get namespace variable from astyle-hooks.el file
set namespace-string=findstr /c:"setq indent-namespaces"  %appfile%
for  /f  "tokens=3 delims=() "  %%v  in ('%namespace-string%') do  set yes-no=%%~v
if %yes-no% == yes  set namespace=-N

REM get class variable from astyle-hooks.el file
set class-string=findstr /c:"setq indent-classes"  %appfile%
for  /f  "tokens=3 delims=() "  %%v  in ('%class-string%') do  set yes-no=%%~v
if %yes-no% == yes  set class=-C

REM display variables
REM m=min-conditional-indent, M=max-instatement-indent, n=no backup, 
echo -
set options=  --style=%style%  %namespace%  %class%  -m0M50n
echo options:%options% 
echo -
pause

REM loop thru the input directory and find the files
REM CONVERT is called outside the FOR loop so the variables will be resolved
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


SETLOCAL
REM CONVERT
REM %1 is the input file path including the filename
:CONVERT
REM do AStyle first since Emacs cannot change the bracket type (break, attach, linux, stroustrup)
REM then do Emacs and save with an .emacs extension
REM the 'user' option explicitely loads the .emacs file since it is not done when 'batch' is used
echo -
call  set /A  count += 1
echo File: %count%

REM process the file
"%asdir%\AStyle"  %options%  "%1"
"%emdir%\emacs"  --batch  "--visit=%1"  "--user=jp"  "--load=~\.emacs.d\format-file"

REM echo for every 100 files processed
set /A  mod=%count%%%10
if %mod% == 0 (
echo -
echo %count% files processed
echo -
pause
)

goto :EOF
ENDLOCAL


:EOF
