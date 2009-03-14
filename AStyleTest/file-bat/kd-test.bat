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


set excludes= --exclude=app_templates

%progdir%\AStyle  -vR  %excludes%  "%testdata%\kdevelop\*.cpp"  "%testdata%\kdevelop\*.h"  > test.txt

:: %progdir%\AStyle  -CSKBGNLwM50m10yexpPUoOCEvR  %excludes%  "%testdata%\kdevelop\*.cpp"  "%testdata%\kdevelop\*.h"  > test.txt

REM removed confilicts with release 1.22, removed oO
:: %progdir%\AStyle  -CSKNLwM50m10yepPUEvR  %excludes%  "%testdata%\kdevelop\*.cpp"  "%testdata%\kdevelop\*.h"  > test.txt


echo -
pause
