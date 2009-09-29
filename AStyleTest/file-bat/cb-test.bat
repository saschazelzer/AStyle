@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyle

REM excludes because of %pythoncode
REM advprops.h is __WXPYTHON__ at line 192
REM propgrid.cpp is the macro IMPLEMENT_GET_VALUE
set exclude1= --exclude=wx\wxscintilla.h --exclude=wx\propgrid\advprops.h --exclude=wx\propgrid\manager.h
set exclude2= --exclude=wx\propgrid\propgrid.h --exclude=propgrid\propgrid.cpp

:: set options= -vRQ
REM indent-blocks (B), add-brackets (j), break-blocks=all (F), align-pointer=type (k1)
set options= -CSKBNLwM50m10yejoOcFpPHUxEk1 -vRQ
REM indent-brackets (G), add-one-line-brackets (J), break-blocks (f), align-pointer=middle (k2)
:: set options= -CSKGNLwM50m10yeJoOcfpPHUxEk2 -vRQ


call  libCompile.bat  %astyle%
echo Formatting CodeBlocks %options%

%astyle%  %options%  %exclude1%%exclude2%  "%testdata%\CodeBlocks\src\*.cpp"  "%testdata%\CodeBlocks\src\*.h"  > test.txt


echo -
pause
