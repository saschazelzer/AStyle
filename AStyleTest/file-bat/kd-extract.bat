@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove kdevelop
if exist "%testdata%\kdevelop" (
echo Removing directory kdevelop
rmdir  /s  "%testdata%\kdevelop"
)

REM uncompress tar.bz to tar
if not exist "%archives%\kdevelop-*.tar" (
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\kdevelop-*.tar.bz2"  -o"%archives%"  -r
if errorlevel 2 pause
)

REM untar
echo -
echo Extracting files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\kdevelop-*.tar"  -o"%testdata%"  *.cpp *.h  -ry > NUL
REM  all files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\kdevelop-*.tar"  -o"%testdata%"  -ry > NUL
if errorlevel 2 pause

REM rename directory
echo -
for /D %%v in ("%testdata%\kdevelop-*") do (
echo Renaming %%v
move  "%%v"  "%testdata%\kdevelop" > NUL
)


echo -
pause
