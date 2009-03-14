@echo off

set progdir=..\build\cb-mingw\bin
set testdir=..\..\TestData\CodeBlocks\src


REM do NOT use recursive
:: "%progdir%\AStylep"   -CSKBNLwM50m10FyexpPUoOcEv  "%testdir%\ASBeautifier.cpp"
:: "%progdir%\AStylep"   -CSKBNLwM50m10FyexpPUoOcEv  "%testdir%\ASBeautifier.java"
"%progdir%\AStylep"   -CSKBNLwM50m10FyexpPUoOcERv  "%testdir%\*.cpp"

echo -
pause
