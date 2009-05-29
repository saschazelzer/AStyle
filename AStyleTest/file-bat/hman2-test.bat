@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyled

REM -----------------------------------
REM STYLE
REM g - brackets=horstmann
REM t3 -  indent=tab=3  OR  s3 -  iindent=spaces=3
REM S - indent-switches
REM U - unpad-paren
REM H - pad-header
REM -----------------------------------
REM ADDITIONAL
REM O - keep-one-line-blocks
REM o - keep-one-line-statements
REM -----------------------------------
REM OPTIONAL
REM p - pad-oper
REM -----------------------------------

set options= -gs3SUHOo -vRQ

call  libCompile.bat  %astyle%
echo Formatting Horstmann2 %options%

REM C++
:: %astyle%  %options%  "%testdata%\Horstmann2\*.cpp"  "%testdata%\Horstmann2\*.h"  > test.txt
REM Java
%astyle%  %options%  "%testdata%\Horstmann2\*.java"  > test.txt


echo -
pause
