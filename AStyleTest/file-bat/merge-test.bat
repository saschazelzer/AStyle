@echo off
REM copy all file types to MergeTest folder for testing

set testdata=..\..\TestData
set astyledir=..\..\AStyle

:: set progdir=%astyledir%\build\cb-borland\bin
:: set progdir=%astyledir%\build\cb-dmars\bin
:: set progdir=%astyledir%\build\cb-mingw\bin
:: set progdir=%astyledir%\build\vs2003\bin
:: set progdir=%astyledir%\build\vs2005\bin
set progdir=%astyledir%\build\vs2008\bin

echo -
echo removing orig and tmp files
del /s  "%testdata%\MergeTest\*.orig"
del /s  "%testdata%\MergeTest\*.tmp"

echo -
echo formatting files

%progdir%\AStyle  -vR  "%testdata%\MergeTest\*"  > test.txt

:: %progdir%\AStyle  -CSKBGNLwM50m10yexpPUoOCEvR  "%testdata%\CodeBlocks\src\*"  > test.txt


echo -
pause
