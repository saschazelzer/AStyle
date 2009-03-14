@echo off

set testdata=..\..\TestData
set astyledir=..\..\AStyle

:: set progdir=%astyledir%\build\cb-borland\bin
:: set progdir=%astyledir%\build\cb-dmars\bin
:: set progdir=%astyledir%\build\cb-mingw\bin
:: set progdir=%astyledir%\build\vs2003\bin
:: set progdir=%astyledir%\build\vs2005\bin
set progdir=%astyledir%\build\vs2008\bin


:: %progdir%\AStyle  -h
:: %progdir%\AStyle  -V

:: set ARTISTIC_STYLE_OPTIONS=.\astylerc


%progdir%\AStyle  -vR  "%testdata%\jEdit\*.java"  > test.txt

:: %progdir%\AStyle  -CSKBGNLwM50m10yexpPUoOCEvR  "%testdata%\jEdit\*.java" > test.txt

REM removed confilicts with release 1.22, removed oO
:: %progdir%\AStyle  -CSKNLwM50m10yepPUEvR  "%testdata%\jEdit\*.java" > test.txt


echo -

pause
