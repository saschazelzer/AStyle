@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove CodeBlocks
if exist "%testdata%\CodeBlocks" (
echo Removing directory CodeBlocks
rmdir  /s  "%testdata%\CodeBlocks"
)

REM uncompress tar.bz to tar
if not exist "%archives%\codeblocks-*.tar" (
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\codeblocks-*.tar.bz2"  -o"%archives%"  -r
if errorlevel 2 pause
)

REM untar
echo -
echo Extracting files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\codeblocks-*.tar"  -o"%testdata%"  *.cpp *.h  -ry > NUL
REM  all files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\codeblocks-*.tar"  -o"%testdata%"  -ry > NUL
if errorlevel 2 pause

REM rename directory
echo -
for /D %%v in ("%testdata%\codeblocks-*") do (
echo Renaming %%v
move  "%%v"  "%testdata%\CodeBlocks" > NUL
)


echo -
pause
