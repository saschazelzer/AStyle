@echo off
color 0B
REM This file should be called by the python program system-file.py
REM %1, project (CodeBlocks, jEdit, etc.)
REM %2, current bracket type
REM %3, previous bracket type
REM %4 - %5, filepathe to process
REM %6+ - options

:: set astyle=..\..\AStyle\build\vs2008\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\debug\AStyled
set tempfile=%TEMP%\astyle.tmp
set infile=test.txt

set project=%1
set bracketType=%2
set prevBracket=%3
set testdata1=..\..\TestData\%4
set testdata2=..\..\TestData\%5
set options=%6 %7 %8 %9
if not "%bracketType%" == "_"  (
set options= -%bracketType% %options%
)

call  libCompile.bat  %astyle%
echo Formatting %project% %options%

%astyle%  %options%  "%testdata1%"  "%testdata2%"  > test.txt

REM validate input file
if not exist "%infile%"  (
echo Input file does not exist!
echo %infile%
pause
exit
)

REM read infile to find the totals (with a comma) line and set the total variables
set command=FINDSTR "formatted, unchanged,"  "%infile%"
for /f "tokens=1,3,5,6,7" %%v in ('%command%')  do  (
call  set /A  formatted = %%v
call  set /A  totalfiles = %%v + %%w
set mtime=%%x
set mword=%%y
set stime=%%z
)

REM display stats
if "%mword%" == "min" (
echo %formatted% formatted, %totalfiles% files, %mtime% min %stime% sec
) else (
echo %formatted% formatted, %totalfiles% files, %mtime% seconds
)

REM exit if okay
if %formatted% equ 0  exit
if %prevBracket% equ 0  exit
if not "%bracketType%" == "_"  (
if not "%bracketType%" == "%prevBracket%"  exit
)

REM unwanted formatting
@color 0C
REM CHOICE has an option to wait specified number of seconds 
REM             before defaulting to a specified key
choice /c yn /m "Do you want to run diff-print.bat "
if errorlevel 2 exit
@color 07
call diff-print.bat
if errorlevel 1 pause
@color 0B

