@REM formats the AStyleX C++ source code
@echo off

set progdir=C:\Program Files (x86)\AStyle
set srcdir1=..\src-c
set srcdir2=..\src-cx


"%progdir%\AStyle"  -A9k1 -Q  %srcdir1%\*.cpp
"%progdir%\AStyle"  -A9k1 -Q  %srcdir2%\*.cpp  %srcdir2%\*.h

echo -
echo -
echo * * * *  end of Format Cpp  * * * *
pause
