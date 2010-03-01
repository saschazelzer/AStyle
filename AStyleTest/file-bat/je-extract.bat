@echo off
REM uncompress jEdit from TestArcives to TestData

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove jEdit
if exist "%testdata%\jEdit" (
echo Removing directory jEdit
rmdir  /s  "%testdata%\jEdit"
)

REM NOTE: must use jedit 4.3 or higher with jdk 6 Update 11
REM uncompress tar.bz to tar
if not exist "%archives%\jedit4.3*.tar" (
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\jedit4.3*.tar.bz2"  -o"%archives%"  -r
if errorlevel 2 pause
)

REM untar
echo -
echo Extracting jEdit
REM  java files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\jedit4.3*.tar"  -o"%testdata%"  *.java  -ry > NUL
REM  all files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\jedit4.3*.tar"  -o"%testdata%"  -ry > NUL
if errorlevel 2 pause


echo -
pause
