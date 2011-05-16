@echo off

set testdata=..\..\TestData
set archives=..\..\TestArchives

echo -

REM remove eclipse
if exist "%testdata%\eclipse" (
echo Removing directory eclipse
rmdir  /s  "%testdata%\eclipse"
)

REM extract src.zip files
if not exist "%archives%\eclipse" (
echo -
echo Extracting src.zip files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\eclipse-*.zip"  -o"%archives%"  src.zip  -ry  >  NUL
if errorlevel 2 pause
)

REM extract .java files
REM  org.eclipse.cvs.*       -   500 files
REM  org.eclipse.jdt.*       -  4300 files
REM  org.eclipse.pde.*       -  1500 files
REM  org.eclipse.platform.*  -  5000 files
REM  org.eclipse.rcp.*       -  3300 files
REM  all files  .*       =   - 15500 files, 30 min with debug config
echo -
echo Extracting files
REM all files
"%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\eclipse\plugins\*"  -o"%testdata%\eclipse"  *.java  -ry  >  NUL
REM selected files
:: "%PROGRAMFILES%\7-Zip\7z"  x  "%archives%\eclipse\plugins\org.eclipse.pde.*"  -o"%testdata%\eclipse"  *.java  -ry  >  NUL
if errorlevel 2 pause
)

echo -
pause
