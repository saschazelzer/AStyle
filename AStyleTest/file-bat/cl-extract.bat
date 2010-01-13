@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove codelite
if exist "%testdata%\codelite" (
echo Removing directory codelite
rmdir  /s  "%testdata%\codelite"
)

REM uncompress tar.bz to tar
if not exist "%archives%\codelite-*.tar" (
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\codelite-*.tar.gz"  -o"%archives%"  -r
if errorlevel 2 pause
)

REM untar
echo -
echo Extracting files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\codelite-*.tar"  -o"%testdata%"  *.cpp *.h *.cxx  -ry > NUL
REM  all files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\codelite-*.tar"  -o"%testdata%"  -ry > NUL
if errorlevel 2 pause

REM rename directory
echo -
for /D %%v in ("%testdata%\codelite-*") do (
echo Renaming %%v
move  "%%v"  "%testdata%\codelite" > NUL
)


echo -
pause
