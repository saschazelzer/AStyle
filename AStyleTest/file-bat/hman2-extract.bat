@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove Horstmann2
if exist "%testdata%\Horstmann2" (
echo Removing directory Horstmann2
rmdir  /s  "%testdata%\Horstmann2"
)

REM unzip
echo -
if exist "%archives%\PracticalOO.zip" (
echo Extracting files
REM  all files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\PracticalOO.zip"  -o"%testdata%\Horstmann2"  -ry > NUL
if errorlevel 2 pause
) else (
echo no file to extract "%archives%\PracticalOO.zip"
)


echo -
pause
