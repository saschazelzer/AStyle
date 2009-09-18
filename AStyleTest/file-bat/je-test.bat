@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyled

set options= -vRQ
REM with indent-blocks (B), add-brackets (j), break-blocks=all (F)
:: set options= -CSKBNLwM50m10yejoOcFpPHUxE -vRQ
REM with indent-brackets (G), add-one-line-brackets (J), break-blocks (f)
:: set options= -CSKGNLwM50m10yeJoOcfpPHUxE -vRQ


call  libCompile.bat  %astyle%
echo Formatting jEdit %options%

%astyle%  %options%  "%testdata%\jEdit\*.java"  > test.txt


echo -
pause
