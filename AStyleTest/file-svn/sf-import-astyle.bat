@echo off
REM create a repository and import the astyle source
REM global-ignores in config should list unwanted commits

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=https://astyle.svn.sourceforge.net/svnroot/astyle
set svndir=%repos%/trunk


echo -
echo ---------------------------
echo creating trunk directory
echo ---------------------------
svn  mkdir  "%repos%/trunk"  -m "Create trunk directory."

echo -
echo ---------------------------
echo creating branches directory
echo ---------------------------
svn  mkdir  "%repos%/branches"  -m "Create branches directory."

echo -
echo ---------------------------
echo creating tags directory
echo ---------------------------
svn  mkdir  "%repos%/tags"  -m "Create releases directory." 


cd  "%USERPROFILE%\Projects"

REM do NOT use backslashes in the file:/// statement
REM the %%v variables must NOT have backslashes
for /d %%v in (AStyle/doc
               AStyle/src)  do (
echo -
echo ---------------------------
echo importing %%v
echo ---------------------------
svn  import  %%v  "%svndir%/%%v"  -m "Release 1.23."  --depth files
if errorlevel 1 pause
)

REM do NOT use backslashes in the file:/// statement
REM the %%v variables must NOT have backslashes
for /d %%v in (AStyle/build/gcc
			   AStyle/build/intel
			   AStyle/build/mac
			   AStyle/build/vms
			   AStyle/build/vs2003
			   AStyle/build/vs2005
               AStyle/build/vs2008)  do (
echo -
echo ---------------------------
echo importing %%v
echo ---------------------------
svn  import  %%v  "%svndir%/%%v"  -m "Release 1.23."  --depth files
if errorlevel 1 pause
)


echo -
echo -
echo * * * * * *  end of import  * * * * * *
pause
