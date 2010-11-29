@REM formats the astylex Java source code
@echo off

set progdir=C:\Program Files (x86)\AStyle
set srcdir1=..\src-j
set srcdir2=..\src-jx


"%progdir%\AStyle"  -g -Q  %srcdir1%\*.java 
"%progdir%\AStyle"  -g -Q  %srcdir2%\*.java 

echo -
echo -
echo * * * *  end of Format Java  * * * *
pause
