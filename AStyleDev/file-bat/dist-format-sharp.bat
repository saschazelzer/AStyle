@REM formats the astylex Java source code
@echo off

::set progdir=..\..\AStyle\_VC-2003\bin
set progdir=..\..\AStyle\_VC-2008\bin
set srcdir1=..\src-s
set srcdir2=..\src-sx


%progdir%\AStyle  -l  %srcdir1%\*.cs
%progdir%\AStyle  -l  %srcdir2%\*.cs 

echo -
echo -
echo * * * *  end of Format Sharp  * * * *
pause
