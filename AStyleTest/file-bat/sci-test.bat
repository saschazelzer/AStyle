@echo off

set testdata=..\..\TestData\scite
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


set errfile="%USERPROFILE%\Documents\sci-test.txt"

set excludes= --exclude=lua

%progdir%\AStyle  -Rv  %excludes%  "%testdata%\*.cxx"  "%testdata%\*.h"  >  test.txt

REM NO indent-blocks
:: %progdir%\AStyle   -bCSKBNLwM50m10FepPUoOcERv  %excludes%  "%testdata%\*.cxx"  "%testdata%\*.h"  >  test.txt


echo -

pause
