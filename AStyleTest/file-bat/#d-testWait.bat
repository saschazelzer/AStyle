@echo off

set testdata=..\..\TestData
set astyledir=..\..\AStyle

:: set progdir=%astyledir%\build\cb-borland\bin
:: set progdir=%astyledir%\build\cb-dmars\bin
:: set progdir=%astyledir%\build\cb-mingw\bin
:: set progdir=%astyledir%\build\vs2003\bin
:: set progdir=%astyledir%\build\vs2005\bin
set progdir=%astyledir%\build\vs2008\bin


set excludes= --exclude=TestPrograms

%progdir%\AStyle  -vRa  %excludes%  "%testdata%\SharpDevelop\src\AddIns\*.cs" > test.txt
if errorlevel 1 pause
%progdir%\AStyle  -vRb  %excludes%  "%testdata%\SharpDevelop\src\AddIns\*.cs" > test.txt
if errorlevel 1 pause
%progdir%\AStyle  -vRl  %excludes%  "%testdata%\SharpDevelop\src\AddIns\*.cs" > test.txt
if errorlevel 1 pause
%progdir%\AStyle  -vRa  %excludes%  "%testdata%\SharpDevelop\src\AddIns\*.cs" > test.txt
if errorlevel 1 pause
%progdir%\AStyle  -vRb  %excludes%  "%testdata%\SharpDevelop\src\AddIns\*.cs" > test.txt
if errorlevel 1 pause
%progdir%\AStyle  -vRl  %excludes%  "%testdata%\SharpDevelop\src\AddIns\*.cs" > test.txt


:: %progdir%\AStyle  -CSKBGNLwM50m10yexpPUoOCEvR  %excludes%  "%testdata%\SharpDevelop\src\*.cs" > test.txt

REM removed confilicts with release 1.22, removed oO
:: %progdir%\AStyle  -CSKNLwM50m10yepPUEvR  %excludes%  "%testdata%\SharpDevelop\src\*.cs" > test.txt


echo -
pause
