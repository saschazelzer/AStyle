@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove SharpDevelop
if exist "%testdata%\SharpDevelop" (
echo Removing directory SharpDevelop
rmdir  /s  "%testdata%\SharpDevelop"
)

REM unzip
echo -
if exist "%archives%\SharpDevelop_*.zip" (
echo Extracting SharpDevelop
REM  C# files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\SharpDevelop_*.zip"  -o"%testdata%\SharpDevelop"  *.cs  -ry > NUL
REM  all files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\SharpDevelop_*.zip"  -o"%testdata%\SharpDevelop"  -ry > NUL
if errorlevel 2 pause
) else (
echo no file to extract "%archives%\SharpDevelop_*.zip"
)


echo -
pause
