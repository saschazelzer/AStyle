@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyled

:: set options= -HvRQ
:: set options= -bCSKBGNLwM50m10yeoOcFpPHUxEvRQ
REM without indent-blocks or indent-brackets (B or G)
set options= -gCSKNLwM50m10yeoOcFpPHUxEvRQ


set excludes= --exclude=TestPrograms

call  libCompile.bat  %astyle%
echo Formatting SharpDevelop %options%

%astyle%  %options%  %excludes%  "%testdata%\SharpDevelop\src\*.cs" > test.txt


echo -
pause
