@echo off
REM Read the xx-diff.bat output file and open the diffs in WinMerge

REM CHANGE THE FOLLOWING VARIABLES
REM indir contains the formatted files to be compared
REM indirOLD contains the files formatted with the old version
REM infile is the xx-diff formatted ouput file
REM winmerge is the path to the WinMerge executable, includig the executable filename
REM tempfile is the workfile for the directory and file names
set indir=%USERPROFILE%
set indirOLD=%USERPROFILE%

set infile=test-diff.txt
set winmerge=%PROGRAMFILES%\WinMerge\WinMergeU
set tempfile=%TEMP%\astyle.tmp


REM validate input file
if not exist "%infile%"  (
echo Input file does not exist!
echo %infile%
pause
exit
)

REM initialize variables
set total=0
set count=0
set processed=0
set totalfiles=0
set endprocess=no

REM read infile to find the "directory" and set the %indir% variables
REM DIRECTORY is called outside the FOR loop so the variables will be resolved
FINDSTR "^directory1 "  "%infile%" > %tempfile%
for /f "tokens=2" %%v in (%tempfile%)  do  set indir=%%v
FINDSTR "^directory2 "  "%infile%" > %tempfile%
for /f "tokens=2" %%v in (%tempfile%)  do  set indirOLD=%%v

REM read infile to find the " files listed" total line and set the total variables
FINDSTR  ".files.listed"  "%infile%" > %tempfile%
for /f "tokens=1,3" %%v in (%tempfile%)  do  (
call  set /A  total = %%v
call  set /A  totalfiles = %%w
)

REM validate input directories
if not exist "%indir%"  (
echo Input directory does not exist!
echo "%indir%"
pause
exit
)
if not exist "%indirOLD%"  (
echo Input directory does not exist!
echo %indirOLD%
pause
exit
)

REM read infile and output all lines beginning with "diff  "
FINDSTR "^diff  "  "%infile%" > %tempfile%

REM display information
echo -
echo N,M to skip
echo Z to end
echo -
echo %indir:~30%
echo %indirOLD:~30%
echo -
echo %total% diffs in %totalfiles% files
echo -
echo -

REM read tempfile and open the files in WinMerge
REM PROCESS is called outside the FOR loop so the variables will be resolved
REM arguments must be in quotes to allow spaces in names
for /f "tokens=2*" %%v in (%tempfile%)  do  call :PROCESS "%%v"
goto :END


:PROCESS
REM PROCESS - process the file
REM %1 is the input file path
set inpath=%~1
call  set /A  count += 1
if %count% GTR %total%  goto :EOF
REM must loop thru remaining files to end
if "%endprocess%" == "yes" goto :EOF
REM get response and process
echo %count% of %total%  %inpath%
choice /n /c:nmzxcvb
if errorlevel 4 (
"%winmerge%"  "%indir%\%inpath%"  "%indirOLD%\%inpath%"
call  set /A  processed += 1
) else (
if errorlevel 3 (
set endprocess=yes
)
REM errorlevel 1 (N,M) will skip processing
)
goto :EOF


:END
REM display totals
echo -
echo -
echo %processed% of %total% diffs processed
echo -
pause

:EOF
