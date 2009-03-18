@echo off
REM dump the repository
REM do NOT use backslashes in the URL statement
REM do NOT use %USERPROFILE% in the URL because of the backslashes
set repos=file:///C:/Users/jp/Projects/TestSvn/Repository
set backdir=%USERPROFILE%\Projects\TestSvn\Dump
set reposdir=%repos:~8%

if not exist  %backdir%  (
md  "%backdir%"
)

echo -
echo --------------------------
echo dumping %reposdir%
echo --------------------------
svnadmin  dump %reposdir%  >  %backdir%\dump


echo -
echo -
echo * * * * *  end of dump  * * * * *
pause
