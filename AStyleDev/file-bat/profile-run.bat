@echo off
REM Run AStylep executable to create the gmon.out file
REM Code must be compiled with the Profile target in MinGW AStyle

set progdir=..\build\cb-mingw\bin
set testdir=..\..\TestData\CodeBlocks\src

REM check for the compiled program
if not exist "%progdir%\AStylep.exe"  (
echo Must compile AStyle with the Profile configuration!
pause
exit 100
)


REM do NOT use recursive
:: "%progdir%\AStylep"   -CSKBNLwM50m10FyexpPUoOcEv  "%testdir%\ASBeautifier.cpp"
:: "%progdir%\AStylep"   -CSKBNLwM50m10FyexpPUoOcEv  "%testdir%\ASBeautifier.java"
"%progdir%\AStylep"   -CSKBNLwM50m10FyexpPUoOcERv  "%testdir%\*.cpp"


echo -
pause
