@REM formats the astylex Java source code
@echo off

set progdir=..\..\AStyle\build\vs2008\bin
set srcdir1=..\src-s
set srcdir2=..\src-sx


%progdir%\AStyle  -g  %srcdir1%\*.cs
%progdir%\AStyle  -g  %srcdir2%\*.cs 

echo -
echo -
echo * * * *  end of Format Sharp  * * * *
pause
