@echo off
REM create the development web documentation branch from the current trunk
REM the old files will be removed if necessary

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=https://astyle.svn.sourceforge.net/svnroot/astyle
set svndir=%repos%/branches

REM do NOT use backslashes in the file:/// statement

echo -
echo --------------------------
echo deleting old AStyleWeb/doc-dev
echo --------------------------
svn delete 	"%svndir%/AStyleWeb/doc-dev"  -m "Delete directory." 
if errorlevel 1 (
REM must create AStyleWeb if it doesn't exist
echo -
echo --------------------------
echo creating AStyleWeb
echo --------------------------
svn  mkdir  "%svndir%/AStyleWeb"   -m "Create directory."
)

REM copy files and rename the directory
echo -
echo --------------------------
echo copying AStyleWeb/doc-dev
echo --------------------------
svn  copy  "%repos%/trunk/AStyleDev/doc"  "%svndir%/AStyleWeb/doc-dev"  -m "Copy AStyleDev files."


echo -
echo -
echo * * * *  end of create dev branch  * * * *
pause
