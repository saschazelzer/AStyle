@echo off

set progdir=C:\Program Files\SlikSvn\bin
REM get today's date and convert to yy.mm.dd
set tdate=%DATE:~4%
set today=%tdate:~8,2%.%tdate:~0,2%.%tdate:~3,2%

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                  checkout codeblocks                  *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

echo CodeBlocks_%today%

REM checkout codeblocks to TEMP
:: "%progdir%\svn"  checkout  "svn://svn.berlios.de/codeblocks/trunk"  "%TEMP%\CodeBlocks_%today%"

REM "%progdir%\svn"  checkout  --revision {2007-07-05} "svn://svn.berlios.de/codeblocks/trunk"  "%TEMP%\CodeBlocks"
"%progdir%\svn"  checkout  --revision 5859 "svn://svn.berlios.de/codeblocks/trunk"  "%TEMP%\CodeBlocks"

echo -
pause
