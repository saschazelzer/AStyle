@echo off
REM hotcopy the repository
REM do NOT use backslashes in the URL statement
REM do NOT use %USERPROFILE% in the URL because of the backslashes
set reposdir=C:/Users/jp/Projects/TestSvn/Repository
set backdir=%USERPROFILE%\Projects\TestSvn\Hotcopy


if exist  %backdir% (
echo removing %backdir%
rd  /s  /q  "%backdir%"
)

echo -
echo --------------------------
echo verifying %reposdir%
echo --------------------------
svnadmin  verify  %reposdir%
if errorlevel 1 (
pause
exit 100
)

REM NOTE: do NOT use 'svn create' when using hotcopy

echo -
echo --------------------------
echo hotcopying %reposdir%
echo --------------------------
svnadmin  hotcopy  %reposdir%  %backdir%


echo -
echo -
echo * * * * *  end of hotcopy  * * * * *
pause
