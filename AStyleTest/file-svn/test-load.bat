@echo off
REM dump the repository
REM do NOT use backslashes in the URL statement
REM do NOT use %USERPROFILE% in the URL because of the backslashes
set reposdir=C:/Users/jp/Projects/TestSvn/Repository
set backdir=%USERPROFILE%\Projects\TestSvn\Dump


if exist  "%reposdir%" (
echo -
echo removing repository
rd  /s  /q  "%reposdir%"
)

REM NOTE: use 'svn create' when using load

echo -
echo creating repository
md  "%reposdir%"
svnadmin  create  "%reposdir%"

echo -
echo --------------------------
echo loading %reposdir%
echo --------------------------
svnadmin  load  %reposdir%  <  %backdir%\dump


echo -
echo -
echo * * * * *  end of load  * * * * *
pause
