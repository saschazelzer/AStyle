@echo off
REM create a repository and import the AStyleDev source
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
for /d %%v in (AStyleDev/doc
               AStyleDev/file-bat
			   AStyleDev/file-sh
			   AStyleDev/scripts
			   AStyleDev/src-c
			   AStyleDev/src-cx
			   AStyleDev/src-cxx
			   AStyleDev/src-j
			   AStyleDev/src-jx
			   AStyleDev/src-s
			   AStyleDev/src-sx
			   AStyleDev/test-c
			   AStyleDev/test-j
               AStyleDev/test-s)  do (
echo -
echo ---------------------------
echo importing %%v
echo ---------------------------
svn  import  %%v  "%svndir%/%%v"  -m "Initial import."  --depth files
if errorlevel 1 pause
)

REM do NOT use backslashes in the file:/// statement
REM the %%v variables must NOT have backslashes
for /d %%v in (AStyleDev/build/cb-borland
			   AStyleDev/build/cb-dmars
			   AStyleDev/build/cb-gcc
			   AStyleDev/build/cb-intel
			   AStyleDev/build/cb-mingw
			   AStyleDev/build/vs2005
               AStyleDev/build/vs2008
			   AStyleDev/build/vs2008/AllExamples
			   AStyleDev/build/vs2008/Example2Dll
			   AStyleDev/build/vs2008/Example2Lib
			   AStyleDev/build/vs2008/Example2Obj
			   AStyleDev/build/vs2008/ExampleDll
			   AStyleDev/build/vs2008/ExampleLib
			   AStyleDev/build/vs2008/ExampleObj
			   AStyleDev/build/vs2008/Glob
			   AStyleDev/build/vs2008/PrintDir
			   AStyleDev/build/vs2008/PrintDirTest)  do (
echo -
echo ---------------------------
echo importing %%v
echo ---------------------------
svn  import  %%v  "%svndir%/%%v"  -m "Initial import."  --depth files
if errorlevel 1 pause
)


echo -
echo -
echo * * * * * *  end of dev import  * * * * * *
pause
