@echo off

REM this file will format source code with both AStyle and Emacs
REM the Emacs files will have an .emacs extension
REM the format options are obtained from the .emacs file
REM this file uses format-file.el when calling Emacs

REM variables
set filedir=..\..\EmacsTest
set appfile=%APPDATA%\.emacs.d\astyle-hooks.el

set asdir=..\..\AStyle\build\vs2008\bin
set emdir=C:\Program Files\Emacs\bin

echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *             Formatting Emacs Test Files               *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

REM check for program file
if not exist "%asdir%\AStyle.exe" (
echo AStyle program not found
pause
exit
)

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


REM do AStyle first since Emacs cannot change the bracket type (break, attach, linux, stroustrup)
REM then do Emacs and save with an .emacs extension
REM the 'user' option explicitely loads the .emacs file since it is not done when 'batch' is used
echo -
if exist "%filedir%\*.cpp" (
for %%v in ("%filedir%\*.cpp")  do (
echo -
echo %%~nxv
"%asdir%\AStyle"  %options%  "%%v"
"%emdir%\emacs"  --batch  "--visit=%%v"  "--user=jp"  "--load=~\.emacs.d\format-file"
)
)
if exist "%filedir%\*.h" (
for %%v in ("%filedir%\*.h")  do (
echo -
echo %%~nxv
"%asdir%\AStyle"  %options%  "%%v"
"%emdir%\emacs"  -batch  "--visit=%%v"  "--user=jp"  "--load=~\.emacs.d\format-file"
)
)
if exist "%filedir%\*.java" (
for %%v in ("%filedir%\*.java")  do (
echo -
echo %%~nxv
"%asdir%\AStyle"  %options%  "%%v"
"%emdir%\emacs"  -batch  "--visit=%%v"  "--user=jp"  "--load=~\.emacs.d\format-file"
)
)
if exist "%filedir%\*.cs" (
for %%v in ("%filedir%\*.cs")  do (
echo -
echo %%~nxv
"%asdir%\AStyle"  %options%  "%%v"
"%emdir%\emacs"  -batch  "--visit=%%v"  "--user=jp"  "--load=~\.emacs.d\format-file"
)
)


echo -
echo -
pause
