@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyled

set options= -pvRQ
:: set options= -bCSKBGNLwM50m10yeoOcFpPHUxEvRQ
REM without indent-blocks or indent-brackets (B or G)
:: set options= -bCSKNLwM50m10yeoOcFpPHUxEvRQ


call  libCompile.bat  %astyle%
echo Formatting jEdit %options%

%astyle%  %options%  "%testdata%\jEdit\*.java"  > test.txt


echo -
pause
