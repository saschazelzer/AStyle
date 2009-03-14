@echo off
REM create releases files from the current trunk
REM change "set rel=" to the current release

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=C:/Users/jp/Projects/TestSvn/Repository
set svndir=%repos%/tags
set rel=1.23


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo creating tags %rel% directory
echo --------------------------
svn  mkdir  "file:///%svndir%/%rel%"   -m "Create directory."
if errorlevel 1 (
echo -
echo file not copied
) else (
echo -
echo --------------------------
echo copying trunk to %rel% directory
echo --------------------------
svn  copy  "file:///%repos%/trunk/AStyle"  "file:///%svndir%/%rel%/AStyle"  -m "Create release %rel%"
)

echo -
echo -
echo * * * * *  end of create release  * * * * *
pause
