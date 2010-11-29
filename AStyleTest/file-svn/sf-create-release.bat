@echo off
REM create releases files from the current trunk
REM change "set rel=" to the current release

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% because of the backslashes
set repos=https://astyle.svn.sourceforge.net/svnroot/astyle
set svndir=%repos%/tags
set rel=2.01


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo creating tags %rel% directory
echo --------------------------
svn  mkdir  "%svndir%/%rel%"   -m "Create directory."
if errorlevel 1 (
echo -
echo file not copied
) else (
echo -
echo --------------------------
echo copying trunk to %rel% directory
echo --------------------------
svn  copy  "%repos%/trunk/AStyle"  "%svndir%/%rel%/AStyle"  -m "Create AStyle release %rel%"
svn  copy  "%repos%/trunk/AStyleTest"  "%svndir%/%rel%/AStyleTest"  -m "Create AStyleTest release %rel%"
)

echo -
echo -
echo * * * * *  end of create release  * * * * *
pause
