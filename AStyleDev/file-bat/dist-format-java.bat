@REM formats the astylex Java source code
@echo off

set progdir=..\..\AStyle\build\vs2008\bin
set srcdir1=..\src-j
set srcdir2=..\src-jx


%progdir%\AStyle  -g -vQ  %srcdir1%\*.java 
%progdir%\AStyle  -g -vQ  %srcdir2%\*.java 

echo -
echo -
echo * * * *  end of Format Java  * * * *
pause
