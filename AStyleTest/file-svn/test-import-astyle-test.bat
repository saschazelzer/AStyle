@echo off
REM create a repository and import the AStyleTest source
REM global-ignores in config should list unwanted commits

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=file:///C:/Users/jp/Projects/TestSvn/Repository
set svndir=%repos%/trunk


if not exist  "%repos:~8%" (
echo -
echo TestSvn/Repository must exist
pause
exit 100
)

cd  "%USERPROFILE%\Projects"

REM do NOT use backslashes in the file:/// statement
REM the %%v variables must NOT have backslashes
for /d %%v in (AStyleTest/file-bat
			   AStyleTest/file-sh
			   AStyleTest/file-svn
			   AStyleTest/src)  do (
echo -
echo ---------------------------
echo importing %%v
echo ---------------------------
svn  import  %%v  "%svndir%/%%v"  -m "Initial import."  --depth files
if errorlevel 1 pause
)

REM do NOT use backslashes in the file:/// statement
REM the %%v variables must NOT have backslashes
for /d %%v in (AStyleTest/build/cb-gcc
			   AStyleTest/build/cb-intel
			   AStyleTest/build/cb-mingw
               AStyleTest/build/vs2008)  do (
echo -
echo ---------------------------
echo importing %%v
echo ---------------------------
svn  import  %%v  "%svndir%/%%v"  -m "Initial import."  --depth files
if errorlevel 1 pause
)


echo -
echo -
echo * * * * * *  end of test import  * * * * * *
pause
