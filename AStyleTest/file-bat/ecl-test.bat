@echo off

set testdata=..\..\TestData
set astyledir=..\..\AStyle

:: set progdir=%astyledir%\buildcb-borland\bin
:: set progdir=%astyledir%\buildcb-dmars\bin
:: set progdir=%astyledir%\buildcb-mingw\bin
:: set progdir=%astyledir%\buildvs2003\bin
:: set progdir=%astyledir%\buildvs2005\bin
set progdir=%astyledir%\buildvs2008\bin


:: %progdir%\AStyle  -h
:: %progdir%\AStyle  -V

:: set ARTISTIC_STYLE_OPTIONS=.\astylerc


:: %progdir%\AStyled  -Rv  "%testdata%\eclipse\*.java"  > test.txt
REM NO indent-blocks
%progdir%\AStyled   -CSKBNLwM50m10FepPUoOcERv  "%testdata%\eclipse\*.java"

echo -

pause
