@REM compare SharpDevelopOLD to SharpDevelop and display files that are different
@echo off

set testdata=%USERPROFILE%\Projects\TestData

set indir=%testdata%\SharpDevelop\src
set indirOLD=%testdata%\SharpDevelopOLD\src

REM optional statement to run Artistic Style
set progdir=..\AStyle\_VC-2008\bin
::%progdir%\AStyle.exe   -R  "%testdata%\SharpDevelop\src\*.cs"
::if errorlevel 1 pause

REM name of the output file
set errfile="test-diff.txt"

if exist %errfile% del %errfile%

if not exist "%indirOLD%" (
echo No file "SharpDevelopOLD"
pause
exit 1
)

REM display the files and write to output
echo Compare %indir:~30% to %indirOLD:~30% 
echo directory1  %indir% >> %errfile%
echo directory2  %indirOLD% >> %errfile%
echo ---------------------------------------------- >> %errfile%

REM set inlength to the length of indir
call :SETLENGTH  "%indir%"  inlength
set count=0
set diffs=0
REM loop thru the directory and find the .cs files
REM COMPARE is called outside the FOR loop so the variables will be resolved
REM arguments must be in quotes to allow spaces in names
for /R  "%indir%"  %%V   in (*.cs)  do (
    call  :COMPARE  "%%~dpV"  "%%~nxV"
)
REM write totals to errfile
echo ---------------------------------------------- >> %errfile%
echo %diffs% of %count% files listed >> %errfile%
REM display ending message
echo -
echo %count% files  %diffs% diffs
echo -
pause
goto :EOF


REM COMPARE - compare files from two primary directories
REM arguments are in quotes to handle spaces in names
REM %1 is the input file path
REM %2 is the input file name and extension
:COMPARE
REM remove quotes and trailing \ from inpath
set inpath=%~1
set inpath=%inpath:~0,-1%
:: echo %inpath%
REM remove quotes from name and extension
set nameext=%~2
REM remove indir and leading \ from the input file path giving the sub path
call set outsub=%%inpath:~%inlength%%%
set outsub=%outsub:~1%
:: echo %outsub%
REM prepend sub path to the input path
set outpath=%indir%\%outsub%
set outpathOLD=%indirOLD%\%outsub%
:: echo %outpath%\%nameext%
:: echo %outpathOLD%\%nameext%
REM compare the files
fc  /lb1 /t  "%outpathOLD%\%nameext%"  "%outpath%\%nameext%" > NUL
if errorlevel 1  (
	echo diff  %outsub%\%nameext% >> %errfile%
	call  set /A  diffs+=1
)
REM increment the file count
call  set /A  count+=1
REM echo for every 100 files processed
set /A  tmp=%count%%%100
if %tmp%==0 echo %count% files  %diffs% diffs
goto :EOF


SETLOCAL
REM SETLENGTH - set a variable to the length of a string
REM %1 is the string
REM %2 is the name of the variable to set
:SETLENGTH
REM remove quotes from inpath
set string=%~1
:: echo %string%
REM write string to temp text file
REM put redirection symbol right after variable to avoid a trailing space
set tempfile=%TEMP%\moveit.tmp
REM write the string to tempfile
echo %string%> %tempfile%
REM get the file size in bytes
for %%a in (%tempfile%) do set /a length=%%~za
REM subtract 2 bytes, 1 for CR, 1 for LF
set /a length -=2
REM set the variable to the length
set %2=%length%
:: echo variable "%2" set to %length% characters
REM clean up the temp file
del %tempfile%
ENDLOCAL


:EOF
