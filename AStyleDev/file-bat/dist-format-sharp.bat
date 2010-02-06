@REM formats the astylex Java source code
@echo off

set progdir=C:\Program Files\AStyle
set srcdir1=..\src-s
set srcdir2=..\src-sx


"%progdir%\AStyle"  -g -vQ  %srcdir1%\*.cs
"%progdir%\AStyle"  -g -vQ  %srcdir2%\*.cs 

echo -
echo -
echo * * * *  end of Format Sharp  * * * *
pause
