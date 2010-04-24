@REM formats the AStyleX C++ source code
@echo off

set progdir=C:\Program Files\AStyle
set srcdir1=..\src-c
set srcdir2=..\src-cx


"%progdir%\AStyle"  -gk3 -vQ  %srcdir1%\*.cpp
"%progdir%\AStyle"  -gk3 -vQ  %srcdir2%\*.cpp  %srcdir2%\*.h

echo -
echo -
echo * * * *  end of Format Cpp  * * * *
pause
