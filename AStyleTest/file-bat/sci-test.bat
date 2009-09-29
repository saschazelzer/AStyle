@echo off

set testdata=..\..\TestData\scite

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyled

set excludes= --exclude=lua

set options= -vRQ
REM indent-blocks (B), add-brackets (j), break-blocks=all (F), align-pointer=type (k1)
:: set options= -CSKBNLwM50m10yejoOcFpPHUxEk1 -vRQ
REM indent-brackets (G), add-one-line-brackets (J), break-blocks (f), align-pointer=middle (k2)
:: set options= -CSKGNLwM50m10yeJoOcfpPHUxEk2 -vRQ


call  libCompile.bat  %astyle%
echo Formatting SciTE %options%

%astyle%  %options%  %excludes%  "%testdata%\*.cxx"  "%testdata%\*.h"  >  test.txt


echo -
pause
