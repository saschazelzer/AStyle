@echo off
REM Read the AStyle recursive output file and open the diffs in WinMerge

REM CHANGE THE FOLLOWING VARIABLES
REM infile is the AStyle recursive ouput file
REM winmerge is the path to the WinMerge executable, includig the executable filename
REM tempfile is the workfile for the directory and file names
set infile=test.txt
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
set indir=%USERPROFILE%

REM read infile to find the "directory" and set the %indir% variable
REM DIRECTORY is called outside the FOR loop so the variables will be resolved
FINDSTR "^directory"  "%infile%" > %tempfile%
for /f "tokens=2*" %%v in (%tempfile%)  do  call :DIRECTORY %%v %%w %%x

REM read infile to find the totals (with a comma) ine and set the total variables
FINDSTR "formatted, unchanged,"  "%infile%" > %tempfile%
for /f "tokens=1,3" %%v in (%tempfile%)  do  (
call  set /A  total = %%v
call  set /A  totalfiles = %%v + %%w
)

REM validate directory name
if not exist "%indir%"  (
echo Input directory does not exist!
echo %indir%
pause
exit
)

REM read infile and output all lines beginning with "formatted"
FINDSTR "^formatted"  "%infile%" > %tempfile%

REM display information
echo -
echo N,M to skip
echo Z to end
echo -
echo %indir%
echo -
echo %total% diffs in %totalfiles% files
echo -
echo -

REM read tempfile and open the files in WinMerge
REM PROCESS is called outside the FOR loop so the variables will be resolved
REM arguments must be in quotes to allow spaces in names
for /f "tokens=2*" %%v in (%tempfile%)  do  call :PROCESS "%%v"
goto :END


:DIRECTORY
REM DIRECTORY -  set the %indir% variable
REM parameters are the input directory from AStyle
REM must remove the filename wildcard (*) and trailing / from the indir
set indir=%1 %2 %3
for /f "delims=*" %%v in ('echo %indir%')  do  set indir=%%v
set indir=%indir:~0,-1%
goto :EOF


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
choice /n /c:nmzxcvbasdfghjklqwertyuiop
if errorlevel 4 (
"%winmerge%"  "%indir%\%inpath%"  "%indir%\%inpath%.orig"
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
