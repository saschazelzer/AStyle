@echo off

set progdir=C:\Program Files\SlikSvn\bin
REM get today's date and convert to yy.mm.dd
set tdate=%DATE:~4%
set today=%tdate:~8,2%.%tdate:~0,2%.%tdate:~3,2%

set codeblocks=CodeBlocks_%today%

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                  checkout codeblocks                  *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

echo %codeblocks%

REM checkout codeblocks to TEMP
:: "%progdir%\svn"  checkout  "svn://svn.berlios.de/codeblocks/trunk"  "%TEMP%\%codeblocks%"

REM "%progdir%\svn"  checkout  --revision {2007-07-05} "svn://svn.berlios.de/codeblocks/trunk"  "%TEMP%\%codeblocks%"
"%progdir%\svn"  checkout  --revision 5859 "svn://svn.berlios.de/codeblocks/trunk"  "%TEMP%\%codeblocks%"

if not exist "%TEMP%\%codeblocks%" (
goto :END
)

REM verify remove
REM obtain a Y/N reply
REM errorlevel 2 is N
echo -
choice /m "Do you want to remove the .svn directories"
if errorlevel 2 goto :END

for /r  "%TEMP%\%codeblocks%"  %%v  in (.svn) do (
if exist "%%v"  rd  /s /q "%%v"
)

:END
echo -
pause
