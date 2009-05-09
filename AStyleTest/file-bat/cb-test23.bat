@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyle23

set options= -avRQ
:: set options= -CSKBGNLwM50m10yeoOcFpPUxEvRQ
REM without indent-blocks or indent-brackets (B or G)
:: set options= -CSKNLwM50m10yeoOcFpPHUxEvRQ


call  libCompile.bat  %astyle%
echo Formatting CodeBlocks %options%

%astyle%  %options%  "%testdata%\CodeBlocks\src\*.cpp"  "%testdata%\CodeBlocks\src\*.h" > test.txt


echo -
pause
