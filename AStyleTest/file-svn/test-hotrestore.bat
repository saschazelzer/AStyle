@echo off
REM restore the repository using hotcopy
REM do NOT use backslashes in the URL statement
REM do NOT use %USERPROFILE% in the URL because of the backslashes
set reposdir=C:/Users/jp/Projects/TestSvn/Repository
set backdir=%USERPROFILE%\Projects\TestSvn\Hotcopy


if exist  "%reposdir%" (
echo -
echo removing repository
rd  /s  /q  "%reposdir%"
)

REM NOTE: do NOT use 'svn create' when using hotcopy

echo -
echo --------------------------
echo hot restoring %reposdir%
echo --------------------------
svnadmin  hotcopy  %backdir%  %reposdir%


echo -
echo -
echo * * * * *  end of restore  * * * * *
pause
