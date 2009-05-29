@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove Horstmann1
if exist "%testdata%\Horstmann1" (
echo Removing directory Horstmann1
rmdir  /s  "%testdata%\Horstmann1"
)

REM unzip
echo -
if exist "%archives%\mcppcode.zip" (
echo Extracting files
REM  cpp files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\mcppcode.zip"  -o"%testdata%\Horstmann1"  *.cpp  -ry > NUL
REM  all files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\mcppcode.zip"  -o"%testdata%\Horstmann1"  -ry > NUL
if errorlevel 2 pause
) else (
echo no file to extract "%archives%\mcppcode.zip"
)


echo -
pause
