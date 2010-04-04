@echo off

set progdir=C:\Program Files\SlikSvn\bin
REM get today's date and convert to yy.mm.dd
set tdate=%DATE:~4%
set today=%tdate:~8,2%.%tdate:~0,2%.%tdate:~3,2%

set gtest=GTest_%today%

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                    checkout gtest                     *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

echo %gtest%

REM checkout read-only working copy to TEMP
"%progdir%\svn"  checkout  "http://googletest.googlecode.com/svn/trunk/"  "%TEMP%\%gtest%"

:: "%progdir%\svn"  checkout  --revision {2007-07-05} "http://googletest.googlecode.com/svn/trunk/"  "%TEMP%\%gtest%"
:: "%progdir%\svn"  checkout  --revision 5859 "http://googletest.googlecode.com/svn/trunk/"  "%TEMP%\%gtest%"

if not exist "%TEMP%\%gtest%" (
goto :END
)

REM verify remove
REM obtain a Y/N reply
REM errorlevel 2 is N
echo -
choice /m "Do you want to remove the .svn directories"
if errorlevel 2 goto :END

for /r  "%TEMP%\%gtest%"  %%v  in (.svn) do (
if exist "%%v"  rd  /s /q "%%v"
)

:END
echo -
pause
